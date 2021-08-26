//3E-1M. Write a program to draw circle using points.

#include<stdio.h>
#include <math.h> // for the "abs" function
#include <GL/glut.h> // include the OpenGL library
GLdouble R, Xc, Yc; // the Radius and the center point

//setup the windows parameters
void Init()
{
	glClearColor(1.0, 1.0, 1.0, 0); // set the background color (white)
	glColor3f(0.0, 0.0, 0.0); // set the foreground color (black)
	glViewport(0, 0, 640, 480); // set the viowport dimensions (all the window)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480); // set the window dimension (640x480)
}

// draw a circle using the direct method
void CircleDirect(void)
{
	GLdouble x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2);
	glBegin(GL_POINTS);
	for (x = -R; x <= R; x++)
	{
		y = sqrt(R * R - (x * x));
		glVertex2i(Xc + x, Yc + y); // The upper half
		glVertex2i(Xc + x, Yc - y); // the lower half
	}
	glEnd();
	glFlush();
}

//The main function
void main(int argc, char** argv)
{
	//Read the circle radius and the center
	printf("Enter the Radius R: \n");
	scanf_s("%lf", &R);
	printf("Enter the mid points: \n");
	scanf_s("%lf%lf", &Xc, &Yc);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("A Circle with a direct method");
	Init();
	glutDisplayFunc(CircleDirect);
	glutMainLoop();
}