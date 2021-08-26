//#4E-1M. Write a program to draw a house using Lines.

#include<stdio.h>
#include<GL/glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 150, 0, 150);
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.1, 1);
	glLineWidth(2.0);
	glBegin(GL_LINES);
		glVertex2f(20, 2);
		glVertex2f(20, 40);
		glVertex2f(50, 2);
		glVertex2f(50, 40);
		glVertex2f(100, 2);
		glVertex2f(100, 40);
		glVertex2f(20, 2);
		glVertex2f(50, 2);
		glVertex2f(50, 2);
		glVertex2f(100, 2);
	glEnd();
	glColor3f(0.5, 0.0, 0.3);
	glBegin(GL_LINES);
		glVertex2f(20, 40);
		glVertex2f(35, 60);
		glVertex2f(35, 60);
		glVertex2f(50, 40);
		glVertex2f(20, 40);
		glVertex2f(50, 40);

		glVertex2f(50, 40);
		glVertex2f(100, 40);
		glVertex2f(35, 60);
		glVertex2f(85, 60);
		glVertex2f(85, 60);
		glVertex2f(100, 40);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
		glVertex2f(30, 2);
		glVertex2f(30, 20);
		glVertex2f(30, 20);
		glVertex2f(40, 20);
		glVertex2f(40, 20);
		glVertex2f(40, 2);
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 150);
	glutCreateWindow("House");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();

}