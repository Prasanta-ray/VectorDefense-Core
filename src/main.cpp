#include <glad/glad.h> // Loads the raw OpenGL function pointers
#include <GLFW/glfw3.h> // Handles the desktop window and OS inputs
#include <stdio.h>
#include <stdlib.h>

// Dynamically scale the viewport if the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // 1. Boot up GLFW
    if (!glfwInit()) {
        printf("Critical Error: Failed to initialize GLFW\n");
        return -1;
    }

    // Lock it to OpenGL 3.3 Core Profile (Modern OpenGL, no legacy junk)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 2. Create the raw desktop window
    GLFWwindow* window = glfwCreateWindow(800, 600, "VectorDefense v0.1 - C Core Engine", NULL, NULL);
    if (!window) {
        printf("Critical Error: Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 3. Load OpenGL pointers via GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Critical Error: Failed to initialize GLAD\n");
        return -1;
    }

    printf("Booting VectorDefense Core Engine...\n");

    // 4. The Main Game Loop
    while (!glfwWindowShouldClose(window)) {
        // Input Handling: Hit ESC to kill the engine
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, 1);
        }

        // Render Phase: Clear screen to a dark, modern background
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // --> Your raw C render logic, math, and shaders will go here <--

        // Swap the front and back buffers, poll for keyboard/mouse events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    printf("Engine shutting down cleanly.\n");
    glfwTerminate();
    return 0;
}
