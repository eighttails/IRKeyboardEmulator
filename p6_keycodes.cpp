#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include "p6_keycodes.h"
#include "send_ir.h"

const std::map<int, std::string> p6_code_names
{

    { KP6_UNKNOWN, "UNKNOWN" },

    { KP6_0, "0" },
    { KP6_1, "1" },
    { KP6_2, "2" },
    { KP6_3, "3" },
    { KP6_4, "4" },
    { KP6_5, "5" },
    { KP6_6, "6" },
    { KP6_7, "7" },
    { KP6_8, "8" },
    { KP6_9, "9" },

    { KP6_A, "A" },
    { KP6_B, "B" },
    { KP6_C, "C" },
    { KP6_D, "D" },
    { KP6_E, "E" },
    { KP6_F, "F" },
    { KP6_G, "G" },
    { KP6_H, "H" },
    { KP6_I, "I" },
    { KP6_J, "J" },
    { KP6_K, "K" },
    { KP6_L, "L" },
    { KP6_M, "M" },
    { KP6_N, "N" },
    { KP6_O, "O" },
    { KP6_P, "P" },
    { KP6_Q, "Q" },
    { KP6_R, "R" },
    { KP6_S, "S" },
    { KP6_T, "T" },
    { KP6_U, "U" },
    { KP6_V, "V" },
    { KP6_W, "W" },
    { KP6_X, "X" },
    { KP6_Y, "Y" },
    { KP6_Z, "Z" },

    { KP6_SPACE, "SPACE" },
    { KP6_COMMA, "COMMA" },
    { KP6_MINUS, "MINUS" },
    { KP6_PERIOD, "PERIOD" },
    { KP6_SLASH, "SLASH" },
    { KP6_AT, "AT" },
    { KP6_LBRACKET, "LBRACKET" },
    { KP6_RBRACKET, "RBRACKET" },
    { KP6_CARET, "CARET" },
    { KP6_UNDERSCORE, "UNDERSCORE" },
    { KP6_YEN, "YEN" },
    { KP6_COLON, "COLON" },
    { KP6_SEMICOLON, "SEMICOLON" },

    { KP6_TAB, "TAB" },
    { KP6_HOME, "HOME" },
    { KP6_RETURN, "RETURN" },
    { KP6_INS, "INS" },
    { KP6_ESC, "ESC" },
    { KP6_RIGHT, "RIGHT" },
    { KP6_LEFT, "LEFT" },
    { KP6_UP, "UP" },
    { KP6_DOWN, "DOWN" },
    { KP6_DEL, "DEL" },
    { KP6_PAGE, "PAGE" },

    { KP6_F1, "F1" },
    { KP6_F2, "F2" },
    { KP6_F3, "F3" },
    { KP6_F4, "F4" },
    { KP6_F5, "F5" },

    { KP6_STOP, "STOP" },
    { KP6_CAPS, "CAPS" },
    { KP6_MODE, "MODE" },
    { KP6_KANA, "KANA" },

    { KP6_CTRL, "CTRL" },
    { KP6_SHIFT, "SHIFT" },
    { KP6_GRAPH, "GRAPH" },

};

bool process_p6_key_event(const P6KeyEvent &event)
{
    static P6GameKeyStatus prev_game_keys = {};

    P6KEYsym code = event.code;
    bool pressed = event.pressed;

    // handle game specific key event
    P6GameKeyStatus game_keys = {};
    if (pressed && code == KP6_SPACE) game_keys.space = true;
    if (pressed && code == KP6_LEFT)  game_keys.left  = true;
    if (pressed && code == KP6_DOWN)  game_keys.down  = true;
    if (pressed && code == KP6_UP)    game_keys.up    = true;
    if (pressed && code == KP6_STOP)  game_keys.stop  = true;
    if (pressed && code == KP6_SHIFT) game_keys.shift = true;
    if (game_keys != prev_game_keys){
        std::cerr << p6_code_names.at(code) << " status changed." << std::endl;
        prev_game_keys = game_keys;
        if (!send_gamekey(game_keys)){
            return false;
        }
    }

    // handle normal key event
    // send to IR only if key is pressed.
    if (!pressed) return true;

    std::cerr << p6_code_names.at(code) << (pressed ? " pressed." : " released.") << std::endl;

    return send_key(event);
}
