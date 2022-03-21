#include <glut.h>
#include<iostream>
#include<GLU.H>
#include <math.h>

void circle(float x, float y, double r){
	float x1, y1;
	float pi, i;
	glBegin(GL_POLYGON);

	for (int i = 0; i < 200; i++){
		float pi = 3.1416;
		float A = (i * 2 * pi) / 25;
		float x1 = x + (r - .07)*cos(A);
		float y1 = y + ((r)*sin(A));
		glVertex2f(x1, y1);
		glVertex2f(x1, y1);
	}
	glEnd();
}

void buildfish(){

}
void drawcircle(float x, float y, double r){
	float x1, y1;
	float pi, i;
	glBegin(GL_POLYGON);

	for (int i = 0; i < 200; i++){
		float pi = 3.1416;
		float A = (i * 2 * pi) / 25;
		float x1 = x + (r - .09)*cos(A);
		float y1 = y + ((r)*sin(A));
		glVertex2f(x1, y1);
		glPushMatrix();
		glColor3f(0, 1, 0);
		glTranslatef(10, 9.0, 0);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 1, 0);
		glTranslatef(13, 9.0, 0);
		glPopMatrix();


	}

	glEnd();
}

void buildhouse(float x, float y, float z){
	glPushMatrix();
	glTranslated(0, 0, 0);
	glTranslatef(x, y, z);
	glPushMatrix();
	glBegin(GL_POLYGON);//                           السطح1
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3d(40, 40, 0);
	glVertex3d(8, 40, 0);
	glVertex3d(22, 20, 0);
	glVertex3d(50, 20, 0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glBegin(GL_POLYGON);//                          تكملة السطح1
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3d(13, 40, 0);
	glVertex3d(8, 40, 0);
	glVertex3d(-6, 20, 0);
	glVertex3d(-2, 20, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(2, 2);
	glVertex2i(6, 2);
	glVertex2i(7, 0);
	glVertex2i(3, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.0, 0.0);

	// Top of Front Wall
	glColor3f(0.1, 0.5, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2i(2, 2);
	glVertex2i(1, 0.5);
	glVertex2i(3, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	// Front Wall
	glColor3f(0.7, 0.2, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(1, 0.5);
	glVertex2i(3, 0.5);
	glVertex2i(3, -2);
	glVertex2i(1, -2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.2, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(3, 0.5);
	glVertex2i(7, 0.5);
	glVertex2i(7, -2);
	glVertex2i(3, -2);
	glEnd();

	glPushMatrix();
	glTranslatef(6, 2, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);//     درفات الباب                     
	glColor3f(0, 0.0f, 0.0f);
	glVertex2f(0.0,-4);
	glVertex2f(0,-2);
	glVertex2f(-1.5,-2);
	glVertex2f(-1.5,-4);
	
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glPushMatrix();
	glBegin(GL_POLYGON);//     درفات الباب                     
	glColor3f(0.8, 0.0f, 0.0f);
	glVertex2f(0.0, -4.0);
	glVertex2f(0, -2);
	glVertex2f(-0.8, -2.3);
	glVertex2f(-0.8, -4.0);

	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glBegin(GL_POLYGON);//     درفات الباب                     
	glColor3f(0.8, 0.0f, 0.0f);
	glVertex2f(-1, -4.0);
	glVertex2f(-1, -2.3);
	glVertex2f(-1.5, -2);
	glVertex2f(-1.5, -4);

	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslated(7, 0.5, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);//                           الحافة تحت البيت
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-4, -2.3);
	glVertex2f(0.05, -2.3);
	glVertex2f(0, -2.7);
	glVertex2f(-3.95, -2.7);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3.35, -3.9, 0);
	glRotatef(178, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);//                          تكملة الحافة تحت البيت
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(0.75, -1.1);
	glVertex2f(2.75, -1.1);
	glVertex2f(2.7, -1.5);
	glVertex2f(0.7, -1.5);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void buildcloude(float x, float y, float z){
	glPushMatrix();
	glTranslatef(x, y, z);
	glBegin(GL_POLYGON);
	glColor3f(0.80, 0.8, 1.2);
	circle(2.9, 7.5, 1.2);
	circle(1.7, 6.5, 1.3);
	circle(3.9, 6.5, 1.3);
	circle(1.7, 8.5, 1.3);
	circle(3.9, 8.5, 1.3);
	circle(5.3, 7.5, 1.2);
	circle(0.1, 7.5, 1.2);

	glEnd();
	glPopMatrix();
}
void buildmountins(float x, float y, float z, float v){
	glPushMatrix();
	glTranslatef(x, y, z);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.4, 0.1);
	glVertex3f(0.0f, 7.8f, 0.0f);
	glVertex3f(v, -40.0f, -10.0f);
	glVertex3f(-v, -40.0f, -10.0f);
	glEnd();
	glPopMatrix();
}
void buildbot(float x, float y, float z){
	glPushMatrix();
	glTranslated(x, y, z);
	glPushMatrix();
	glTranslatef(6, -9, 0);
	glColor3f(0, 0, 3);
	glBegin(GL_QUADS);
	glVertex2f(1, -7);
	glVertex2f(-1, -7);
	glVertex2f(-3, -5);
	glVertex2f(3, -5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -14, 0);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(2, 0);
	glVertex2f(2, 2);
	glVertex2f(0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -14, 0);
	glBegin(GL_TRIANGLES);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(2, 1.5);
	glVertex2f(2.5, 2);
	glVertex2f(2, 2);
	glEnd();
	glPopMatrix();
	glPopMatrix();
}
void buildtree(float x, float y, float z){
	glPushMatrix();
	glTranslatef(x, y, z);
	glBegin(GL_POLYGON);
	glColor3f(0.70, 0.39, 0.35);
	glVertex2f(0.5, 3);
	glVertex2f(1.5, 4.2);
	glVertex2f(1, 4.4);
	glVertex2f(0, 3.5);
	glVertex2f(-1, 4.4);
	glVertex2f(-1.5, 4.2);
	glVertex2f(-0.5, 3);
	glVertex2f(-0.5, -2);
	glVertex2f(0, -2.4);
	glVertex2f(0.5, -2);
	glEnd();
	glTranslatef(-4.1, -2.5, 0);
	glBegin(GL_POLYGON);
	glColor3f(0, 0.8, 0.2);
	circle(1.55, 7.4, 1.5);
	circle(6.55, 7.4, 1.5);
	circle(4, 8, 1.5);
	circle(3, 9.7, 1.5);
	circle(5, 9.7, 1.5);
	circle(4.4, 9.1, 1.5);
	circle(4.4, 9.1, 1.5);
	glEnd();
	glPopMatrix();
}
void DrawAllComponents()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(-12, 38, -19, 14);//range
	glMatrixMode(GL_MODELVIEW);
	///sky///
	glBegin(GL_POLYGON);
	glVertex2f(38.0f, 3.0f);
	glColor3f(0, 0, 1);
	glVertex2f(38.0f, 14.0f);
	glVertex2f(-12.0f, 14.0f);
	glVertex2f(-12.0f, 3.0f);
	glEnd();
	/////////////////////////////
	///sun////
	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslatef(31, 9.0, 0);
	glutSolidSphere(1.0, 150, 150);//Draw first Circle 
	glPopMatrix();
	glColor3f(1, 1, 0);
	//glutSolidSphere(1.0, 150, 150);//Draw second Circle
	/////////////////////////////////////////


	//ground
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.7, 0.1);
	glVertex2f(-60.8, -61.3);
	glVertex2f(-60.8, 3.0);
	glVertex2f(60.9, 3.0);
	glVertex2f(60.9, -61.3);
	glEnd();
	/////////////////////////////////
	//revier
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.6);
	glVertex2f(-60.0, -61.5);
	glVertex2f(-60.0, -7.2);
	glVertex2f(60.0, -7.2);
	glVertex2f(60.0, -61.5);
	glEnd();
	/////////////////////////////
	//Riverbank ground
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.8f, 0.6f);
	glVertex2f(-60.0, -7.5);
	glVertex2f(-60.0, -4.6);
	glVertex2f(60.0, -4.6);
	glVertex2f(60.0, -7.5);
	glEnd();
	//Riverbank 1
	glBegin(GL_POLYGON);
	glColor3f(0.33, 0.33, 0.33);
	glVertex2f(-60.0, -5.4);
	glVertex2f(-60.0, -4.6);
	glVertex2f(60.0, -4.6);
	glVertex2f(60.0, -5.4);
	glEnd();
	//Riverbank 2
	glBegin(GL_POLYGON);
	glColor3f(0.33, 0.33, 0.33);
	glVertex2f(-60.1, -6.4);
	glVertex2f(-60.1, -5.5);
	glVertex2f(60.6, -5.5);
	glVertex2f(60.6, -6.4);
	glEnd();
	//Riverbank 3
	glBegin(GL_POLYGON);
	glColor3f(0.33, 0.33, 0.33);
	glVertex2f(-60.0, -7.5);
	glVertex2f(-60.0, -6.5);
	glVertex2f(60.0, -6.5);
	glVertex2f(60.0, -7.5);
	glEnd();

	//////////////////////////////////////////
	//cloud

	//cloud1

	buildcloude(5, 2, 0);
	buildcloude(23, -1, 0);
	buildcloude(-5, 1, 0);


	//////////////////////////////////////////
	//mountians
	buildmountins(20, 0, 0, 65);
	buildmountins(10, 0, 0, 100);
	buildmountins(33, 0, 0, 53);
	buildmountins(-6, 0, 0, 60);



	///////////////////////////////////////////////////
	////tree
	buildtree(20, 0.0, 0.0);
	buildtree(3, -2, 0);
	buildtree(-7, 2, 0);
	////////////////////////////////////////////
	//house	
	buildhouse(5, 1, 0.0);
	buildhouse(-10, -2, 0.0);
	/////////////////////////////////////////////////
	//boat
	buildbot(10, 1, 0);
	buildbot(0, 0, 0);


	//////////////////////////////////////
	glutPostRedisplay();
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1300, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(" Graphics HomeWork ");


	glutDisplayFunc(DrawAllComponents);
	glutMainLoop();
	return 0;
}
