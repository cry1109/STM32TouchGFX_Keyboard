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
Description :��ȡ������ı�
Input       :textBuff�����������ı�
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
uint8_t Keyboard::getInputLength(void)
{
    return textInputCount;
}

/************************************************************************************
Name        :getInputText()
Description :��ȡ������ı�
Input       :textBuff�����������ı�
OutPut      :��
Return      :��
Note        :��
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
Description :����ESC��ť�ص�����
Input       :callback��ָ�򱻵��õĺ���
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void Keyboard::setescBtCallback(GenericCallback< Keyboard& >& callback)
{
    escBtCallback = &callback;
}

/************************************************************************************
Name        :setcn_entBtrCallback()
Description :�������ļ���ȷ����ť�ص�����
Input       :callback��ָ�򱻵��õĺ���
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void Keyboard::setcn_entBtrCallback(GenericCallback< Keyboard& >& callback)
{
    cn_entBtCallback = &callback;
}

/************************************************************************************
Name        :seten_entBtrCallback()
Description :����Ӣ��Enter��ť�ص�����
Input       :callback��ָ�򱻵��õĺ���
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void Keyboard::seten_entBtrCallback(GenericCallback< Keyboard& >& callback)
{
    en_entBtCallback = &callback;
}

/************************************************************************************
Name        :setnb_entBtrCallback()
Description :��������Enter��ť�ص�����
Input       :callback��ָ�򱻵��õĺ���
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void Keyboard::setnb_entBtrCallback(GenericCallback< Keyboard& >& callback)
{
    nb_entBtCallback = &callback;
}

/************************************************************************************
Name        :escBtClick()
Description :ESC��ť����ص�
Input       :��
OutPut      :��
Return      :��
Note        :��
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
Description :CLR��ť����ص�
Input       :��
OutPut      :��
Return      :��
Note        :��
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
Description :cn_en��ť����ص�
Input       :��
OutPut      :��
Return      :��
Note        :��Ӣ�ļ����л�
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
Description :132��ť����ص�
Input       :��
OutPut      :��
Return      :��
Note        :���ּ��̼����л�
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
* Ӣ�ļ��̵������
-------------------------------------------------------------------------------------------------------*/

/************************************************************************************
*ȷ����ť����ص�
************************************************************************************/
void Keyboard::en_entBtClick()
{
    if (en_entBtCallback->isValid())
    {
        en_entBtCallback->execute(*this);
    }
}

/************************************************************************************
*ɾ����ť����ص�
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
*��Сд�л���ť����ص�
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
*a��ť����ص�
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
*b��ť����ص�
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
*c��ť����ص�
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
*d��ť����ص�
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
*e��ť����ص�
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
*f��ť����ص�
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
*g��ť����ص�
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
*h��ť����ص�
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
*i��ť����ص�
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
*j��ť����ص�
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
*k��ť����ص�
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
*l��ť����ص�
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
*m��ť����ص�
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
*n��ť����ص�
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
*o��ť����ص�
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
*p��ť����ص�
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
*q��ť����ص�
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
*r��ť����ص�
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
*s��ť����ص�
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
*t��ť����ص�
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
*u��ť����ص�
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
*v��ť����ص�
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
*w��ť����ص�
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
*x��ť����ص�
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
*y��ť����ص�
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
*z��ť����ص�
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
*�ո�ť����ص�
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
* ���ּ��̵������
-------------------------------------------------------------------------------------------------------*/

/************************************************************************************
*ɾ����ť����ص�
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
*ȷ����ť����ص�
************************************************************************************/
void Keyboard::fhEntBtClick()
{
    if (nb_entBtCallback->isValid())
    {
        nb_entBtCallback->execute(*this);
    }
}

/************************************************************************************
*����1��ť����ص�
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
*����2��ť����ص�
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
*����3��ť����ص�
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
*����4��ť����ص�
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
*����5��ť����ص�
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
*����6��ť����ص�
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
*����7��ť����ص�
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
*����8��ť����ص�
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
*����9��ť����ص�
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
*����0��ť����ص�
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
*����1��ť����ص�
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
*����2��ť����ص�
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
*����3��ť����ص�
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
*����4��ť����ص�
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
*����5��ť����ص�
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
*����6��ť����ص�
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
*����7��ť����ص�
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
*����8��ť����ص�
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
*����9��ť����ص�
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
*����10��ť����ص�
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
*����11��ť����ص�
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
*����12��ť����ص�
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
* ���ļ��̵������
-------------------------------------------------------------------------------------------------------*/

/************************************************************************************
*ƴ��ѡ������ʾ����
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

    while (count != 0)	//���ҵ����ܹ�ƥ���ƴ��ѡ��
    {
        i = 0;
        py = PinyinTable[g_Pinyin.MatchIndex[count]].Input;

        if (count == 4)
        {
            while (*py != NULL)
            {
                pyText5Buffer[i++] = *py++;	//��ƥ�䵽��ƴ�����µ���ʾ�б���
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
*����ѡ������ʾ����
************************************************************************************/
void Keyboard::cnSelecUpdata(uint8_t page)
{
    if (g_Pinyin.PageTotal != 0)	//����ѡ�ֹ1ҳ
    {
        if (page == (g_Pinyin.PageTotal - 1))	//����ѡ���б����һҳ
        {
            if (g_Pinyin.PageReamin == 0)	//���һҳȫ��ռ��
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
    else  //����ѡ��ֻ��1ҳ
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
*����������뷨ƴ��
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
*���ĺ��˰�ť����ص�
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
*����ɾ����ť����ص�
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
*����ȷ����ť����ص�
************************************************************************************/
void Keyboard::cnBtEntClick()
{
    if (cn_entBtCallback->isValid())
    {
        cn_entBtCallback->execute(*this);
    }
}

/************************************************************************************
*����ѡ��1��ť����ص�
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
*����ѡ��2��ť����ص�
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
*����ѡ��3��ť����ص�
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
*����ѡ��4��ť����ص�
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
*����ѡ��5��ť����ص�
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
*ƴ��ѡ��1��ť����ص�
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
*ƴ��ѡ��2��ť����ص�
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
*ƴ��ѡ��3��ť����ص�
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
*ƴ��ѡ��4��ť����ص�
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
*ƴ��ѡ��5��ť����ص�
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
*����ѡ����ť����ص�
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
*����ѡ���Ұ�ť����ص�
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
*ƴ����ť1����ص�
************************************************************************************/
void Keyboard::cnBtNoneClick()
{

}

/************************************************************************************
*ƴ����ť2����ص�
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
*ƴ����ť3����ص�
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
*ƴ����ť4����ص�
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
*ƴ����ť5����ص�
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
*ƴ����ť6����ص�
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
*ƴ����ť7����ص�
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
*ƴ����ť8����ص�
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
*ƴ����ť9����ص�
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
