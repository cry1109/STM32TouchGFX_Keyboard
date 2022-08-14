#include <gui/containers/Keyboard.hpp>
#include <string.h>
#include <touchgfx/Utils.hpp>

Keyboard::Keyboard() :
    escBtCallback(0),
    cn_entBtCallback(0),
    en_entBtCallback(0),
    nb_entBtCallback(0)
{

}

void Keyboard::initialize()
{
    KeyboardBase::initialize();

    mode = CN_KEYBOARD;
    letter = LOWER_LETTER;

    textInputCount = 0;
    memset(textInputBuffer, 0, TEXTINPUT_SIZE);

    pyClearInput();
    
    cnCont.setVisible(1);
    enCont.setVisible(0);
    nbCont.setVisible(0);

    cn_enBt.setLabelText(TypedText(T_TEXTENBT));

    g_Pinyin.PageIndex = 0;
    g_Pinyin.PageTotal = 0;

    cnText1Buffer[0] = PinyinTable[0].Chinese[0];
    cnText2Buffer[0] = PinyinTable[1].Chinese[0];
    cnText3Buffer[0] = PinyinTable[2].Chinese[0];
    cnText4Buffer[0] = PinyinTable[3].Chinese[0];
    cnText5Buffer[0] = PinyinTable[4].Chinese[0];
}

/************************************************************************************
Name        :getInputText()
Description :获取输入的文本
Input       :textBuff：存放输入的文本
OutPut      :无
Return      :无
Note        :无
************************************************************************************/
uint8_t Keyboard::getInputLength(void)
{
    return textInputCount;
}

