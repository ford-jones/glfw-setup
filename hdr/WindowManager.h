#include <iostream>
#include "GL/gl.h"
#include <GLFW/glfw3.h>

#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

class WindowManager
{
    public:
        int height, width;
        const char *title;
        GLFWmonitor *monitor;
        GLFWwindow *fullscreen, *window;

        GLclampf red, green, blue, alpha;

        WindowManager(int h, int w, const char *t, GLFWmonitor *m, GLFWwindow *win);
        virtual ~WindowManager();
        int Initialise();
        
    private:
        int errorCode;
        const char** errorMessage;
};

#endif