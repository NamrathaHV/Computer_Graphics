/* 16E-3M. Write a program to create a house like figure and scale it increase and decrease its size
using mouse callback function. */

#include<stdio.h>
#include<stdlib.h>
#include<gl/glut.h>

int sizef = 0;
void init()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}
void disp()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(200 - sizef, 100 - sizef);
	glVertex2f(400 + sizef, 100 - sizef);
	glVertex2f(400 + sizef, 300 + sizef);
	glVertex2f(200 - sizef, 300 + sizef);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(400 + sizef, 300 + sizef);
	glVertex2f(200 - sizef, 300 + sizef);
	glVertex2f(300, 400 + sizef);
	glEnd();
	glFlush();
}
void mousef(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
		sizef += 20;
	else if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
		sizef -= 20;
	/*else if (b == GLUT_MIDDLE_BUTTON && s == GLUT_DOWN)
		exit(0);*/
	glutPostRedisplay();

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 50);
	glutCreateWindow("Mouse Func");
	init();
	glutDisplayFunc(disp);
	glutMouseFunc(mousef);
	glutMainLoop();
}