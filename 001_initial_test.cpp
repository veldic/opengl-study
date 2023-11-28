#include <OpenGL/gl.h>
#include <GLUT/glut.h>

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5, -0.5, 0.0);
        glVertex3f(0.5, -0.5, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Testing");
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