/************************************************************************************
Name        :getInputText()
Description :获取输入的文本
Input       :textBuff：存放输入的文本
OutPut      :无
Return      :无
Note        :无
************************************************************************************/
void Keyboard::getInputText(touchgfx::Unicode::UnicodeChar *textBuff,uint16_t textLength)
{
    if (textLength <= TEXTINPUT_SIZE)
    {
        for (uint8_t i = 0; i < textLength; i++)
        {
            textBuff[i] = textInputBuffer[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < TEXTINPUT_SIZE; i++)
        {
            textBuff[i] = textInputBuffer[i];
        }
    }
}

/************************************************************************************
Name        :setescBtCallback()
Description :设置ESC按钮回调函数
Input       :callback：指向被调用的函数
OutPut      :无
Return      :无
Note        :无
************************************************************************************/
void Keyboard::setescBtCallback(GenericCallback< Keyboard& >& callback)
{
    escBtCallback = &callback;
}

/************************************************************************************
Name        :setcn_entBtrCallback()
Description :设置中文键盘确定按钮回调函数
Input       :callback：指向被调用的函数
OutPut      :无
Return      :无
Note        :无
************************************************************************************/
void Keyboard::setcn_entBtrCallback(GenericCallback< Keyboard& >& callback)
{
    cn_entBtCallback = &callback;
}

/************************************************************************************
Name        :seten_entBtrCallback()
Description :设置英文Enter按钮回调函数
Input       :callback：指向被调用的函数
OutPut      :无
Return      :无
Note        :无
************************************************************************************/
void Keyboard::seten_entBtrCallback(GenericCallback< Keyboard& >& callback)
{
    en_entBtCallback = &callback;
}

/************************************************************************************
Name        :setnb_entBtrCallback()
Description :设置数字Enter按钮回调函数
Input       :callback：指向被调用的函数
OutPut      :无
Return      :无
Note        :无
************************************************************************************/
void Keyboard::setnb_entBtrCallback(GenericCallback< Keyboard& >& callback)
{
    nb_entBtCallback = &callback;
}

/************************************************************************************
Name        :escBtClick()
Description :ESC按钮点击回调
Input       :无
OutPut      :无
Return      :无
Note        :无
************************************************************************************/
void Keyboard::escBtClick()
{
    if (escBtCallback->isValid())
    {
        escBtCallback->execute(*this);
    }
}

/************************************************************************************
Name        :clrBtClick()
Description :CLR按钮点击回调
Input       :无
OutPut      :无
Return      :无
Note        :无
************************************************************************************/
void Keyboard::clrBtClick()
{
    textInputCount = 0;
    cnNumberCount = 0;

    memset(textInputBuffer,0, TEXTINPUT_SIZE);
    memset(cnNumber, 0, CN_NUMBER_SIZE);

    for (uint8_t i = 0; i < PYTEXT1_SIZE; i++)
    {
        pyText1Buffer[i] = 0;
        pyText2Buffer[i] = 0;
        pyText3Buffer[i] = 0;
        pyText4Buffer[i] = 0;
        pyText5Buffer[i] = 0;
    }

    pySeclecCont.invalidate();
    textInput.invalidate();
}

/************************************************************************************
Name        :cn_enBtClick()
Description :cn_en按钮点击回调
Input       :无
OutPut      :无
Return      :无
Note        :中英文键盘切换
************************************************************************************/
void Keyboard::cn_enBtClick()
{
    if (nbCont.isVisible())
    {
        nbCont.setVisible(0);
        nbCont.invalidate();
    }

    if (mode == EN_KEYBOARD)
    {
        mode = CN_KEYBOARD;

        cnCont.setVisible(1);
        enCont.setVisible(0);
        
        cnCont.invalidate();
        enCont.invalidate();

        cn_enBt.setLabelText(TypedText(T_TEXTENBT));
        cn_enBt.invalidate();
    }
    else if (mode == CN_KEYBOARD)
    {
        mode = EN_KEYBOARD;

        cnCont.setVisible(0);
        enCont.setVisible(1);

        cnCont.invalidate();
        enCont.invalidate();

        cn_enBt.setLabelText(TypedText(T_TEXTCNBT));
        cn_enBt.invalidate();
    }
}

/************************************************************************************
Name        :numBtClick()
Description :132按钮点击回调
Input       :无
OutPut      :无
Return      :无
Note        :数字键盘键盘切换
************************************************************************************/
void Keyboard::numBtClick()
{
    cnCont.setVisible(0);
    enCont.setVisible(0);
    nbCont.setVisible(1);

    cnCont.invalidate();
    enCont.invalidate();
    nbCont.invalidate();
}

/*-------------------------------------------------------------------------------------------------------
* 英文键盘点击处理
-------------------------------------------------------------------------------------------------------*/

/************************************************************************************
*确定按钮点击回调
************************************************************************************/
void Keyboard::en_entBtClick()
{
    if (en_entBtCallback->isValid())
    {
        en_entBtCallback->execute(*this);
    }
}

/************************************************************************************
*删除按钮点击回调
************************************************************************************/
void Keyboard::en_delBtClick()
{
    if (textInputCount == 0)
    {
        return;
    }

    textInputCount--;
    textInputBuffer[textInputCount] = 0;
    textInput.invalidate();
}

/************************************************************************************
*大小写切换按钮点击回调
************************************************************************************/
void Keyboard::dxBtClick()
{
    if (letter == LOWER_LETTER)
    {
        letter = CAPITAL_LETTER;

        aBt.setLabelText(TypedText(T_TEXT_A_D));
        bBt.setLabelText(TypedText(T_TEXT_B_D));
        cBt.setLabelText(TypedText(T_TEXT_C_D));
        dBt.setLabelText(TypedText(T_TEXT_D_D));
        eBt.setLabelText(TypedText(T_TEXT_E_D));
        fBt.setLabelText(TypedText(T_TEXT_F_D));
        gBt.setLabelText(TypedText(T_TEXT_G_D));
        hBt.setLabelText(TypedText(T_TEXT_H_D));
        iBt.setLabelText(TypedText(T_TEXT_I_D));
        jBt.setLabelText(TypedText(T_TEXT_J_D));
        kBt.setLabelText(TypedText(T_TEXT_K_D));
        lBt.setLabelText(TypedText(T_TEXT_L_D));
        mBt.setLabelText(TypedText(T_TEXT_M_D));
        nBt.setLabelText(TypedText(T_TEXT_N_D));
        oBt.setLabelText(TypedText(T_TEXT_O_D));
        pBt.setLabelText(TypedText(T_TEXT_P_D));
        qBt.setLabelText(TypedText(T_TEXT_Q_D));
        rBt.setLabelText(TypedText(T_TEXT_R_D));
        sBt.setLabelText(TypedText(T_TEXT_S_D));
        tBt.setLabelText(TypedText(T_TEXT_T_D));
        uBt.setLabelText(TypedText(T_TEXT_U_D));
        vBt.setLabelText(TypedText(T_TEXT_V_D));
        wBt.setLabelText(TypedText(T_TEXT_W_D));
        xBt.setLabelText(TypedText(T_TEXT_X_D));
        yBt.setLabelText(TypedText(T_TEXT_Y_D));
        zBt.setLabelText(TypedText(T_TEXT_Z_D));

        dxBt.setLabelText(TypedText(T_TEXT_DX));
    }
    else
    {
        letter = LOWER_LETTER;

        aBt.setLabelText(TypedText(T_TEXT_A_X));
        bBt.setLabelText(TypedText(T_TEXT_B_X));
        cBt.setLabelText(TypedText(T_TEXT_C_X));
        dBt.setLabelText(TypedText(T_TEXT_D_X));
        eBt.setLabelText(TypedText(T_TEXT_E_X));
        fBt.setLabelText(TypedText(T_TEXT_F_X));
        gBt.setLabelText(TypedText(T_TEXT_G_X));
        hBt.setLabelText(TypedText(T_TEXT_H_X));
        iBt.setLabelText(TypedText(T_TEXT_I_X));
        jBt.setLabelText(TypedText(T_TEXT_J_X));
        kBt.setLabelText(TypedText(T_TEXT_K_X));
        lBt.setLabelText(TypedText(T_TEXT_L_X));
        mBt.setLabelText(TypedText(T_TEXT_M_X));
        nBt.setLabelText(TypedText(T_TEXT_N_X));
        oBt.setLabelText(TypedText(T_TEXT_O_X));
        pBt.setLabelText(TypedText(T_TEXT_P_X));
        qBt.setLabelText(TypedText(T_TEXT_Q_X));
        rBt.setLabelText(TypedText(T_TEXT_R_X));
        sBt.setLabelText(TypedText(T_TEXT_S_X));
        tBt.setLabelText(TypedText(T_TEXT_T_X));
        uBt.setLabelText(TypedText(T_TEXT_U_X));
        vBt.setLabelText(TypedText(T_TEXT_V_X));
        wBt.setLabelText(TypedText(T_TEXT_W_X));
        xBt.setLabelText(TypedText(T_TEXT_X_X));
        yBt.setLabelText(TypedText(T_TEXT_Y_X));
        zBt.setLabelText(TypedText(T_TEXT_Z_X));

        dxBt.setLabelText(TypedText(T_TEXT_XD));
    }

    enCont.invalidate();
}

/************************************************************************************
*a按钮点击回调
************************************************************************************/
void Keyboard::aBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'a';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'A';
    }

    textInput.invalidate();
}

