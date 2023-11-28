#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif


const int windowWidth = 1024;
const int windowHeight = 768;

void drawCube() {
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Back face
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);

    // Top face
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // Bottom face
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    // Right face
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // Left face
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    glEnd();
}

void myDisplay() {
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, width, height);
    drawCube();
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

    // Main window settings
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(windowPosX, windowPosY);
    glutCreateWindow("OpenGL View Port");
    glutSetWindow(glutGetWindow());
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Perspective Mode
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (double)windowWidth/(double)windowHeight, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.5, 2.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
