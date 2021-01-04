#include <cstdint>
#include <map>
#include <iostream>

#ifndef IR_STUB
#include <pigpiod_if2.h>
#endif

#include "send_ir.h"

struct IRCode {
    uint8_t control_code;
    uint8_t key_code;
};


const std::map<P6KEYsym, IRCode> ircode_table =
{
    { KP6_0,            { 0b000, 0x30 }},
    { KP6_1,            { 0b000, 0x31 }},
    { KP6_2,            { 0b000, 0x32 }},
    { KP6_3,            { 0b000, 0x33 }},
    { KP6_4,            { 0b000, 0x34 }},
    { KP6_5,            { 0b000, 0x35 }},
    { KP6_6,            { 0b000, 0x36 }},
    { KP6_7,            { 0b000, 0x37 }},
    { KP6_8,            { 0b000, 0x38 }},
    { KP6_9,            { 0b000, 0x39 }},

    { KP6_A,            { 0b000, 0x61 }},
    { KP6_B,            { 0b000, 0x62 }},
    { KP6_C,            { 0b000, 0x63 }},
    { KP6_D,            { 0b000, 0x64 }},
    { KP6_E,            { 0b000, 0x65 }},
    { KP6_F,            { 0b000, 0x66 }},
    { KP6_G,            { 0b000, 0x67 }},
    { KP6_H,            { 0b000, 0x68 }},
    { KP6_I,            { 0b000, 0x69 }},
    { KP6_J,            { 0b000, 0x6a }},
    { KP6_K,            { 0b000, 0x6b }},
    { KP6_L,            { 0b000, 0x6c }},
    { KP6_M,            { 0b000, 0x6d }},
    { KP6_N,            { 0b000, 0x6e }},
    { KP6_O,            { 0b000, 0x6f }},
    { KP6_P,            { 0b000, 0x70 }},
    { KP6_Q,            { 0b000, 0x71 }},
    { KP6_R,            { 0b000, 0x72 }},
    { KP6_S,            { 0b000, 0x73 }},
    { KP6_T,            { 0b000, 0x74 }},
    { KP6_U,            { 0b000, 0x75 }},
    { KP6_V,            { 0b000, 0x76 }},
    { KP6_W,            { 0b000, 0x77 }},
    { KP6_X,            { 0b000, 0x78 }},
    { KP6_Y,            { 0b000, 0x79 }},
    { KP6_Z,            { 0b000, 0x7a }},

    { KP6_SPACE,        { 0b000, 0x20 }},
    { KP6_COMMA,        { 0b000, 0x2c }},
    { KP6_MINUS,        { 0b000, 0x2d }},
    { KP6_PERIOD,       { 0b000, 0x2e }},
    { KP6_SLASH,        { 0b000, 0x2f }},
    { KP6_AT,           { 0b000, 0x40 }},
    { KP6_LBRACKET,     { 0b000, 0x5b }},
    { KP6_RBRACKET,     { 0b000, 0x5d }},
    { KP6_CARET,        { 0b000, 0x5e }},
    { KP6_UNDERSCORE,   { 0b000, 0xdb }},
    { KP6_YEN,          { 0b000, 0x5c }},
    { KP6_COLON,        { 0b000, 0x3a }},
    { KP6_SEMICOLON,    { 0b000, 0x3b }},

    { KP6_TAB,          { 0b000, 0x09 }},
    { KP6_HOME,         { 0b000, 0x0c }},
    { KP6_RETURN,       { 0b000, 0x0d }},
    { KP6_INS,          { 0b000, 0x12 }},
    { KP6_ESC,          { 0b000, 0x1b }},
    { KP6_RIGHT,        { 0b000, 0x1c }},
    { KP6_LEFT,         { 0b000, 0x1d }},
    { KP6_UP,           { 0b000, 0x1e }},
    { KP6_DOWN,         { 0b000, 0x1f }},
    { KP6_DEL,          { 0b000, 0x7f }},
    { KP6_PAGE,         { 0b000, 0xfe }},

    { KP6_F1,           { 0b001, 0xf0 }},
    { KP6_F2,           { 0b001, 0xf1 }},
    { KP6_F3,           { 0b001, 0xf2 }},
    { KP6_F4,           { 0b001, 0xf3 }},
    { KP6_F5,           { 0b001, 0xf4 }},

    { KP6_STOP,         { 0b001, 0xfa }},
    { KP6_CAPS,         { 0b001, 0xfb }},
    { KP6_MODE,         { 0b001, 0xfd }},
    { KP6_KANA,         { 0b001, 0xfe }}
};