/************************************************************************************
*b按钮点击回调
************************************************************************************/
void Keyboard::bBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'b';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'B';
    }

    textInput.invalidate();
}

/************************************************************************************
*c按钮点击回调
************************************************************************************/
void Keyboard::cBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'c';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'C';
    }

    textInput.invalidate();
}

/************************************************************************************
*d按钮点击回调
************************************************************************************/
void Keyboard::dBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'd';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'D';
    }

    textInput.invalidate();
}

/************************************************************************************
*e按钮点击回调
************************************************************************************/
void Keyboard::eBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'e';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'E';
    }

    textInput.invalidate();
}

/************************************************************************************
*f按钮点击回调
************************************************************************************/
void Keyboard::fBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'f';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'F';
    }

    textInput.invalidate();
}

/************************************************************************************
*g按钮点击回调
************************************************************************************/
void Keyboard::gBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'g';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'G';
    }

    textInput.invalidate();
}

/************************************************************************************
*h按钮点击回调
************************************************************************************/
void Keyboard::hBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'h';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'H';
    }

    textInput.invalidate();
}

/************************************************************************************
*i按钮点击回调
************************************************************************************/
void Keyboard::iBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'i';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'I';
    }

    textInput.invalidate();
}

/************************************************************************************
*j按钮点击回调
************************************************************************************/
void Keyboard::jBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'j';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'J';
    }

    textInput.invalidate();
}

/************************************************************************************
*k按钮点击回调
************************************************************************************/
void Keyboard::kBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'k';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'K';
    }

    textInput.invalidate();
}

/************************************************************************************
*l按钮点击回调
************************************************************************************/
void Keyboard::lBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'l';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'L';
    }

    textInput.invalidate();
}

/************************************************************************************
*m按钮点击回调
************************************************************************************/
void Keyboard::mBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'm';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'M';
    }

    textInput.invalidate();
}

/************************************************************************************
*n按钮点击回调
************************************************************************************/
void Keyboard::nBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'n';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'N';
    }

    textInput.invalidate();
}

/************************************************************************************
*o按钮点击回调
************************************************************************************/
void Keyboard::oBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'o';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'O';
    }

    textInput.invalidate();
}

/************************************************************************************
*p按钮点击回调
************************************************************************************/
void Keyboard::pBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'p';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'P';
    }

    textInput.invalidate();
}

