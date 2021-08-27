#include "controller/controller.h"

int main(void) {
    controller_initialize();
    controller_main_loop();
    controller_finalize();
    return 0;
}
