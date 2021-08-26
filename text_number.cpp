//#27E-5M. Write a program to display text and numbers.

#include<stdio.h>
#include<string.h>
#include<gl/glut.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 1);
	char message[] = "Name : NAMRATHA.H.V ";
	char number[] = "USN : 1RN18CS067 ";
	glRasterPos2i(150, 260);
	for (int i = 0; i < strlen(number); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, number[i]);
	}
	glRasterPos2i(150, 300);
	for (int i = 0; i < strlen(message); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
	}

	glFlush();
}

void reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	myinit();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(150, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Text and Number");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}