#ifndef CUSTOMKEYEVENT_H
#define CUSTOMKEYEVENT_H

#include <QString>

namespace yasem {
namespace SDK {

class CustomKeyEvent
{
public:
    virtual ~CustomKeyEvent() {}
    enum KeyState {
        KeyDown = 0,
        KeyPress = 1,
        KeyRelease = 2,
        MouseDown = 3,
        MouseClick = 4,
        MouseUp = 5
    };

    enum EventType {
        TypeUnknown = 0,
        TypeKeyboard = 1,
        TypeMouse = 2
    };

    int m_key_code;
    int m_which;
    int m_key_code2;
    int m_which_2;
    bool m_alt;
    bool m_ctrl;
    bool m_shift;

    virtual QString toString() = 0;

protected:
    virtual void init(int m_key_code, int m_which, int m_key_code2, int m_which_2, bool m_alt = false, bool m_ctrl = false, bool m_shift = false) = 0;

};

}

}

#endif // CUSTOMKEYEVENT_H
