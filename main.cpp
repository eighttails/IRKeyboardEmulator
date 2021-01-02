#include <fstream>
#include "handle_input.h"

int main()
{
    init_input();
    while (true) {
        handle_input();
    }
    deinit_input();
    return 0;
}
