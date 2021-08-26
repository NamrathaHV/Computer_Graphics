// 8L. Develop a menu driven program to animate a flag using Bezier Curve algorithm.

#include<gl/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1416
GLsizei winwidth = 600, winheight = 600;
GLfloat xwcMin = 0.0, xwcMax = 130.0;
GLfloat ywcMin = 0.0, ywcMax = 130.0;
typedef struct wcPt3D
{
	GLfloat x, y, z;
};
void bino(GLint n, GLint* C)
{
	GLint k, j;
	for (k = 0; k <= n; k++)
	{
		C[k] = 1;
		for (j = n; j >= k + 1; j--)
			C[k] *= j;
		for (j = n - k; j >= 2; j--)
			C[k] /= j;
	}
}
void computeBezPt(GLfloat u, wcPt3D* bezPt, GLint nCtrlPts, wcPt3D* ctrlPts, GLint* C)
{
	GLint k, n = nCtrlPts - 1;
	GLfloat bezBlendFcn;
	bezPt->x = bezPt->y = bezPt->z = 0.0;
	for (k = 0; k < nCtrlPts; k++)
	{
		bezBlendFcn = C[k] * pow(u, k) * pow(1 - u, n - k);
		bezPt->x += ctrlPts[k].x * bezBlendFcn;
		bezPt->y += ctrlPts[k].y * bezBlendFcn;
		bezPt->z += ctrlPts[k].z * bezBlendFcn;
	}
}
void beizer(wcPt3D* ctrlPts, GLint nCtrlPts, GLint nBezCurvePts)
{
	wcPt3D bezCurvePt;
	GLfloat u;
	GLint *C, k;
	C = new GLint[nCtrlPts];
	bino(nCtrlPts - 1, C);
	glBegin(GL_LINE_STRIP);
	for (k = 0; k <= nBezCurvePts; k++)
	{
		u = GLfloat(k) / GLfloat(nBezCurvePts);
		computeBezPt(u, &bezCurvePt, nCtrlPts, ctrlPts, C);
		glVertex2f(bezCurvePt.x, bezCurvePt.y);
	}
	glEnd();
	delete[]C;
}
void displayFcn()
{
	GLint nCtrlPts = 4, nBezCurvePts = 20;
	static float theta = 0;
	wcPt3D ctrlPts[4] = { {20,100,0},{30,110,0},{50,90,0},{60,100,0} };
	ctrlPts[1].x += 10 * sin(theta * PI / 180.0);
	ctrlPts[1].y += 5 * sin(theta * PI / 180.0);
	ctrlPts[2].x -= 10 * sin((theta + 30) * PI / 180.0);
	ctrlPts[2].y -= 10 * sin((theta + 30) * PI / 180.0);
	ctrlPts[3].x -= 4 * sin(theta * PI / 180.0);
	ctrlPts[3].y += sin((theta - 30) * PI / 180.0);
	theta += 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glPushMatrix();
	glLineWidth(5);
	for (int i = 0; i < 24; i++)
	{
		glTranslatef(0, -0.8, 0);
		beizer(ctrlPts, nCtrlPts, nBezCurvePts);
	}
	glPopMatrix();
	glLineWidth(5);
	glBegin(GL_LINES);
		glVertex2f(20, 100);
		glVertex2f(20, 40);
	glEnd();
	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}
void winReshapeFun(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);
	glClear(GL_COLOR_BUFFER_BIT);
}
void d_menu(int op)
{
	if (op == 1)
		glColor3f(1.0, 0.0, 0.0);
	else if (op == 2)
		glColor3f(0.0, 1.0, 0.0);
	else if (op == 3)
		glColor3f(0.0, 0.0, 1.0);
	else if (op == 4)
		exit(0);
	glutPostRedisplay();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(winwidth, winheight);
	glutCreateWindow("Bezier Curve");
	glutCreateMenu(d_menu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Quit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(displayFcn);
	glutReshapeFunc(winReshapeFun);
	glutMainLoop();
}