const std::map<P6KEYsym, IRCode> ircode_table_shift =
{
    { KP6_0,            { 0b000, 0xa6}},
    { KP6_1,            { 0b000, 0x21 }},
    { KP6_2,            { 0b000, 0x22 }},
    { KP6_3,            { 0b000, 0x23 }},
    { KP6_4,            { 0b000, 0x24 }},
    { KP6_5,            { 0b000, 0x25 }},
    { KP6_6,            { 0b000, 0x26 }},
    { KP6_7,            { 0b000, 0x27 }},
    { KP6_8,            { 0b000, 0x28 }},
    { KP6_9,            { 0b000, 0x29 }},

    { KP6_A,            { 0b000, 0x41 }},
    { KP6_B,            { 0b000, 0x42 }},
    { KP6_C,            { 0b000, 0x43 }},
    { KP6_D,            { 0b000, 0x44 }},
    { KP6_E,            { 0b000, 0x45 }},
    { KP6_F,            { 0b000, 0x46 }},
    { KP6_G,            { 0b000, 0x47 }},
    { KP6_H,            { 0b000, 0x48 }},
    { KP6_I,            { 0b000, 0x49 }},
    { KP6_J,            { 0b000, 0x4a }},
    { KP6_K,            { 0b000, 0x4b }},
    { KP6_L,            { 0b000, 0x4c }},
    { KP6_M,            { 0b000, 0x4d }},
    { KP6_N,            { 0b000, 0x4e }},
    { KP6_O,            { 0b000, 0x4f }},
    { KP6_P,            { 0b000, 0x50 }},
    { KP6_Q,            { 0b000, 0x51 }},
    { KP6_R,            { 0b000, 0x52 }},
    { KP6_S,            { 0b000, 0x53 }},
    { KP6_T,            { 0b000, 0x54 }},
    { KP6_U,            { 0b000, 0x55 }},
    { KP6_V,            { 0b000, 0x56 }},
    { KP6_W,            { 0b000, 0x57 }},
    { KP6_X,            { 0b000, 0x58 }},
    { KP6_Y,            { 0b000, 0x59 }},
    { KP6_Z,            { 0b000, 0x5a }},

    { KP6_SPACE,        { 0b000, 0x20 }},
    { KP6_COMMA,        { 0b000, 0x3c }},
    { KP6_MINUS,        { 0b000, 0x3d }},
    { KP6_PERIOD,       { 0b000, 0x3e }},
    { KP6_SLASH,        { 0b000, 0x3f }},
    { KP6_AT,           { 0b000, 0x40 }},
    { KP6_LBRACKET,     { 0b000, 0xa2 }},
    { KP6_RBRACKET,     { 0b000, 0xa3 }},
    { KP6_CARET,        { 0b000, 0x00 }},
    { KP6_UNDERSCORE,   { 0b000, 0x5f }},
    { KP6_YEN,          { 0b000, 0x00 }},
    { KP6_COLON,        { 0b000, 0x2a }},
    { KP6_SEMICOLON,    { 0b000, 0x2b }},

    { KP6_TAB,          { 0b000, 0x09 }},
    { KP6_HOME,         { 0b000, 0x0b }},
    { KP6_RETURN,       { 0b000, 0x0d }},
    { KP6_INS,          { 0b000, 0x12 }},
    { KP6_ESC,          { 0b000, 0x1b }},
    { KP6_RIGHT,        { 0b000, 0x1c }},
    { KP6_LEFT,         { 0b000, 0x1d }},
    { KP6_UP,           { 0b000, 0x1e }},
    { KP6_DOWN,         { 0b000, 0x1f }},
    { KP6_DEL,          { 0b000, 0x7f }},
    { KP6_PAGE,         { 0b001, 0xfc }},

    { KP6_F1,           { 0b001, 0xf5 }},
    { KP6_F2,           { 0b001, 0xf6 }},
    { KP6_F3,           { 0b001, 0xf7 }},
    { KP6_F4,           { 0b001, 0xf8 }},
    { KP6_F5,           { 0b001, 0xf9 }},

    { KP6_STOP,         { 0b001, 0xfa }},
    { KP6_CAPS,         { 0b001, 0xfb }},
    { KP6_MODE,         { 0b001, 0xfd }},
    { KP6_KANA,         { 0b001, 0xfe }}
};

