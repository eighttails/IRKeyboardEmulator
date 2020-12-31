#include <fstream>
#include "handle_input.h"
#include "p6_keycodes.h"
#include "send_ir.h"

int main()
{
    init_input();
    while (true) {
        input_event event;
        get_input(event);

    }
    deinit_input();
    return 0;
}
