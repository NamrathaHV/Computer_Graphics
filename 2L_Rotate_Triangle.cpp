// #2L. Create and rotate a triangle about the origin and a fixed point.

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
double point[3][2] = { {30,30},{55,55},{80,30} };
double xp, yp, theta, rtheta;
void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}
void triangle() {
	glBegin(GL_TRIANGLES);
		glVertex2dv(point[0]);
		glVertex2dv(point[1]);
		glVertex2dv(point[2]);
	glEnd();
}
void display() {
	double x, y;
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0, 0.5);
	triangle();
	rtheta = (theta * 3.142) / 180;
	for (int i = 0; i < 3; i++) {
		x = point[i][0];
		y = point[i][1];
		point[i][0] = xp + (x - xp) * cos(rtheta) - (y - yp) * sin(rtheta);
		point[i][1] = yp + (x - xp) * sin(rtheta) + (y - yp) * cos(rtheta);
	}
	glColor3f(0, 1, 1);
	triangle();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Triangle Rotation");
	printf("Enter Reference Point x-coordinate\n");
	scanf_s("%lf", &xp);
	printf("Enter Reference Point y-coordinate\n");
	scanf_s("%lf", &yp);
	printf("Enter Rotation Angle\n");
	scanf_s("%lf", &theta);
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}