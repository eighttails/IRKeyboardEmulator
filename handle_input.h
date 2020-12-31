#include <linux/input.h>

void init_input();
void deinit_input();

bool get_input(input_event& event);
