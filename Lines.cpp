//#2E-1M. Program to draw lines and also apply various properties(color, width, stipple).

#include<stdio.h>
#include<GL/glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
}
void display1()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.7, 0.1, 1);
	glLineWidth(4.0);
	glLineStipple(2, 0XAAAA);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
		glVertex2f(20, 30);
		glVertex2f(20, 80);
		glVertex2f(60, 30);
		glVertex2f(60, 80);
		glVertex2f(38, 40);
		glVertex2f(38, 70);
		glVertex2f(42, 40);
		glVertex2f(42, 70);

		glVertex2f(20, 30);
		glVertex2f(38, 40);
		glVertex2f(60, 30);
		glVertex2f(42, 40);
		glVertex2f(20, 80);
		glVertex2f(38, 70);
		glVertex2f(60, 80);
		glVertex2f(42, 70);
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Lines");
	
	glutDisplayFunc(display1);
	myinit();
	glutMainLoop();

}