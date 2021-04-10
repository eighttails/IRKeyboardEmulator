#pragma once

// P6 key codes
typedef enum
{
    KP6_UNKNOWN,

    KP6_0,
    KP6_1,
    KP6_2,
    KP6_3,
    KP6_4,
    KP6_5,
    KP6_6,
    KP6_7,
    KP6_8,
    KP6_9,

    KP6_A,
    KP6_B,
    KP6_C,
    KP6_D,
    KP6_E,
    KP6_F,
    KP6_G,
    KP6_H,
    KP6_I,
    KP6_J,
    KP6_K,
    KP6_L,
    KP6_M,
    KP6_N,
    KP6_O,
    KP6_P,
    KP6_Q,
    KP6_R,
    KP6_S,
    KP6_T,
    KP6_U,
    KP6_V,
    KP6_W,
    KP6_X,
    KP6_Y,
    KP6_Z,

    KP6_SPACE,
    KP6_COMMA,
    KP6_MINUS,
    KP6_PERIOD,
    KP6_SLASH,
    KP6_AT,
    KP6_LBRACKET,
    KP6_RBRACKET,
    KP6_CARET,
    KP6_UNDERSCORE,
    KP6_YEN,
    KP6_COLON,
    KP6_SEMICOLON,

    KP6_TAB,
    KP6_HOME,
    KP6_RETURN,
    KP6_INS,
    KP6_ESC,
    KP6_RIGHT,
    KP6_LEFT,
    KP6_UP,
    KP6_DOWN,
    KP6_DEL,
    KP6_PAGE,

    KP6_F1,
    KP6_F2,
    KP6_F3,
    KP6_F4,
    KP6_F5,

    KP6_STOP,
    KP6_CAPS,
    KP6_MODE,
    KP6_KANA,

    KP6_CTRL,
    KP6_SHIFT,
    KP6_GRAPH,

    KP6_LAST
} P6KEYsym;

struct P6KeyEvent {
    P6KEYsym code;
    bool pressed; // press = true, release = false
};

struct P6GameKeyStatus {
    // press = true, release = false
    bool space;
    bool right;
    bool left;
    bool down;
    bool up;
    bool stop;
    bool shift;
};

inline bool operator==(const P6GameKeyStatus& a, const P6GameKeyStatus& b)
{
    return  a.space == b.space &&
            a.right == b.right &&
            a.left  == b.left  &&
            a.down  == b.down  &&
            a.up    == b.up    &&
            a.stop  == b.stop  &&
            a.shift == b.shift;
}

inline bool operator!=(const P6GameKeyStatus& a, const P6GameKeyStatus& b)
{
    return !(a == b);
}

bool process_p6_key_event(const P6KeyEvent& event);