const std::map<P6KEYsym, IRCode> ircode_table_ctrl =
{
    { KP6_0,            { 0b000, 0x00 }},
    { KP6_1,            { 0b000, 0x00 }},
    { KP6_2,            { 0b000, 0x00 }},
    { KP6_3,            { 0b000, 0x00 }},
    { KP6_4,            { 0b000, 0x00 }},
    { KP6_5,            { 0b000, 0x00 }},
    { KP6_6,            { 0b000, 0x00 }},
    { KP6_7,            { 0b000, 0x00 }},
    { KP6_8,            { 0b000, 0x00 }},
    { KP6_9,            { 0b000, 0x00 }},

    { KP6_A,            { 0b000, 0x01 }},
    { KP6_B,            { 0b000, 0x02 }},
    { KP6_C,            { 0b000, 0x03 }},
    { KP6_D,            { 0b000, 0x04 }},
    { KP6_E,            { 0b000, 0x05 }},
    { KP6_F,            { 0b000, 0x06 }},
    { KP6_G,            { 0b000, 0x07 }},
    { KP6_H,            { 0b000, 0x08 }},
    { KP6_I,            { 0b000, 0x09 }},
    { KP6_J,            { 0b000, 0x0a }},
    { KP6_K,            { 0b000, 0x0b }},
    { KP6_L,            { 0b000, 0x0c }},
    { KP6_M,            { 0b000, 0x0d }},
    { KP6_N,            { 0b000, 0x0e }},
    { KP6_O,            { 0b000, 0x0f }},
    { KP6_P,            { 0b000, 0x10 }},
    { KP6_Q,            { 0b000, 0x11 }},
    { KP6_R,            { 0b000, 0x12 }},
    { KP6_S,            { 0b000, 0x13 }},
    { KP6_T,            { 0b000, 0x14 }},
    { KP6_U,            { 0b000, 0x15 }},
    { KP6_V,            { 0b000, 0x16 }},
    { KP6_W,            { 0b000, 0x17 }},
    { KP6_X,            { 0b000, 0x18 }},
    { KP6_Y,            { 0b000, 0x19 }},
    { KP6_Z,            { 0b000, 0x1a }},

    { KP6_SPACE,        { 0b000, 0x00 }},
    { KP6_COMMA,        { 0b000, 0x00 }},
    { KP6_MINUS,        { 0b000, 0x00 }},
    { KP6_PERIOD,       { 0b000, 0x00 }},
    { KP6_SLASH,        { 0b000, 0x00 }},
    { KP6_AT,           { 0b000, 0x00 }},
    { KP6_LBRACKET,     { 0b000, 0x1b }},
    { KP6_RBRACKET,     { 0b000, 0x1d }},
    { KP6_CARET,        { 0b000, 0x1e }},
    { KP6_UNDERSCORE,   { 0b000, 0x00 }},
    { KP6_YEN,          { 0b000, 0x00 }},
    { KP6_COLON,        { 0b000, 0x00 }},
    { KP6_SEMICOLON,    { 0b000, 0x00 }},

    { KP6_TAB,          { 0b000, 0x00 }},
    { KP6_HOME,         { 0b000, 0x00 }},
    { KP6_RETURN,       { 0b000, 0x00 }},
    { KP6_INS,          { 0b000, 0x12 }},
    { KP6_ESC,          { 0b000, 0x00 }},
    { KP6_RIGHT,        { 0b000, 0x00 }},
    { KP6_LEFT,         { 0b000, 0x00 }},
    { KP6_UP,           { 0b000, 0x00 }},
    { KP6_DOWN,         { 0b000, 0x00 }},
    { KP6_DEL,          { 0b000, 0x7f }},
    { KP6_PAGE,         { 0b000, 0xfe }},

    { KP6_F1,           { 0b001, 0x00 }},
    { KP6_F2,           { 0b001, 0x00 }},
    { KP6_F3,           { 0b001, 0x00 }},
    { KP6_F4,           { 0b001, 0x00 }},
    { KP6_F5,           { 0b001, 0x00 }},

    { KP6_STOP,         { 0b010, 0x02 }},
    { KP6_CAPS,         { 0b001, 0xfb }},
    { KP6_MODE,         { 0b001, 0xfd }},
    { KP6_KANA,         { 0b001, 0xfe }}
};

