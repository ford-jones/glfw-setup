#include "main.h"

int main()
{
    window = new WindowManager(800, 600, "Ford & Xaviers Awesome Window", NULL, NULL);
    window->Initialise();

    delete window;
    return 0;
};
