#include "../hdr/WindowManager.h"

int WindowManager::WindowInit()
{
    if(!glfwInit())
    {
        std::cout << "ERROR::GLFW::NOT_FOUND" << std::endl;
        glfwTerminate();
        return -1;
    };

    window = glfwCreateWindow
    (
        height, 
        width, 
        title, 
        monitor, 
        fullscreen
    );

    while(!glfwWindowShouldClose(window))
    {
        errorCode = glfwGetError(errorMessage); 

        if(errorCode != GLFW_NO_ERROR)
        {
            std::cout << "ERROR::GLFW::WINDOW" << std::endl;
            std::cout << "GL_MESSAGE: " << errorMessage << std::endl;

            return errorCode;
        };
    };

    return GLFW_NO_ERROR;
};

WindowManager::WindowManager(int h, int w, const char *t, GLFWmonitor *m, GLFWwindow *win)
{
    height = h;
    width = w;
    title = t;
    monitor = m;
    fullscreen = win;
};

WindowManager::~WindowManager() 
{
    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout << "Destroying window memory" << std::endl;
};