const std::map<P6KEYsym, IRCode> ircode_table_graph =
{
    { KP6_0,            { 0b001, 0x0f }},
    { KP6_1,            { 0b001, 0x07 }},
    { KP6_2,            { 0b001, 0x01 }},
    { KP6_3,            { 0b001, 0x02 }},
    { KP6_4,            { 0b001, 0x03 }},
    { KP6_5,            { 0b001, 0x04 }},
    { KP6_6,            { 0b001, 0x05 }},
    { KP6_7,            { 0b001, 0x06 }},
    { KP6_8,            { 0b001, 0x0d }},
    { KP6_9,            { 0b001, 0x0e }},

    { KP6_A,            { 0b001, 0x00 }},
    { KP6_B,            { 0b001, 0x1b }},
    { KP6_C,            { 0b001, 0x1a }},
    { KP6_D,            { 0b001, 0x14 }},
    { KP6_E,            { 0b001, 0x18 }},
    { KP6_F,            { 0b001, 0x15 }},
    { KP6_G,            { 0b001, 0x13 }},
    { KP6_H,            { 0b001, 0x0a }},
    { KP6_I,            { 0b001, 0x16 }},
    { KP6_J,            { 0b001, 0x00 }},
    { KP6_K,            { 0b001, 0x00 }},
    { KP6_L,            { 0b001, 0x1e }},
    { KP6_M,            { 0b001, 0x0b }},
    { KP6_N,            { 0b001, 0x00 }},
    { KP6_O,            { 0b001, 0x00 }},
    { KP6_P,            { 0b001, 0x10 }},
    { KP6_Q,            { 0b001, 0x00 }},
    { KP6_R,            { 0b001, 0x12 }},
    { KP6_S,            { 0b001, 0x0c }},
    { KP6_T,            { 0b001, 0x19 }},
    { KP6_U,            { 0b001, 0x00 }},
    { KP6_V,            { 0b001, 0x11 }},
    { KP6_W,            { 0b001, 0x00 }},
    { KP6_X,            { 0b001, 0x1c }},
    { KP6_Y,            { 0b001, 0x08 }},
    { KP6_Z,            { 0b001, 0x00 }},

    { KP6_SPACE,        { 0b001, 0x00 }},
    { KP6_COMMA,        { 0b001, 0x1f }},
    { KP6_MINUS,        { 0b001, 0x17 }},
    { KP6_PERIOD,       { 0b001, 0x1d }},
    { KP6_SLASH,        { 0b001, 0x80 }},
    { KP6_AT,           { 0b001, 0x00 }},
    { KP6_LBRACKET,     { 0b001, 0x84 }},
    { KP6_RBRACKET,     { 0b001, 0x85 }},
    { KP6_CARET,        { 0b001, 0x00 }},
    { KP6_UNDERSCORE,   { 0b001, 0x83 }},
    { KP6_YEN,          { 0b001, 0x09 }},
    { KP6_COLON,        { 0b001, 0x81 }},
    { KP6_SEMICOLON,    { 0b001, 0x82 }},

    { KP6_TAB,          { 0b001, 0x00 }},
    { KP6_HOME,         { 0b000, 0x0c }},
    { KP6_RETURN,       { 0b001, 0x00 }},
    { KP6_INS,          { 0b000, 0x12 }},
    { KP6_ESC,          { 0b001, 0x00 }},
    { KP6_RIGHT,        { 0b001, 0x00 }},
    { KP6_LEFT,         { 0b010, 0x20 }},
    { KP6_UP,           { 0b001, 0x00 }},
    { KP6_DOWN,         { 0b010, 0x08 }},
    { KP6_DEL,          { 0b000, 0x7f }},
    { KP6_PAGE,         { 0b000, 0xfe }},

    { KP6_F1,           { 0b001, 0xf0 }},
    { KP6_F2,           { 0b001, 0xf1 }},
    { KP6_F3,           { 0b001, 0xf2 }},
    { KP6_F4,           { 0b001, 0xf3 }},
    { KP6_F5,           { 0b001, 0xf4 }},

    { KP6_STOP,         { 0b001, 0x00 }},
    { KP6_CAPS,         { 0b001, 0xfb }},
    { KP6_MODE,         { 0b001, 0xfd }},
    { KP6_KANA,         { 0b001, 0xfe }}
};


