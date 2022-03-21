#include <glut.h>
#include<iostream>
#include<GLU.H>
#include <math.h>
void tree() {
	glPushMatrix();
	glColor3f(1.0, 1.5, 0.0);
	glTranslatef(60, 10, -50);
	glScalef(4, 28, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(55, 27, -50);
	glScalef(2, 1, 1);
	glutSolidSphere(5, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(65, 27, -50);
	glScalef(2, 1, 1);
	glutSolidSphere(5, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(60, 33, -50);
	glScalef(2, 1, 1);
	glutSolidSphere(5, 20, 20);
	glPopMatrix();


}
//void circle(float x, float y, double r){
//	float x1, y1;
//	float pi, i;
//	glBegin(GL_POLYGON);
//
//	for (int i = 0; i < 200; i++){
//		float pi = 3.1416;
//		float A = (i * 2 * pi) / 25;
//		float x1 = x + (r - .07)*cos(A);
//		float y1 = y + ((r)*sin(A));
//		glVertex2f(x1, y1);
//		glVertex2f(x1, y1);
//	}
//
//	glEnd();


//void drawcircle(float x, float y, double r){
//	float x1, y1;
//	float pi, i;
//	glBegin(GL_POLYGON);
//
//	for (int i = 0; i < 200; i++){
//		float pi = 3.1416;
//		float A = (i * 2 * pi) / 25;
//		float x1 = x + (r - .09)*cos(A);
//		float y1 = y + ((r)*sin(A));
//		glVertex2f(x1, y1);
//		glPushMatrix();
//		glColor3f(0, 1, 0);
//		glTranslatef(10, 9.0, 0);
//		glPopMatrix();
//		glPushMatrix();
//		glColor3f(0, 1, 0);
//		glTranslatef(13, 9.0, 0);
//		glPopMatrix();
//
//
//	}
//
//	glEnd();


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
	//mountians


	glPushMatrix();
	glTranslatef(10, 0, 0);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.4, 0.1);
	glVertex3f(0.0f, 7.8f, 0.0f);
	glVertex3f(100.0f, -40.0f, -10.0f);
	glVertex3f(-100.0f, -40.0f, -10.0f);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(20, 0, 0);
	glBegin(GL_TRIANGLES);//تاني واحد عاليمين
	glColor3f(0.0, 0.4, 0.1);
	glVertex3f(0.0f, 7.8f, 0.0f);
	glVertex3f(65.0f, -40.0f, -10.0f);
	glVertex3f(-65.0f, -40.0f, -10.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(33, 0, 0);
	glBegin(GL_TRIANGLES);//اخر واحدعاليمين
	glColor3f(1.0, 0.0, 0.0);
	glColor3f(0.0f, 0.4f, 0.1f);		// ??? ????
	glVertex3f(0.0f, 7.5f, 0.0f);		//  ?????? ??????? ?? ??????- ??????? ???????? ?????
	glVertex3f(53.0f, -38.0f, -10.0f);	//  ?????? ???????? ?? ??????- ??????? ???????? ?????
	glVertex3f(-53.0f, -38.0f, -10.0f);


	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-77, -6, -162);
	glScalef(1, 10, 1);
	glutSolidCube(1.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6, 0, 0);
	glBegin(GL_TRIANGLES);// الاخير من اليسار 
	glColor3f(0.0f, 0.4f, 0.1f);
	glVertex3f(0.0f, 7.8f, 0.0f);
	glVertex3f(60.0f, -40.0f, -10.0f);
	glVertex3f(-60.0f, -40.0f, -10.0f);
	glEnd();
	glPopMatrix();

	//boat
	glPushMatrix();
	glTranslatef(19, -6, 0);
	glColor3f(0, 0, 3);
	glBegin(GL_QUADS);
	glVertex2f(1, -7);
	glVertex2f(-1, -7);
	glVertex2f(-3, -5);
	glVertex2f(3, -5);
	glEnd();


	glPopMatrix();

	//
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
	glTranslatef(19, -11, 0);
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(2, 0);
	glVertex2f(2, 2);
	glVertex2f(0.2, 0);
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
	glColor3f(0.0, 1.0, 1.1);
	glVertex2f(2, 1.5);
	glVertex2f(2.5, 2);
	glVertex2f(2, 2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19, -11, 0);
	glBegin(GL_TRIANGLES);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(2, 1.5);
	glVertex2f(2.5, 2);
	glVertex2f(2, 2);
	glEnd();
	glPopMatrix();






	//cloud1
	/*glPushMatrix();
	glTranslatef(-2, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.80, 0.8, 1.2);
	circle(2.9, 7.5, 1.4);
	circle(1.9, 8.3, 1.4);
	circle(3.9, 8.8, 1.4);
	circle(4.9, 9.4, 1.4);
	circle(2.9, 7.5, 1.4);
	circle(1.9, 8.3, 1.4);
	circle(3.9, 8.8, 1.4);
	circle(4.9, 9.4, 1.4);

	glEnd();
	glPopMatrix();
	*/

	////cloud1
	//glPushMatrix();
	//glTranslatef(22, 0, 0);
	//glBegin(GL_POLYGON);
	//glColor3f(0.80, 0.8, 0.9);
	//circle(2.7, 7.2, 1.3);
	//circle(1.7, 7.5, 1.3);
	//circle(3.7, 8, 1.3);
	//circle(4.7, 8.5, 1.3);
	//circle(2.7, 7.2, 1.3);
	//circle(1.7, 7.5, 1.3);
	//circle(3.7, 8, 1.3);
	//circle(4.7, 8.5, 1.3);
	//glEnd();
	//glPopMatrix();

	/*glPushMatrix();
	glTranslatef(13, 2, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.80, 0.8, 0.9);
	circle(2.7, 7.2, 1.3);
	circle(1.7, 7.5, 1.3);
	circle(3.7, 8, 1.3);
	circle(4.7, 8.5, 1.3);
	circle(2.7, 7.2, 1.3);
	circle(1.7, 7.5, 1.3);
	circle(3.7, 8, 1.3);
	circle(4.7, 8.5, 1.3);
	glEnd();
	glPopMatrix();
	*/
	//revier


	////tree

	/*drawcircle(0.9, 0.9, 0.9);
	drawcircle(2, 2, 2);*/


	glPushMatrix();
	glTranslatef(8, 0, 0);
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
	glPopMatrix();



	glPushMatrix();
	glTranslatef(3, -2, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.70, 0.39, 0.35);
	glVertex2f(0.5, 3);
	glVertex2f(1.5, 4.6);
	glVertex2f(1, 4.8);
	glVertex2f(0, 3.5);
	glVertex2f(-1, 4.8);
	glVertex2f(-1.5, 4.6);
	glVertex2f(-0.5, 3);
	glVertex2f(-0.5, -2);
	glVertex2f(0, -2.4);
	glVertex2f(0.5, -2);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-9.5, -2, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.70, 0.39, 0.35);
	glVertex2f(0.5, 3);
	glVertex2f(1.5, 4.6);
	glVertex2f(1, 4.8);
	glVertex2f(0, 3.5);
	glVertex2f(-1, 4.8);
	glVertex2f(-1.5, 4.6);
	glVertex2f(-0.5, 3);
	glVertex2f(-0.5, -2);
	glVertex2f(0, -2.4);
	glVertex2f(0.5, -2);

	glEnd();
	glPopMatrix();








	/*glPushMatrix();
	glTranslatef(10, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.80, 0.8, 0.9);
	glVertex2f(1.5, 3.3);
	glVertex2f(1, 3.5);

	glVertex2f(0, 3.1);
	glVertex2f(-1, 3.5);
	glVertex2f(-1.5, 3.3);
	glEnd();
	glPopMatrix();*/








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
	init();
	glutDisplayFunc(DrawAllComponents);
	glutMainLoop();
	return 0;
}