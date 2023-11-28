#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <iostream>


const int windowWidth = 1024;
const int windowHeight = 768;

void myDisplay() {
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, width, height);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0, -1.0, 0.0);
        glVertex3f(0.5, -0.5, 0.0);
        glVertex3f(1.0, 1.0, 0.0);
        glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glFlush();
}

void tempDisplay() { /* dummy display function to center the window */ }

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);

    // Create a temporary window (to center the window on the screen)
    glutInitWindowSize(1, 1);
    glutCreateWindow("Temporary Window");
    glutDisplayFunc(tempDisplay);

    // Get screen resolution
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

    // Calculate window position
    int windowPosX = (screenWidth - windowWidth) / 2;
    int windowPosY = (screenHeight - windowHeight) / 2;

    // Destroy temporary window
    glutDestroyWindow(glutGetWindow());

    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(windowPosX, windowPosY);
    glutCreateWindow("OpenGL View Port");
    glutSetWindow(glutGetWindow());
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