const unsigned GPIOID = 10;
const unsigned PWMFREQ = 38000;
const uint32_t PWMDUTY = 500000; // half of PWM resolution(1000000).
int pi = 0; //pigpio handle

bool init_ir()
{
#ifndef IR_STUB
    pi = pigpio_start(NULL, NULL);
    if (pi == 0) {
        std::cerr << "pigpio_start failed." << std::endl;
        return false;
    }
    int err = 0;
    err = set_mode(pi, GPIOID, PI_OUTPUT);
    if (err = set_mode(pi, GPIOID, PI_OUTPUT)) {
        std::cerr << "set_mode failed. " << err << std::endl;
        return false;
    }
    if (err = hardware_PWM(pi, GPIOID, PWMFREQ, PWMDUTY)) {
        std::cerr << "hardware_PWM failed. " << err << std::endl;
        return false;
    }
    return true;
#else
    return true;
#endif
}

bool send_ir(const IRCode &code)
{
#ifndef IR_STUB
    // TODO
    return true;
#else
    // TODO
    return true;
#endif
}

bool send_key(const P6KeyEvent &event)
{
    static bool shift = false;
    static bool ctrl  = false;
    static bool graph = false;

    P6KEYsym code = event.code;
    bool pressed = event.pressed;

    if (code == KP6_SHIFT) {
        shift = pressed;
    } else if (code == KP6_CTRL) {
        ctrl  = pressed;
    } else if (code == KP6_GRAPH) {
        graph = pressed;
    } else {
        // convert key code to IR code.
        IRCode ir_code = {};
        if (shift) {
            ir_code = ircode_table_shift.at(code);
        } else if (ctrl) {
            ir_code = ircode_table_ctrl.at(code);
        } else if (graph) {
            ir_code = ircode_table_graph.at(code);
        } else {
            ir_code = ircode_table.at(code);
        }
        return send_ir(ir_code);
    }
    return true;
}


bool send_gamekey(const P6GameKeyStatus &stat)
{
    uint8_t game_keys = 0;
    if (stat.stop)  game_keys |= (1<<7);
    if (stat.left)  game_keys |= (1<<5);
    if (stat.right) game_keys |= (1<<4);
    if (stat.down)  game_keys |= (1<<3);
    if (stat.up)    game_keys |= (1<<2);
    if (stat.stop)  game_keys |= (1<<1);
    if (stat.shift) game_keys |= (1<<0);

    IRCode code;
    code.control_code = 0b010;
    code.key_code = game_keys;

    return send_ir(code);
}