/************************************************************************************
*q按钮点击回调
************************************************************************************/
void Keyboard::qBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'q';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'Q';
    }

    textInput.invalidate();
}

/************************************************************************************
*r按钮点击回调
************************************************************************************/
void Keyboard::rBtClick() 
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'r';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'R';
    }

    textInput.invalidate();
}

/************************************************************************************
*s按钮点击回调
************************************************************************************/
void Keyboard::sBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 's';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'S';
    }

    textInput.invalidate();
}

/************************************************************************************
*t按钮点击回调
************************************************************************************/
void Keyboard::tBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 't';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'T';
    }

    textInput.invalidate();
}

/************************************************************************************
*u按钮点击回调
************************************************************************************/
void Keyboard::uBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'u';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'U';
    }

    textInput.invalidate();
}

/************************************************************************************
*v按钮点击回调
************************************************************************************/
void Keyboard::vBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'v';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'V';
    }

    textInput.invalidate();
}

/************************************************************************************
*w按钮点击回调
************************************************************************************/
void Keyboard::wBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'w';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'W';
    }

    textInput.invalidate();
}

/************************************************************************************
*x按钮点击回调
************************************************************************************/
void Keyboard::xBtClick() 
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'x';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'X';
    }

    textInput.invalidate();
}

/************************************************************************************
*y按钮点击回调
************************************************************************************/
void Keyboard::yBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'y';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'Y';
    }

    textInput.invalidate();
}

/************************************************************************************
*z按钮点击回调
************************************************************************************/
void Keyboard::zBtClick() 
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = 'z';
    }
    else
    {
        textInputBuffer[textInputCount++] = 'Z';
    }

    textInput.invalidate();
}

/************************************************************************************
*空格按钮点击回调
************************************************************************************/
void Keyboard::blBtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (letter == LOWER_LETTER)
    {
        textInputBuffer[textInputCount++] = ' ';
    }
    else
    {
        textInputBuffer[textInputCount++] = ' ';
    }

    textInput.invalidate();
}


/*-------------------------------------------------------------------------------------------------------
* 数字键盘点击处理
-------------------------------------------------------------------------------------------------------*/

/************************************************************************************
*删除按钮点击回调
************************************************************************************/
void Keyboard::fhDelBtClick()
{
    if (textInputCount == 0)
    {
        return;
    }

    textInputCount--;
    textInputBuffer[textInputCount] = 0;
    textInput.invalidate();
}

/************************************************************************************
*确定按钮点击回调
************************************************************************************/
void Keyboard::fhEntBtClick()
{
    if (nb_entBtCallback->isValid())
    {
        nb_entBtCallback->execute(*this);
    }
}

/************************************************************************************
*数字1按钮点击回调
************************************************************************************/
void Keyboard::nb1BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '1';
    textInput.invalidate();
}

/************************************************************************************
*数字2按钮点击回调
************************************************************************************/
void Keyboard::nb2BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '2';
    textInput.invalidate();
}

/************************************************************************************
*数字3按钮点击回调
************************************************************************************/
void Keyboard::nb3BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '3';
    textInput.invalidate();
}

/************************************************************************************
*数字4按钮点击回调
************************************************************************************/
void Keyboard::nb4BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '4';
    textInput.invalidate();
}

/************************************************************************************
*数字5按钮点击回调
************************************************************************************/
void Keyboard::nb5BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '5';
    textInput.invalidate();
}

/************************************************************************************
*数字6按钮点击回调
************************************************************************************/
void Keyboard::nb6BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '6';
    textInput.invalidate();
}

/************************************************************************************
*数字7按钮点击回调
************************************************************************************/
void Keyboard::nb7BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '7';
    textInput.invalidate();
}

/************************************************************************************
*数字8按钮点击回调
************************************************************************************/
void Keyboard::nb8BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '8';
    textInput.invalidate();
}

/************************************************************************************
*数字9按钮点击回调
************************************************************************************/
void Keyboard::nb9BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '9';
    textInput.invalidate();
}

/************************************************************************************
*数字0按钮点击回调
************************************************************************************/
void Keyboard::nb0BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '0';
    textInput.invalidate();
}

/************************************************************************************
*符号1按钮点击回调
************************************************************************************/
void Keyboard::fh1BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '.';
    textInput.invalidate();
}

/************************************************************************************
*符号2按钮点击回调
************************************************************************************/
void Keyboard::fh2BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '+';
    textInput.invalidate();
}

