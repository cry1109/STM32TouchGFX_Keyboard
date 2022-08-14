#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <gui/containers/Keyboard.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    /*����textArea1�ص�������*/
    void textArea1ClickHandler(const TextAreaWithOneWildcard& text, const ClickEvent& event);

    void KeyboardEscBtClickHandler(Keyboard& element);
    void KeyboardEnEnterBtClickHandler(Keyboard& element);
    void KeyboardNbEnterBtClickHandler(Keyboard& element);
    void KeyboardCnEnterBtClickHandler(Keyboard& element);

protected:

    /*����TextArea1����ص�*/
    Callback<Screen1View, const TextAreaWithOneWildcard&,const ClickEvent&> textArea1ClickedCallback;

    /*����Keyboard�ؼ�������ذ�ť�ص�*/
    uint8_t KeyboardExist;
    Keyboard MyKeyboard;
    Callback<Screen1View, Keyboard&> KeyboardEscBtClickedCallBack;
    Callback<Screen1View, Keyboard&> KeyboardEnEnterBtClickedCallBack;
    Callback<Screen1View, Keyboard&> KeyboardNbEnterBtClickedCallBack;
    Callback<Screen1View, Keyboard&> KeyboardCnEnterBtClickedCallBack;
};

#endif // SCREEN1VIEW_HPP
