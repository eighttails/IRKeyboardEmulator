#include <fstream>
#include "handle_input.h"
#include "send_ir.h"

int main()
{
    if (!init_ir()){
        exit(EXIT_FAILURE);
    }
    init_input();
    while (true) {
        if (!handle_input()){
            deinit_input();
            exit(EXIT_FAILURE);
        }
    }
    deinit_input();
    if (!deinit_ir()){
        exit(EXIT_FAILURE);
    }
    return 0;
}
