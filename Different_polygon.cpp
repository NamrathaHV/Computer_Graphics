#include<stdio.h>
#include<GL/glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}
/*   FIRST ONE   */

void disp1()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(100, 100);
	glVertex2f(150, 150);
	glVertex2f(275, 150);
	glVertex2f(220, 90);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("QUADRILATERAL");
	myinit();
	glutDisplayFunc(disp1);
	glutMainLoop();
}

/*    SECOND ONE   */

/*void disp1()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	glVertex2f(100, 100);
	glVertex2f(150, 150);
	glColor3f(0, 1, 0);
	glVertex2f(275, 150);
	glColor3f(0, 0, 1);
	glVertex2f(325, 100);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("SHADED POLYGON");
	myinit();
	glutDisplayFunc(disp1);
	glutMainLoop();
}*/


/*  THIRD    */


/*void disp1()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	glVertex2f(100, 100);
	glVertex2f(150, 150);
	glColor3f(0, 1, 0);
	glVertex2f(275, 150);
	glColor3f(0, 0, 1);
	glVertex2f(325, 100);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("MULTICOLORED LINES OF POLYGON");
	myinit();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_LINE_STIPPLE);
	glutDisplayFunc(disp1);
	glutMainLoop();
}*/



/*   FOURTH   */

/*void disp1()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//glLineWidth(4);                    // USE THIS TO SEE THE LINES BETTER  (GL_LINE)
	//glPointSize(4);                    // USE THIS TO SEE THE POINTS BETTER  (GL_POINT)
	glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	glVertex2f(100, 100);
	glVertex2f(150, 150);
	glVertex2f(275, 150);
	glVertex2f(325, 100);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("POLYGON MADE UP OF DIFFERENT LINES AND POINTS");
	myinit();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//     ONLY UNCOMMENT IF USING GL_LINE

	// glEnable(GL_LINE_STIPPLE);

	//glLineStipple(1, 0x0101);      // dotted
	//glLineStipple(1, 0x00FF);      // dashed
	//glLineStipple(1, 0x1C47);      // dash/dot/dash

	glutDisplayFunc(disp1);
	glutMainLoop();
}*/