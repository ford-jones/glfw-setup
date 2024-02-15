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

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glClearColor(red, green, blue, alpha);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        errorMessage = nullptr;
        errorCode = glfwGetError(errorMessage); 

        if(errorCode != GLFW_NO_ERROR)
        {
            std::cout << "ERROR::GLFW::WINDOW" << std::endl;
            std::cout << "GL_MESSAGE: " << errorMessage << std::endl;

            return errorCode;
        };

        glfwSwapBuffers(window);
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

    red = 0.0f;
    green = 0.0f;
    blue = 1.0f;
    alpha = 0.0f;
};

WindowManager::~WindowManager() 
{
    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout << "Destroying window memory" << std::endl;
};
