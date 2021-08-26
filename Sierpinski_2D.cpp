/*#23E-M4. Write a program to recursively subdivide a triangle to form 2D
sierpinski gasket.The number of recursive steps is to be specified by the user.*/


#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
int n;
float v[3][2] = { {-25,-25},{0,25},{25,-25} };
void myinit()
{
	glMatrixMode(GL_PROJECTION);	//Specifies current matrix for geometric-viewing transformations
	glLoadIdentity();		//Sets current matrix to identity.
	gluOrtho2D(-50, 50, -50, 50);	//Specifies parameters for a clipping window and the near and far clipping planes 
	glMatrixMode(GL_MODELVIEW);
}
void triangle(float v0[2], float v1[2], float v2[2])
{
	glBegin(GL_POLYGON);
	glVertex2fv(v0);
	glVertex2fv(v1);
	glVertex2fv(v2);
	glEnd();
}
void divide_triangle(float v0[2], float v1[2], float v2[2], int n)
{
	float a[2], b[2], c[2];
	int j;
	if (n > 0)
	{
		for (j = 0; j < 2; j++)
		{
			a[j] = (v0[j] + v1[j]) / 2;
			b[j] = (v1[j] + v2[j]) / 2;
			c[j] = (v0[j] + v2[j]) / 2;
		}
		divide_triangle(v0, a, c, n - 1);
		divide_triangle(a, v1, b, n - 1);
		divide_triangle(b, c, v2, n - 1);
	}
	else
		triangle(v0, v1, v2);
}
void display()
{

	glClearColor(1, 1, 1, 1);		//Specifies a background RGB color for a display window.
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window.
	glColor3f(1, 0, 0);		//Set current color to red
	divide_triangle(v[0], v[1], v[2], n);
	glFlush();			// Process all OpenGL routines as quickly as possible.
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);// sets buffering and color mode for a display window
	glutInitWindowPosition(100, 100);	    //Specifies coordinates for the top-left corner of a display window.
	glutInitWindowSize(500, 500);		    //Specifies width and height for a display window.
	glutCreateWindow("2D SIERPINSKI PATTERN");  //Creates a display window & specify a display-window title
	printf("Enter the value of n: ");
	scanf_s("%d", &n);
	myinit();				   // Execute initialization procedure.
	glutDisplayFunc(display);		   //Invokes a function to create a picture within the current display window.
	glutMainLoop();				   //Executes the computer-graphics program.

}