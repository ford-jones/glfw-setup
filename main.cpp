#include "main.h"

int main()
{
    manager = new WindowManager(800, 600, "Test Window", NULL, NULL);
    manager->WindowInit();

    delete manager;
    return 0;
};
