//#5E-1M. Program to draw the lines using DDA line drawing algorithm.
#include<iostream>
#include<gl/glut.h>
#include<math.h>
using namespace std;
int xx, yy, xend, yend;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	//glMatrixMode(GL_MODELVIEW);
}

void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	glFlush();
}

void DDA()
{
	float x, y, dx, dy, steps;
	dx = (float)(xend - xx);
	dy = (float)(yend - yy);

	if (dx >= dy)
		steps = dx;
	else
		steps = dy;

	dx = dx / steps;
	dy = dy / steps;
	x = xx;
	y = yy;

	glColor3f(1, 0, 0);
	glPointSize(2);

	int i = 0;
	while (i < steps)
	{
		setPixel(x, y);
		x += dx;
		y += dy;
		i = i + 1;
	}
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	DDA();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 75);
	glutCreateWindow("DDA Lines");
	myinit();
	cout << "Enter coordinates of first position: ";
	cin >> xx >> yy;

	cout << "Enter coordinates of second position: ";
	cin >> xend >> yend;

	glutDisplayFunc(display);
	glutMainLoop();

}