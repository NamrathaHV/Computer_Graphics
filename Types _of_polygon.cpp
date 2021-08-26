/* #8E-2M. Write a program to draw geometric shapes using OpenGL geometric primitives
	a). GL_LINES     b). GL_LINESTRIP    c). GL_LINELOOPS
	d). GL_TRIANGLES e). GL_TRIANGLE_FAN f). GL_TRIANGLE_STRIP
	g). GL_SQUARE    h). GL_QUADS        i). GL_QUAD_STRIP */

#include <GL/glut.h>
#include<iostream>
using namespace std;
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex2f(100, 150);
		glVertex2f(100, 400);
		glVertex2f(100, 150);
		glVertex2f(180, 200);
		glVertex2f(180, 200);
		glVertex2f(180, 350);
		glVertex2f(100, 400);
		glVertex2f(180, 350);
	glEnd();
	glFlush();
}
void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(100, 400);
		glVertex2f(100, 150);
		glVertex2f(180, 200);
		glVertex2f(180, 350);
		glVertex2f(100, 400);
	glEnd();
	glFlush();
}
void display3(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(100, 400);
		glVertex2f(100, 150);
		glVertex2f(180, 200);
		glVertex2f(180, 350);
	glEnd();
	glFlush();
}
void display4(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		//red
		glVertex2f(150.0, 150.0);
		//Green
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(150.0, 450.0);
		//Blue
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(300.0, 450.0);
		glVertex2f(50.0, 50.0);
		glVertex2f(150.0, 50.0);
		glVertex2f(100.0, 200.0);
	glEnd();
	glFlush();
}
void display5(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(150.0, 150.0);

		glColor3f(0.50, 0.80, 0.20);
		glVertex2f(300.0, 50.0);

		glColor3f(0.20, 0.10, 0.60);
		glVertex2f(300.0, 150.0);

		glColor3f(0.70, 0.20, 0.50);
		glVertex2f(300.0, 250.0);

		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(300.0, 350.0);
	glEnd();
	glFlush();
}
void display6(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(250.0, 150.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(200.0, 250.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(250.0, 250.0);

		glColor3f(0.50, 0.80, 0.20);
		glVertex2f(300.0, 150.0);

		glColor3f(0.20, 0.10, 0.60);
		glVertex2f(250.0, 0.0);

		glColor3f(0.70, 0.20, 0.50);
		glVertex2f(200.0, 100.0);
	glEnd();
	glFlush();
}
void display7(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex2f(150.0, 150.0);
		
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(450.0, 150.0);
		
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(450.0, 450.0);

		glColor3f(0.20, 0.10, 0.60);
		glVertex2f(150.0, 450.0);
	glEnd();
	glFlush();
}
void display8(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(250.0, 50.0);
		
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(100.0, 250.0);
		
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(250.0, 250.0);
		
		glColor3f(0.50, 0.80, 0.20);
		glVertex2f(400.0, 50.0);
	glEnd();
	glFlush();
}

void display9(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUAD_STRIP);
		glVertex2f(250.0, 50.0);
		glVertex2f(100.0, 250.0);
		glVertex2f(400.0, 50.0);
		glVertex2f(250.0, 250.0); 

		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(500.0, 50.0);
		glVertex2f(370.0, 250.0);
	glEnd();
	glFlush();
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Polygons");
	glViewport(0, 500, 0, 500);
	init();
	int ch;
	//while (1) {
		cout << "1. GL_LINES \n2. GL_LINE_STRIP\n3. GL_LINE_LOOP\n4. GL_TRIANGLES\n5. GL_TRIANGLE_FAN\n6. GL_TRIANGLE_STRIP\n7. GL_SQUARE\n8. GL_QUADS\n9. GL_QUAD_STRIP\n" << endl;
		cin >> ch;
		switch (ch)
		{

			case 1:glutDisplayFunc(display1);
				break;
			case 2:glutDisplayFunc(display2);
				break;
			case 3:glutDisplayFunc(display3);
				break;
			case 4:glutDisplayFunc(display4);
				break;
			case 5:glutDisplayFunc(display5);
				break;
			case 6:glutDisplayFunc(display6);
				break;
			case 7:glutDisplayFunc(display7);
				break;
			case 8:glutDisplayFunc(display8);
				break;
			case 9:glutDisplayFunc(display9);
				break;
			default:cout << "Invalid" << endl;
				//exit(0);
				break;
		}
		//glutMainLoop();
	//}
	glutMainLoop();
}
