#include<stdio.h>
#include<GL/glut.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

void drawPolygon()
{
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(20, 20);
	glVertex2f(80, 80);
	glVertex2f(100, 20);

	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(180, 25);
	glColor3f(0, 1, 0);
	glVertex2f(140, 90);
	glEnd();
	glFlush();

}
void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	drawPolygon();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Traingle rotation");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}