#include<Windows.h>
#include<gl.h>
#include<GLU.H>
#include<GLUT.h>
#include<GLAUX.H>
#include<math.h>
#pragma comment(lib,"glaux.lib")

static void display(void);
static void keyboard(unsigned char key, int x, int y);
float y = 0;
double sunMove = 0;
double TranslateCloud = 0;
double doorRotate = 0;
double zM = 0;
double kM = 0;
bool b = false;
bool sunM = false;
bool move = false;
bool cloudM = false;
bool door1 = false;
float i = 0;
float j = 0;
float r1 = 0;
float r2 = 0;
bool birdM = false;
bool bM = false;
bool OPEN_DOOR = false;
bool CLOSE_DOOR = false;
double ROT_DOOR = 0;


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Software Homework");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45, 1.0, 10.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0;
}

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

void sky(){
	glLoadIdentity();

	glPushMatrix();

	glTranslatef(0, 10, -100);
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(-90, 40);
	glColor3f(0, 0, 1);
	glVertex2f(-90, 0);
	glColor3f(1, 1, 1);
	glVertex2f(90, 0);
	glColor3f(0, 0, 1);
	glVertex2f(90, 40);
	glEnd();

	glPopMatrix();

}

void ground(){
	glLoadIdentity();

	glPushMatrix();
	glColor3f(0, 0.7, 0.2);
	glTranslatef(0, -20, -100);
	glBegin(GL_POLYGON);
	glVertex2f(-90, 30);
	glVertex2f(-90, 0);
	glVertex2f(90, 0);
	glVertex2f(90, 30);
	glEnd();
	glPopMatrix();
}
void sun()
{
	if (sunM || move){
		sunMove += 0.08;
		if (sunMove >= 250)
			sunMove = -100;
	}
	glLoadIdentity();
	glPushMatrix();
	//translate sun
	glTranslatef(sunMove, 0, 0);
	glTranslatef(45, 35, -150.0f);
	glColor3f(1, 1, 0);
	auxSolidSphere(4);
	glPopMatrix();
}
void mountains()
{
	glPushMatrix();
	glColor3f(0.2, 0.5, 0);

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-85, 20, -200);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(50, 0);
	glVertex2f(20, 20);
	glEnd();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-40, 20, -200);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(64, 0);
	glVertex2f(40, 22);
	glEnd();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0, 20, -200);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(64, 0);
	glVertex2f(40, 22);
	glEnd();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(60, 20, -200);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(30, 0);
	glVertex2f(15, 15);
	glEnd();
	glPopMatrix();

	glPopMatrix();

}
void cloud1()
{
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glPushMatrix();

	glTranslatef(18, 25, -100.0f);

	//translate cloud1


	if (cloudM || move)
	{
		TranslateCloud += 0.001;
		if (TranslateCloud > 400) TranslateCloud = -100;
		glTranslatef(TranslateCloud, 0, 0);
	}

	glPushMatrix();
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, -1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9, 0, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPopMatrix();



}
void cloud2()
{
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glPushMatrix();

	glTranslatef(6, 30, -100.0f);

	//translate cloud1


	if (cloudM || move)
	{
		TranslateCloud += 0.001;
		if (TranslateCloud > 400) TranslateCloud = -100;
		glTranslatef(TranslateCloud, 0, 0);
	}

	glPushMatrix();
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, -1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9, 0, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPopMatrix();
}
void cloud3()
{
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glPushMatrix();

	glTranslatef(-30, 30, -150.0f);



	glPushMatrix();
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, -1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -1, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9, 0, 0);
	auxSolidSphere(2);
	glPopMatrix();

	glPopMatrix();
}
void sea(){
	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.2, 0.6, 0.9);
	glTranslatef(0, -45, -100);
	glBegin(GL_POLYGON);
	glVertex2f(-90, 30);
	glVertex2f(-90, 0);
	glVertex2f(90, 0);
	glVertex2f(90, 30);
	glEnd();
	glPopMatrix();

}
void roadLines(){


	glLoadIdentity();
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, -34, -100);
	glBegin(GL_LINES);
	glVertex2f(-90, 20);
	glVertex2f(90, 20);
	glVertex2f(-90, 18);
	glVertex2f(90, 18);

	glEnd();
	glPopMatrix();
}
void road(){
	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, -20, -100);
	glBegin(GL_POLYGON);
	glVertex2f(-90, 10);
	glVertex2f(-90, 0);
	glVertex2f(90, 0);
	glVertex2f(90, 10);
	glEnd();
	glPopMatrix();
}

void z1(){
	glPushMatrix();

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(7, -30, -100);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(8, 0);
	glVertex2f(12, 5);
	glVertex2f(-4, 5);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(12, -25, -100);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(5, 0);
	glVertex2f(5, 5);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(17, -22, -100);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(0, 2);
	glVertex2f(2, 1);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}
