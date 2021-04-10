#pragma once
// send ir code from transmitter.
#include "p6_keycodes.h"

bool init_ir();
bool deinit_ir();
bool send_key(const P6KeyEvent& event);
bool send_gamekey(const P6GameKeyStatus& stat);