/************************************************************************************
*符号3按钮点击回调
************************************************************************************/
void Keyboard::fh3BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '-';
    textInput.invalidate();
}

/************************************************************************************
*符号4按钮点击回调
************************************************************************************/
void Keyboard::fh4BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '*';
    textInput.invalidate();
}

/************************************************************************************
*符号5按钮点击回调
************************************************************************************/
void Keyboard::fh5BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '/';
    textInput.invalidate();
}

/************************************************************************************
*符号6按钮点击回调
************************************************************************************/
void Keyboard::fh6BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '=';
    textInput.invalidate();
}

/************************************************************************************
*符号7按钮点击回调
************************************************************************************/
void Keyboard::fh7BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '#';
    textInput.invalidate();
}

/************************************************************************************
*符号8按钮点击回调
************************************************************************************/
void Keyboard::fh8BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '@';
    textInput.invalidate();
}

/************************************************************************************
*符号9按钮点击回调
************************************************************************************/
void Keyboard::fh9BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '&';
    textInput.invalidate();
}

/************************************************************************************
*符号10按钮点击回调
************************************************************************************/
void Keyboard::fh10BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '%';
    textInput.invalidate();
}

/************************************************************************************
*符号11按钮点击回调
************************************************************************************/
void Keyboard::fh11BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = '(';
    textInput.invalidate();
}

/************************************************************************************
*符号12按钮点击回调
************************************************************************************/
void Keyboard::fh12BtClick()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    textInputBuffer[textInputCount++] = ')';
    textInput.invalidate();
}

/*-------------------------------------------------------------------------------------------------------
* 中文键盘点击处理
-------------------------------------------------------------------------------------------------------*/

/************************************************************************************
*拼音选项栏显示更新
************************************************************************************/
void Keyboard::pySelecUpdata(uint8_t matchCount)
{
    uint8_t i = 0;
    uint8_t count = matchCount;
    char* py = NULL;

    for (i = 0; i < PYTEXT1_SIZE; i++)
    {
        pyText1Buffer[i] = 0;
        pyText2Buffer[i] = 0;
        pyText3Buffer[i] = 0;
        pyText4Buffer[i] = 0;
        pyText5Buffer[i] = 0;
    }

    while (count != 0)	//查找到的能够匹配的拼音选项
    {
        i = 0;
        py = PinyinTable[g_Pinyin.MatchIndex[count]].Input;

        if (count == 4)
        {
            while (*py != NULL)
            {
                pyText5Buffer[i++] = *py++;	//将匹配到的拼音更新到显示列表中
            }
        }
        else if (count == 3)
        {
            while (*py != NULL)
            {
                pyText4Buffer[i++] = *py++;
            }
        }
        else if (count == 2)
        {
            while (*py != NULL)
            {
                pyText3Buffer[i++] = *py++;
            }
        }
        else if (count == 1)
        {
            while (*py != NULL)
            {
                pyText2Buffer[i++] = *py++;
            }
        }

        count--;
    }

    i = 0;
    py = py = PinyinTable[g_Pinyin.MatchIndex[count]].Input;
    while (*py != NULL)
    {
        pyText1Buffer[i++] = *py++;
    }

    pySeclecCont.invalidate();
}

