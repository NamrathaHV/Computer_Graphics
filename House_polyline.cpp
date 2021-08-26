//#4.1E-1M.program to draw polyline(LineLoop or LineStrip) and construct house using it

#include<stdio.h>
#include<GL/glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 150, 0, 150);
}
void display1()
{
	glClearColor(1, 1, 1, 1); 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.7, 0.1, 1);
	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(30, 2);
		glVertex2f(30, 20);
		glVertex2f(40, 20);
		glVertex2f(40, 2);
	glEnd();
	glColor3f(1, 0.6, 0.1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(50, 40);
		glVertex2f(50, 2);
		glVertex2f(20, 2);
		glVertex2f(20, 40);
		glVertex2f(100, 40);
		glVertex2f(100, 2);
		glVertex2f(50, 2);
	glEnd();
	
	glColor3f(0.7, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(50, 40);
		glVertex2f(20, 40);
		glVertex2f(35, 60);
		glVertex2f(85, 60);
		glVertex2f(100, 40);
		glVertex2f(50, 40);
		glVertex2f(35, 60);
		
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("House");

	glutDisplayFunc(display1);
	myinit();
	glutMainLoop();

}