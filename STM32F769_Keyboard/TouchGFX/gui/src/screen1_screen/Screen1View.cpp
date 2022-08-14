#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Utils.hpp>

Screen1View::Screen1View():
    textArea1ClickedCallback(this, &Screen1View::textArea1ClickHandler),
    KeyboardEscBtClickedCallBack(this, &Screen1View::KeyboardEscBtClickHandler),
    KeyboardEnEnterBtClickedCallBack(this, &Screen1View::KeyboardEnEnterBtClickHandler),
    KeyboardNbEnterBtClickedCallBack(this, &Screen1View::KeyboardNbEnterBtClickHandler),
    KeyboardCnEnterBtClickedCallBack(this, &Screen1View::KeyboardCnEnterBtClickHandler)
{
    
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    KeyboardExist = 0;
    
    textArea1.setClickAction(textArea1ClickedCallback);

    MyKeyboard.setXY(0, 80);
    MyKeyboard.setescBtCallback(KeyboardEscBtClickedCallBack);
    MyKeyboard.seten_entBtrCallback(KeyboardEnEnterBtClickedCallBack);
    MyKeyboard.setnb_entBtrCallback(KeyboardNbEnterBtClickedCallBack);
    MyKeyboard.setcn_entBtrCallback(KeyboardCnEnterBtClickedCallBack);

    textArea1.invalidate();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

/************************************************************************************
Name        :KeyboardEscBtClickHandler()
Description :����ESC��ť����ص�
Input       :element:����Ԫ��
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void Screen1View::KeyboardEscBtClickHandler(Keyboard& element)
{
    if (KeyboardExist == 1)
    {
        KeyboardExist = 0;
        remove(MyKeyboard);
        this->invalidate();
    }
}

/************************************************************************************
Name        :KeyboardEnEnterBtClickHandler()
Description :Ӣ�ļ���ȷ����ť����ص�
Input       :element:����Ԫ��
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void Screen1View::KeyboardEnEnterBtClickHandler(Keyboard& element)
{
    if (KeyboardExist == 1)
    {
        KeyboardExist = 0;

        MyKeyboard.getInputText(textArea1Buffer, TEXTAREA1_SIZE);

        remove(MyKeyboard);
        this->invalidate();
    }
}

/************************************************************************************
Name        :KeyboardNbEnterBtClickHandler()
Description :���ּ���ȷ����ť����ص�
Input       :element:����Ԫ��
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void Screen1View::KeyboardNbEnterBtClickHandler(Keyboard& element)
{
    if (KeyboardExist == 1)
    {
        KeyboardExist = 0;

        MyKeyboard.getInputText(textArea1Buffer,TEXTAREA1_SIZE);

        remove(MyKeyboard);
        this->invalidate();
    }
}

/************************************************************************************
Name        :KeyboardCnEnterBtClickHandler()
Description :���ļ���ȷ����ť����ص�
Input       :element:����Ԫ��
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void Screen1View::KeyboardCnEnterBtClickHandler(Keyboard& element)
{
    if (KeyboardExist == 1)
    {
        KeyboardExist = 0;

        MyKeyboard.getInputText(textArea1Buffer, TEXTAREA1_SIZE);

        remove(MyKeyboard);
        this->invalidate();
    }
}


/************************************************************************************
Name        :textArea1ClickHandler()
Description :textArea1����ص�������
Input       :text:�ı��ؼ�  event:����¼�
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void Screen1View::textArea1ClickHandler(const TextAreaWithOneWildcard& text, const ClickEvent& event)
{
    if (&text == &textArea1)
    {
        if (event.getType() == ClickEvent::PRESSED)
        {
            if (KeyboardExist == 0)
            {
                KeyboardExist = 1;

                add(MyKeyboard);
                MyKeyboard.initialize();
                MyKeyboard.invalidate();
            }
        }
    }
}