/************************************************************************************
*汉字选项栏显示更新
************************************************************************************/
void Keyboard::cnSelecUpdata(uint8_t page)
{
    if (g_Pinyin.PageTotal != 0)	//汉字选项不止1页
    {
        if (page == (g_Pinyin.PageTotal - 1))	//汉字选项列表最后一页
        {
            if (g_Pinyin.PageReamin == 0)	//最后一页全部占满
            {
                cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 0];
                cnText2Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 1];
                cnText3Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 2];
                cnText4Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 3];
                cnText5Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 4];
            }
            else if (g_Pinyin.PageReamin == 1)
            {
                cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 0];
                cnText2Buffer[0] = 0;
                cnText3Buffer[0] = 0;
                cnText4Buffer[0] = 0;
                cnText5Buffer[0] = 0;
            }
            else if (g_Pinyin.PageReamin == 2)
            {
                cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 0];
                cnText2Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 1];
                cnText3Buffer[0] = 0;
                cnText4Buffer[0] = 0;
                cnText5Buffer[0] = 0;
            }
            else if (g_Pinyin.PageReamin == 3)
            {
                cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 0];
                cnText2Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 1];
                cnText3Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 2];
                cnText4Buffer[0] = 0;
                cnText5Buffer[0] = 0;
            }
            else if (g_Pinyin.PageReamin == 4)
            {
                cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 0];
                cnText2Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 1];
                cnText3Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 2];
                cnText4Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 3];
                cnText5Buffer[0] = 0;
            }
        }
        else
        {
            cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 0];
            cnText2Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 1];
            cnText3Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 2];
            cnText4Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 3];
            cnText5Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page * PINYIN_PAGE_SIZE + 4];
        }
    }
    else  //汉字选项只有1页
    {
        if (g_Pinyin.PageReamin == 1)
        {
            cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 0];
            cnText2Buffer[0] = 0;
            cnText3Buffer[0] = 0;
            cnText4Buffer[0] = 0;
            cnText5Buffer[0] = 0;
        }
        else if (g_Pinyin.PageReamin == 2)
        {
            cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 0];
            cnText2Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 1];
            cnText3Buffer[0] = 0;
            cnText4Buffer[0] = 0;
            cnText5Buffer[0] = 0;
        }
        else if (g_Pinyin.PageReamin == 3)
        {
            cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 0];
            cnText2Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 1];
            cnText3Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 2];
            cnText4Buffer[0] = 0;
            cnText5Buffer[0] = 0;
        }
        else if (g_Pinyin.PageReamin == 4)
        {
            cnText1Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 0];
            cnText2Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 1];
            cnText3Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 2];
            cnText4Buffer[0] = PinyinTable[g_Pinyin.TableIndex].Chinese[page + 3];
            cnText5Buffer[0] = 0;
        }
    }

    cnSelectCont.invalidate();
}

/************************************************************************************
*清空中文输入法拼音
************************************************************************************/
void Keyboard::pyClearInput()
{
    uint8_t i = 0;

    cnNumberCount = 0;

    for (i = 0;i < CN_NUMBER_SIZE;i++)
    {
        cnNumber[i] = 0;
    }

    for (uint8_t i = 0; i < PYTEXT1_SIZE; i++)
    {
        pyText1Buffer[i] = 0;
        pyText2Buffer[i] = 0;
        pyText3Buffer[i] = 0;
        pyText4Buffer[i] = 0;
        pyText5Buffer[i] = 0;
    }

    pySeclecCont.invalidate();
}

/************************************************************************************
*中文后退按钮点击回调
************************************************************************************/
void Keyboard::cnBtBackClick()
{
    if (cnNumberCount > 0)
    {
        cnNumberCount--;
        cnNumber[cnNumberCount] = 0;

        g_Pinyin.TableIndex = PinyinToChinese(cnNumber, cnNumberCount);
        PinyinPageUpdata(g_Pinyin.TableIndex);

        pySelecUpdata(g_Pinyin.MatchCount);
    }
    else
    {
        for (uint8_t i = 0; i < PYTEXT1_SIZE; i++)
        {
            pyText1Buffer[i] = 0;
            pyText2Buffer[i] = 0;
            pyText3Buffer[i] = 0;
            pyText4Buffer[i] = 0;
            pyText5Buffer[i] = 0;
        }

        pySeclecCont.invalidate();
    }
}

/************************************************************************************
*中文删除按钮点击回调
************************************************************************************/
void Keyboard::cnBtDelClick()
{
    if (textInputCount == 0)
    {
        return;
    }

    textInputCount--;
    textInputBuffer[textInputCount] = 0;
    textInput.invalidate();
}

/************************************************************************************
*中文确定按钮点击回调
************************************************************************************/
void Keyboard::cnBtEntClick()
{
    if (cn_entBtCallback->isValid())
    {
        cn_entBtCallback->execute(*this);
    }
}

/************************************************************************************
*汉字选择1按钮点击回调
************************************************************************************/
void Keyboard::cnSelectBt1Click()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (cnText1Buffer[0] != NULL)
    {
        textInputBuffer[textInputCount++] = cnText1Buffer[0];
        textInput.invalidate();

        pyClearInput();
    }
}

/************************************************************************************
*汉字选择2按钮点击回调
************************************************************************************/
void Keyboard::cnSelectBt2Click()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (cnText2Buffer[0] != NULL)
    {
        textInputBuffer[textInputCount++] = cnText2Buffer[0];
        textInput.invalidate();

        pyClearInput();
    }
}

/************************************************************************************
*汉字选择3按钮点击回调
************************************************************************************/
void Keyboard::cnSelectBt3Click()
{
    if (textInputCount >= TEXTINPUT_SIZE)
    {
        return;
    }

    if (cnText3Buffer[0] != NULL)
    {
        textInputBuffer[textInputCount++] = cnText3Buffer[0];
        textInput.invalidate();

        pyClearInput();
    }
}

