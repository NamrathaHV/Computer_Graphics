//14E-2M. Write a program to draw a polygon an d demonstrate various properties.

#include<stdio.h>
#include<Gl/glut.h>

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

}

void drawPolygon()
{
    glBegin(GL_POLYGON);
    glEdgeFlag(GL_TRUE);
    glVertex2f(20, 20);
    glEdgeFlag(GL_TRUE);
    glVertex2f(80, 80);
    glEdgeFlag(GL_TRUE);
    glVertex2f(100, 20);
    glEnd();
    glFlush();

}

void display()
{
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);

    //glLineWidth(3);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glPointSize(5);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0101);
    drawPolygon();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polygon Attributes");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();

}