//#1E-1M. Program to draw points and also apply various properties(color,width) .

#include<stdio.h>
#include<GL/glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}
void display1()
{
	glClearColor(0.6, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glBegin(GL_POINTS);
		glColor3f(0, 0, 1);
		glVertex2f(20, 250);
		glVertex2f(480, 250);
		glColor3f(0, 0, 0);
		glVertex2f(250, 480);
		glVertex2f(250, 20);
		glColor3f(1, 0, 0);
		glVertex2f(250, 250);
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("Points");
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();

}