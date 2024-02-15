#include "main.h"

int main()
{
    manager = new WindowManager(800, 600, "Ford & Xaviers Awesome Window", NULL, NULL);
    manager->WindowInit();

    delete manager;
    return 0;
};
