#include <fstream>
#include "handle_input.h"

int main()
{
    init_input();
    while (true) {
        if (!handle_input()){
            deinit_input();
            exit(EXIT_FAILURE);
        }
    }
    deinit_input();
    return 0;
}