/************************************************************************************
*汉字选择4按钮点击回调
************************************************************************************/
void Keyboard::cnSelectBt4Click()
{
    if (cnText4Buffer[0] != NULL)
    {
        textInputBuffer[textInputCount++] = cnText4Buffer[0];
        textInput.invalidate();

        pyClearInput();
    }
}

/************************************************************************************
*汉字选择5按钮点击回调
************************************************************************************/
void Keyboard::cnSelectBt5Click()
{
    if (cnText5Buffer[0] != NULL)
    {
        textInputBuffer[textInputCount++] = cnText5Buffer[0];
        textInput.invalidate();

        pyClearInput();
    }
}

/************************************************************************************
*拼音选择1按钮点击回调
************************************************************************************/
void Keyboard::pySelectBt1Click()
{
    if (pyText1Buffer[0] != NULL)
    {
        g_Pinyin.TableIndex = g_Pinyin.MatchIndex[0];
        PinyinPageUpdata(g_Pinyin.TableIndex);

        g_Pinyin.PageIndex = 0;
        cnSelecUpdata(g_Pinyin.PageIndex);
    }
}

/************************************************************************************
*拼音选择2按钮点击回调
************************************************************************************/
void Keyboard::pySelectBt2Click()
{
    if (pyText2Buffer[0] != NULL)
    {
        g_Pinyin.TableIndex = g_Pinyin.MatchIndex[1];
        PinyinPageUpdata(g_Pinyin.TableIndex);

        g_Pinyin.PageIndex = 0;
        cnSelecUpdata(g_Pinyin.PageIndex);
    }
}

/************************************************************************************
*拼音选择3按钮点击回调
************************************************************************************/
void Keyboard::pySelectBt3Click()
{
    if (pyText3Buffer[0] != NULL)
    {
        g_Pinyin.TableIndex = g_Pinyin.MatchIndex[2];
        PinyinPageUpdata(g_Pinyin.TableIndex);

        g_Pinyin.PageIndex = 0;
        cnSelecUpdata(g_Pinyin.PageIndex);
    }
}

/************************************************************************************
*拼音选择4按钮点击回调
************************************************************************************/
void Keyboard::pySelectBt4Click()
{
    if (pyText4Buffer[0] != NULL)
    {
        g_Pinyin.TableIndex = g_Pinyin.MatchIndex[3];
        PinyinPageUpdata(g_Pinyin.TableIndex);

        g_Pinyin.PageIndex = 0;
        cnSelecUpdata(g_Pinyin.PageIndex);
    }
}

/************************************************************************************
*拼音选择5按钮点击回调
************************************************************************************/
void Keyboard::pySelectBt5Click()
{
    if (pyText5Buffer[0] != NULL)
    {
        g_Pinyin.TableIndex = g_Pinyin.MatchIndex[4];
        PinyinPageUpdata(g_Pinyin.TableIndex);

        g_Pinyin.PageIndex = 0;
        cnSelecUpdata(g_Pinyin.PageIndex);
    }
}

/************************************************************************************
*汉字选择左按钮点击回调
************************************************************************************/
void Keyboard::cnBtLiftClick()
{
    if (g_Pinyin.PageIndex > 0)
    {
        g_Pinyin.PageIndex--;
        cnSelecUpdata(g_Pinyin.PageIndex);
    }
}

/************************************************************************************
*汉字选择右按钮点击回调
************************************************************************************/
void Keyboard::cnBtRightClick()
{
    if (g_Pinyin.PageIndex < (g_Pinyin.PageTotal - 1))
    {
        g_Pinyin.PageIndex++;
        cnSelecUpdata(g_Pinyin.PageIndex);
    }
}

/************************************************************************************
*拼音按钮1点击回调
************************************************************************************/
void Keyboard::cnBtNoneClick()
{

}

/************************************************************************************
*拼音按钮2点击回调
************************************************************************************/
void Keyboard::cnBtABCClick()
{
    if (cnNumberCount >= CN_NUMBER_SIZE)
    {
        return;
    }

    cnNumber[cnNumberCount++] = '2';
    g_Pinyin.TableIndex = PinyinToChinese(cnNumber, cnNumberCount);
    PinyinPageUpdata(g_Pinyin.TableIndex);

    g_Pinyin.PageIndex = 0;
    pySelecUpdata(g_Pinyin.MatchCount);
    cnSelecUpdata(g_Pinyin.PageIndex);
}

