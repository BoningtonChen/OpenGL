#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void)
{
	/* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = 
        glfwCreateWindow(
            640, 
            480, 
            "Hello OpenGL", 
            nullptr, 
            nullptr
        );
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)  
        std::cout << "ERROR! \n";

    // Print OpenGL Version
    std::cout << "OpenGL VERSION: " << glGetString(GL_VERSION) << "\n";

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
