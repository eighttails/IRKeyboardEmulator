#include <cstdint>

struct IRCode {
    uint8_t control_code;
    uint8_t key_code;
};

bool send_ir(const IRCode& code);