/************************************************************************************
*拼音按钮3点击回调
************************************************************************************/
void Keyboard::cnBtDEFClick()
{
    if (cnNumberCount >= CN_NUMBER_SIZE)
    {
        return;
    }

    cnNumber[cnNumberCount++] = '3';
    g_Pinyin.TableIndex = PinyinToChinese(cnNumber, cnNumberCount);
    PinyinPageUpdata(g_Pinyin.TableIndex);

    g_Pinyin.PageIndex = 0;
    pySelecUpdata(g_Pinyin.MatchCount);
    cnSelecUpdata(g_Pinyin.PageIndex);
}

/************************************************************************************
*拼音按钮4点击回调
************************************************************************************/
void Keyboard::cnBtGHIClick()
{
    if (cnNumberCount >= CN_NUMBER_SIZE)
    {
        return;
    }

    cnNumber[cnNumberCount++] = '4';
    g_Pinyin.TableIndex = PinyinToChinese(cnNumber, cnNumberCount);
    PinyinPageUpdata(g_Pinyin.TableIndex);

    g_Pinyin.PageIndex = 0;
    pySelecUpdata(g_Pinyin.MatchCount);
    cnSelecUpdata(g_Pinyin.PageIndex);
}

/************************************************************************************
*拼音按钮5点击回调
************************************************************************************/
void Keyboard::cnBtJKLClick()
{
    if (cnNumberCount >= CN_NUMBER_SIZE)
    {
        return;
    }

    cnNumber[cnNumberCount++] = '5';
    g_Pinyin.TableIndex = PinyinToChinese(cnNumber, cnNumberCount);
    PinyinPageUpdata(g_Pinyin.TableIndex);

    g_Pinyin.PageIndex = 0;
    pySelecUpdata(g_Pinyin.MatchCount);
    cnSelecUpdata(g_Pinyin.PageIndex);
}

/************************************************************************************
*拼音按钮6点击回调
************************************************************************************/
void Keyboard::cnBtMNOClick()
{
    if (cnNumberCount >= CN_NUMBER_SIZE)
    {
        return;
    }

    cnNumber[cnNumberCount++] = '6';
    g_Pinyin.TableIndex = PinyinToChinese(cnNumber, cnNumberCount);
    PinyinPageUpdata(g_Pinyin.TableIndex);

    g_Pinyin.PageIndex = 0;
    pySelecUpdata(g_Pinyin.MatchCount);
    cnSelecUpdata(g_Pinyin.PageIndex);
}

/************************************************************************************
*拼音按钮7点击回调
************************************************************************************/
void Keyboard::cnBtPQRSClick()
{
    if (cnNumberCount >= CN_NUMBER_SIZE)
    {
        return;
    }

    cnNumber[cnNumberCount++] = '7';
    g_Pinyin.TableIndex = PinyinToChinese(cnNumber, cnNumberCount);
    PinyinPageUpdata(g_Pinyin.TableIndex);

    g_Pinyin.PageIndex = 0;
    pySelecUpdata(g_Pinyin.MatchCount);
    cnSelecUpdata(g_Pinyin.PageIndex);
}

/************************************************************************************
*拼音按钮8点击回调
************************************************************************************/
void Keyboard::cnBtTUVClick()
{
    if (cnNumberCount >= CN_NUMBER_SIZE)
    {
        return;
    }

    cnNumber[cnNumberCount++] = '8';
    g_Pinyin.TableIndex = PinyinToChinese(cnNumber, cnNumberCount);
    PinyinPageUpdata(g_Pinyin.TableIndex);

    g_Pinyin.PageIndex = 0;
    pySelecUpdata(g_Pinyin.MatchCount);
    cnSelecUpdata(g_Pinyin.PageIndex);
}

/************************************************************************************
*拼音按钮9点击回调
************************************************************************************/
void Keyboard::cnBtWXYZClick()
{
    if (cnNumberCount >= CN_NUMBER_SIZE)
    {
        return;
    }

    cnNumber[cnNumberCount++] = '9';
    g_Pinyin.TableIndex = PinyinToChinese(cnNumber, cnNumberCount);
    PinyinPageUpdata(g_Pinyin.TableIndex);

    g_Pinyin.PageIndex = 0;
    pySelecUpdata(g_Pinyin.MatchCount);
    cnSelecUpdata(g_Pinyin.PageIndex);
}