void z2(){

	glPushMatrix();


	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(-35, -36, -100);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(8, 0);
	glVertex2f(12, 5);
	glVertex2f(-4, 5);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(-30, -31, -100);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(5, 0);
	glVertex2f(5, 5);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-25, -28, -100);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(0, 2);
	glVertex2f(2, 1);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}


void tree1(){

	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.2);
	glTranslatef(-37, -7, -100);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 12);
	glVertex2f(0, 12);
	glEnd();
	glPopMatrix();


	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.2);
	glTranslatef(-37, 3, -100);
	glRotatef(-20, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 7);
	glVertex2f(0, 7);
	glEnd();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.2);
	glTranslatef(-37, 3, -100);
	glRotatef(+20, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 7);
	glVertex2f(0, 7);
	glEnd();
	glPopMatrix();


	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-38.5, 11, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-37, 14, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-34, 13, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-32, 10, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();
}
void tree2(){

	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.2);
	glTranslatef(-15, -10, -100);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 12);
	glVertex2f(0, 12);
	glEnd();
	glPopMatrix();


	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.2);
	glTranslatef(-15, 2, -100);
	glRotatef(-20, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 7);
	glVertex2f(0, 7);
	glEnd();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.2);
	glTranslatef(-15, 2, -100);
	glRotatef(+20, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 7);
	glVertex2f(0, 7);
	glEnd();
	glPopMatrix();


	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-11, 10, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-14, 11, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-17, 12.5, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-19, 9, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();


}

