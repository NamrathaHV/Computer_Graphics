// #29E-5M. Write a program to draw a polygon using display list.

#include<stdio.h>
#include<stdlib.h>
#include<gl/glut.h>

GLuint listID = glGenLists(1);

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
	glMatrixMode(GL_MODELVIEW);
}

void draw()
{
	glCallList(listID);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glNewList(listID, GL_COMPILE);
		glColor3f(1, 0.4, 1);
		glBegin(GL_POLYGON);
			glVertex2f(100.0, 200.0);
			glVertex2f(200.0, 250.0);
			glVertex2f(300.0, 200.0);
			glVertex2f(250.0, 100.0);
			glVertex2f(150.0, 100.0);
		glEnd();
		glFlush();
	glEndList();
	draw();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Polygon");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}