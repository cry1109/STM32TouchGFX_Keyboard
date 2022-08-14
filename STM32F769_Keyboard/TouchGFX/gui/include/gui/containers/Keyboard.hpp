#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <gui_generated/containers/KeyboardBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <gui/containers/Keyboard.hpp>
#include <gui/containers/Pinyin.hpp>

class Keyboard : public KeyboardBase
{
public:
    Keyboard();
    virtual ~Keyboard() {}

    virtual void initialize();

    uint8_t getInputLength();
    void getInputText(touchgfx::Unicode::UnicodeChar *textBuff,uint16_t textLength);

    void setescBtCallback(GenericCallback< Keyboard& >& callback);		//����ESC���ص�
    void setcn_entBtrCallback(GenericCallback< Keyboard& >& callback);	//�������ļ���ȷ�����ص�
    void seten_entBtrCallback(GenericCallback< Keyboard& >& callback);	//����Ӣ�ļ���Enter���ص�
    void setnb_entBtrCallback(GenericCallback< Keyboard& >& callback);	//�������ּ���Enter���ص�

    void pySelecUpdata(uint8_t matchCount);
    void cnSelecUpdata(uint8_t page);
    void pyClearInput();

    /*��������ť����ص�*/
    virtual void escBtClick();
    virtual void clrBtClick();
    virtual void cn_enBtClick();
    virtual void numBtClick();

    /*Ӣ�ļ��̰�ť����ص�*/
    virtual void en_entBtClick();
    virtual void en_delBtClick();
    virtual void dxBtClick();
    virtual void aBtClick();
    virtual void bBtClick();
    virtual void cBtClick();
    virtual void dBtClick();
    virtual void eBtClick();
    virtual void fBtClick();
    virtual void gBtClick();
    virtual void hBtClick();
    virtual void iBtClick();
    virtual void jBtClick();
    virtual void kBtClick();
    virtual void lBtClick();
    virtual void mBtClick();
    virtual void nBtClick();
    virtual void oBtClick();
    virtual void pBtClick();
    virtual void qBtClick();
    virtual void rBtClick();
    virtual void sBtClick();
    virtual void tBtClick();
    virtual void uBtClick();
    virtual void vBtClick();
    virtual void wBtClick();
    virtual void xBtClick();
    virtual void yBtClick();
    virtual void zBtClick();
    virtual void blBtClick();

    /*���ּ��̰�ť����ص�*/
    virtual void fhDelBtClick();
    virtual void fhEntBtClick();
    virtual void nb1BtClick();
    virtual void nb2BtClick();
    virtual void nb3BtClick();
    virtual void nb4BtClick();
    virtual void nb5BtClick();
    virtual void nb6BtClick();
    virtual void nb7BtClick();
    virtual void nb8BtClick();
    virtual void nb9BtClick();
    virtual void nb0BtClick();
    virtual void fh1BtClick();
    virtual void fh2BtClick();
    virtual void fh3BtClick();
    virtual void fh4BtClick();
    virtual void fh5BtClick();
    virtual void fh6BtClick();
    virtual void fh7BtClick();
    virtual void fh8BtClick();
    virtual void fh9BtClick();
    virtual void fh10BtClick();
    virtual void fh11BtClick();
    virtual void fh12BtClick();

    /*���ļ��̰�ť����ص�*/
    virtual void cnBtBackClick();
    virtual void cnBtDelClick();
    virtual void cnBtEntClick();
    virtual void cnSelectBt1Click();
    virtual void cnSelectBt2Click();
    virtual void cnSelectBt3Click();
    virtual void cnSelectBt4Click();
    virtual void cnSelectBt5Click();
    virtual void pySelectBt1Click();
    virtual void pySelectBt2Click();
    virtual void pySelectBt3Click();
    virtual void pySelectBt4Click();
    virtual void pySelectBt5Click();
    virtual void cnBtLiftClick();
    virtual void cnBtRightClick();
    virtual void cnBtNoneClick();
    virtual void cnBtABCClick();
    virtual void cnBtDEFClick();
    virtual void cnBtGHIClick();
    virtual void cnBtJKLClick();
    virtual void cnBtMNOClick();
    virtual void cnBtPQRSClick();
    virtual void cnBtTUVClick();
    virtual void cnBtWXYZClick();

protected:

    typedef enum
    {
        CN_KEYBOARD = 0,    //���ļ���
        EN_KEYBOARD,        //Ӣ�ļ���
        NUMB_KEYBOARD       //���ּ���
    }keyboard_mode_def;

    typedef enum
    {
        LOWER_LETTER = 0,   //Сд��ĸ
        CAPITAL_LETTER      //��д��ĸ
    }letter_mode_def;

    const static uint16_t CN_NUMBER_SIZE = 6;

    uint8_t textInputCount;
    uint8_t cnNumberCount;
    keyboard_mode_def mode;
    letter_mode_def letter;
    char cnNumber[CN_NUMBER_SIZE];

    GenericCallback< Keyboard& >* escBtCallback;
    GenericCallback< Keyboard& >* cn_entBtCallback;
    GenericCallback< Keyboard& >* en_entBtCallback;
    GenericCallback< Keyboard& >* nb_entBtCallback;
};

#endif // KEYBOARD_HPP