void tree3(){

	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.2);
	glTranslatef(8, -10, -100);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 12);
	glVertex2f(0, 12);
	glEnd();
	glPopMatrix();


	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.2);
	glTranslatef(8, 2, -100);
	glRotatef(-20, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 7);
	glVertex2f(0, 7);
	glEnd();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glColor3f(0.7, 0.5, 0.2);
	glTranslatef(8, 2, -100);
	glRotatef(+20, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 7);
	glVertex2f(0, 7);
	glEnd();
	glPopMatrix();


	glLoadIdentity();
	glPushMatrix();
	glTranslatef(12, 10, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();


	glLoadIdentity();
	glPushMatrix();
	glTranslatef(9, 10.5, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(7, 12, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(5, 10, -100);
	glColor3f(0, 1, 0);
	glRotatef(0, 0, 0, 1);
	auxSolidSphere(2.5);
	glPopMatrix();


}

void H1(){

	if (OPEN_DOOR){
		if (ROT_DOOR <= 130){
			ROT_DOOR += 1;
		}
		else{ OPEN_DOOR = !OPEN_DOOR; }
	}
	if (CLOSE_DOOR){
		if (ROT_DOOR >= 0){
			ROT_DOOR -= 1;
		}
		else{ CLOSE_DOOR = !CLOSE_DOOR; }
	}

	glPushMatrix();

	glTranslatef(-12, -8, -120);
	glColor3f(0.9, 0.5, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(10, 10);
	glVertex2f(0, 10);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-12, -8, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(9, -1);
	glVertex2f(-1, -1);
	glEnd();
	glPopMatrix();


	glPushMatrix();

	glTranslatef(-12, 2, -120);
	glColor3f(0.9, 0.5, 0.9);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(5, 5);
	glEnd();
	glPopMatrix();


	glPushMatrix();

	glTranslatef(-8, -2, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(2, 0);
	glVertex2f(2, 3);
	glVertex2f(0, 3);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-2, -8, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.5, 0.8);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(10, 10);
	glVertex2f(0, 10);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-2, -8, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(11, -1);
	glVertex2f(-1, -1);
	glEnd();
	glPopMatrix();

	glPushMatrix();


	glTranslatef(1, -8, -120);
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(5, 0);
	glVertex2f(5, 7);
	glVertex2f(0, 7);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(1, -8, -120);
	glRotatef(ROT_DOOR, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(0, 7);
	glVertex2f(2.5, 5);
	glVertex2f(2.5, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(6, -8, -120);
	glRotatef(-ROT_DOOR, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(0, 7);
	glVertex2f(-2, 5);
	glVertex2f(-2, 0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-2, 2, -120);
	glBegin(GL_POLYGON);
	//glColor3f(0.8, 0.5, 0.8);
	glColor3f(1, 1, 1);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(5, 5);
	glVertex2f(-5, 5);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-2, 2, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(11, 0);
	glVertex2f(5, 5);
	glVertex2f(-5, 5);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-12, 2, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(-1, 0);
	glVertex2f(4, 5);
	glVertex2f(5.1, 5);

	glEnd();

	glPopMatrix();




}

void H2(){
	if (OPEN_DOOR){
		if (ROT_DOOR <= 130){
			ROT_DOOR += 1;
		}
		else{ OPEN_DOOR = !OPEN_DOOR; }
	}
	if (CLOSE_DOOR){
		if (ROT_DOOR >= 0){
			ROT_DOOR -= 1;
		}
		else{ CLOSE_DOOR = !CLOSE_DOOR; }
	}


	glPushMatrix();

	glTranslatef(-40, -8, -120);
	glColor3f(0.9, 0.5, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(10, 10);
	glVertex2f(0, 10);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-40, -8, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(9, -1);
	glVertex2f(-1, -1);
	glEnd();
	glPopMatrix();


	glPushMatrix();

	glTranslatef(-40, 2, -120);
	glColor3f(0.9, 0.5, 0.9);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(5, 5);
	glEnd();
	glPopMatrix();


	glPushMatrix();

	glTranslatef(-37, -2, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(2, 0);
	glVertex2f(2, 3);
	glVertex2f(0, 3);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-30, -8, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.5, 0.8);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(10, 10);
	glVertex2f(0, 10);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-30, -8, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(11, -1);
	glVertex2f(-1, -1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-27, -8, -120);
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(5, 0);
	glVertex2f(5, 7);
	glVertex2f(0, 7);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-27, -8, -120);
	glRotatef(ROT_DOOR, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(0, 7);
	glVertex2f(2.5, 5);
	glVertex2f(2.5, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();


	glTranslatef(-22, -8, -120);
	glRotatef(-ROT_DOOR, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(0, 7);
	glVertex2f(-2, 5);
	glVertex2f(-2, 0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-30, 2, -120);
	glBegin(GL_POLYGON);
	//glColor3f(0.8, 0.5, 0.8);
	glColor3f(1, 1, 1);
	glVertex2f(0, 0);
	glVertex2f(10, 0);
	glVertex2f(5, 5);
	glVertex2f(-5, 5);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-30, 2, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(11, 0);
	glVertex2f(5, 5);
	glVertex2f(-5, 5);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-40, 2, -120);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.1, 0.1);
	glVertex2f(0, 0);
	glVertex2f(-1, 0);
	glVertex2f(4, 5);
	glVertex2f(5.1, 5);

	glEnd();

	glPopMatrix();




}
void bird(){

	glPushMatrix();
	glColor3f(0, 0, 0);

	r1 = r1 + r2;
	if (r1 >= 60)
		r2 = -0.5;
	if (r1 <= 0)
		r2 = 0.5;
	if (birdM || move)
	{
		if (i >= 25)
			bM = false;
		if (i <= -10)
			bM = true;
		if (bM)
			i = i + 0.01;
		else
			i = i - 0.01;

		glTranslatef(i, 0, 0);
	}


	glTranslatef(30, 20, -150);


	glPointSize(10);
	glLineWidth(4);

	glPushMatrix();
	glBegin(GL_POINTS);
	glVertex2f(0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-r1, 0, 0, 1);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0, 0);
	glVertex2f(5, 5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(r1, 0, 0, 1);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0, 0);
	glVertex2f(-5, 5);
	glEnd();
	glPopMatrix();

	glPopMatrix();

}

void buildfish(){
	glPushMatrix();

	if (zM || move){

		if (zM >= 10||kM<=-5)
			b = true;
		if (zM <= -10|| kM>=5)
			b = false;
		if (b){
			//for (int i = 0; i < 200; i++){
				zM -= 0.01;
				kM += 0.01;
			
		}
		else{
			//for (int i= 0; i < 300; i++){
				zM += 0.01;
				kM -= 0.01;
			
		}
		glRotatef(5,zM,kM, 0);

	}


	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(15, -30, -100);
	glBegin(GL_TRIANGLES);
	glVertex2f(14, 0);
	glVertex2f(8, 0);
	glVertex2f(12, 5);
	//glVertex2f(-4, 5);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(20, -30, -100);
	glBegin(GL_POLYGON);
	glutSolidSphere(5.0, 150, 150);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(3, -34, -100);
	glBegin(GL_TRIANGLES);
	glVertex2f(14, 0);
	glVertex2f(8, 0);
	glVertex2f(12, 5);
	//glVertex2f(-4, 5);
	glEnd();
/*

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(12, -25, -100);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(5, 0);
	glVertex2f(5, 5);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(17, -22, -100);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(0, 2);
	glVertex2f(2, 1);
	glEnd();
	glPopMatrix();*/

	glPopMatrix();
}
void display(){
	glClearColor(0.0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sky();
	sun();
	cloud1();
	cloud2();
	cloud3();
	ground();
	mountains();
	sea();
	road();
	roadLines();

	tree1();
	tree2();
	tree3();
	//huose1();
	//huose2();
	//bird();
	H1();
	H2();
	//z1();
	z2();
	buildfish();
	glutPostRedisplay();
	glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 's':move = true; break;
	case '1':sunM = true; break;
	case '2':cloudM = true; break;
	case '3':birdM = true; break;
	case '4':zM = true; break;
	case 'd':OPEN_DOOR = !OPEN_DOOR; break;
	case 'c':CLOSE_DOOR = !CLOSE_DOOR; break;
	case 'e':move = false; sunM = false; cloudM = false; door1 = false; zM = false; birdM = false; break;



	default:break;
	}


}