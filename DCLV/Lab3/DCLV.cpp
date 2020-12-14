// Dinh Duc Tuan
//1713775

#include "stdafx.h"

#include <iostream>
#include <windows.h>
#include <gl.h>
#include <glut.h>
#include <math.h>
#include "supportClass.h"
#include "Mesh.h"

using namespace std;

#define PI		3.1415926

int		screenWidth = 900;
int		screenHeight = 700;

bool	bWireFrame = false;

bool	camView = false;
bool	lightEnable = false;
bool	lookat;
float	camX = -7.0;
float	camY = 6.0;
float	camZ = 7.0;
float	cam_dis=10;
float	camXFirstView = camX;
float	camYFirstView = camY;
float	camZFirstView = camZ;

float	Rxz = sqrt(camX*camX + camZ*camZ);
float	angle = 2 * PI / 24; 
float	delta = atan2(camZ, camX); 


float	camYScale = 1;
float	camFarScale = 1.1;

float	baseRadius = 0.6;
float	baseHeight = 3;
float	baseRotateStep = 5;

float	cylRadius = 0.3;
float	cylHeight = 1.0;
float   cylMaxScaleY = 2.0;
float	cylScaleStep = 0.05;

float	body1SizeX = 2;
float	body1SizeY = 1.5;
float	body1SizeZ = 1;

float	grooveLong = 2.0;
float	grooveLength1 = 0.4;
float	grooveLength2 = 0.2;
float	grooveLength3 = 0.1;
float	grooveHeight1 = 0.6;
float	grooveHeight2 = 0.2;

float	grooveLong1 = 2.5;
float	grooveLength11 = 0.4;
float	grooveLength12 = 0.2;
float	grooveLength13 = 0.1;
float	grooveHeight11 = 0.2;
float	grooveHeight12 = 0.2;

float	ledgeLong = 0.5;
float	ledgeLength1 = 0.4;
float	ledgeLength2 = 0.1;
float	ledgeLength3 = 0.2;
float	ledgeHeight1 = 0.2;
float	ledgeHeight2 = 0.2;

float	ledgeLong1 = 0.5;
float	ledgeLength11 = 0.4;
float	ledgeLength12 = 0.1;
float	ledgeLength13 = 0.2;
float	ledgeHeight11 = 0.2;
float	ledgeHeight12 = 0.2;

float	cubesize = 1;

float ledgeSizex = 2;
float ledgeSize1x = -1.75;

float cylinderHeight = 0.2;
float cylindeRadius = 0.1;

GLfloat red[] = { 1.0f, 0.0f, 0.0f,1.0f };
GLfloat green[] = { 0.0f, 1.0f, 0.0f,1.0f };
GLfloat blue[] = { 0.0f, 0.0f, 1.0f,1.0f };
GLfloat golden[] = { 1.0f, 0.5f, 0.25f };
GLfloat black[] = { 0.0f, 0.0f, 0.0f,1.0f };
GLfloat white[] = { 1.0f, 1.0f, 1.0f,1.0f };
GLfloat yellow[] = { 1.0f, 1.0f, 0.0f,1.0f };
GLfloat purple[] = { 1.0f, 0.0f, 1.0f,1.0f };
GLfloat almostpink[] = { 1.0f, 0.0f, 0.5f, 1.0f };
GLfloat gray[] = { 0.5f, 0.5f, 0.5f,1.0f };
GLfloat	Specularx[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat	Ambientx[] = { 0.5f, 0.5f, 0.5f, 0.5f };
GLfloat light_positionx1[] = { 6.0f, 6.0f, 6.0f, 0.0f };


Mesh	base;
Mesh	cyl;
Mesh	body1;
Mesh	groove;
Mesh	groove1;
Mesh	ledge;
Mesh	ledge1;
Mesh	cube;
Mesh	cylinder;
Mesh	floor1;
Mesh	facenorm;
int		nChoice = 1;
void setupMaterial(float ambient[], float diffuse[], float specular[], float shiness)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shiness);
}

void drawAxis()
{
	glPushMatrix();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(-4, 0, 0);//x
	glVertex3f(4, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);//y
	glVertex3f(0, 4, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -4);//z
	glVertex3f(0, 0, 4);
	glEnd();

	glPopMatrix();
}
void myKeyboard(unsigned char key, int x, int y)
{
	float	fRInc;
	float	fAngle;
	switch (key)
	{
	

	
	case '+':
		cam_dis += 0.1;
		camX = cam_dis * cos(delta);
		camZ = cam_dis * sin(delta);
		
		break;
	case '-':
		cam_dis -= 0.1;
		camX = cam_dis * cos(delta);
		camZ = cam_dis * sin(delta);
		
		break;
		
		//r/c(d+h)
	
			

	}

	//cout << camX << " " << camY << " " << camZ << " " << angle << " " << cam_dis << endl;
	glutPostRedisplay();
}

void drawBase()
{

	glPushMatrix();

	glTranslated(0, base.slideY, 0);
	glRotatef(base.rotateY, 0, 1, 0);

	
		base.DrawWireframe();
	
	


	glPopMatrix();
}
void drawCyl()
{
	glPushMatrix();

	glTranslated(0, cyl.slideY + baseHeight, 0);
	glScalef(cyl.scaleX, cyl.scaleY, cyl.scaleZ);
	glRotatef(base.rotateY, 0, 1, 0);

	if (bWireFrame)
		cyl.DrawWireframe();
	else {
		setupMaterial(Ambientx, blue, Specularx, 50);
		cyl.Draw();
	}
	glPopMatrix();
}
void drawBody1()
{
	glPushMatrix();
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(0, body1.slideY, 0);

	
		body1.DrawWireframe();
	
	glPopMatrix();
}



void drawCube()
{
	glPushMatrix();
	glRotatef(cube.rotateY, 0, 1, 0);
	glTranslated(0, cube.slideY, 0);

	
		cube.DrawWireframe();
	
	
	glPopMatrix();
}

void drawCylinder()
{
	glPushMatrix();
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(0, body1SizeY * 2 + cylHeight*cyl.scaleY + baseHeight + cubesize + cylinderHeight*2, 0.9);

	if (bWireFrame)
		cylinder.DrawWireframe();
	else {
		setupMaterial(Ambientx, black, Specularx, 50);
		cylinder.Draw();
	}
	glPopMatrix();
}

void drawCylinder1()
{
	glPushMatrix();
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(ledgeSizex, body1SizeY * 2 + cylHeight*cyl.scaleY + baseHeight + grooveHeight1 + ledgeHeight2 + cylinderHeight*1.5, -1);

	if (bWireFrame)
		cylinder.DrawWireframe();
	else {
		setupMaterial(Ambientx, black, Specularx, 50);
		cylinder.Draw();
	}
	glPopMatrix();
}

void drawCylinder2()
{
	glPushMatrix();
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(ledgeSize1x, body1SizeY * 2 + cylHeight*cyl.scaleY + baseHeight + grooveHeight11 + ledgeHeight12 + cylinderHeight*1.5, -1);

	if (bWireFrame)
		cylinder.DrawWireframe();
	else {
		setupMaterial(Ambientx, black, Specularx, 50);
		cylinder.Draw();
	}
	glPopMatrix();
}

void mySpecialFunc(int key, int x, int y) {

	if (key == GLUT_KEY_UP) {
		camY += camYScale;

		camYFirstView = camY;
		//cout << camY << endl;//60
	}
	else if (key == GLUT_KEY_DOWN) {
		camY -= camYScale;

		camYFirstView = camY;
		//cout << camY << endl; //-60
	}
	else if (key == GLUT_KEY_LEFT) {
		if (!camView) {
			camX = cam_dis*cos(delta - angle);
			camZ = cam_dis*sin(delta - angle);
			delta -= angle;

			camZFirstView = camZ;
			camXFirstView = camX;
		}
	}
	else if (key == GLUT_KEY_RIGHT) {
		if (!camView) {
			camX = cam_dis*cos(delta + angle);
			camZ = cam_dis*sin(delta + angle);
			delta += angle;

			camZFirstView = camZ;
			camXFirstView = camX;
		}
	}
	//cout << camX << " " << camY << " " << camZ<< " " << angle << " " << cam_dis<< endl;
	glutPostRedisplay();
}

void drawFloor()
{
	int SPACE = -2;
	for (int i = -5; i < 5; i++)
	{
		for (int j = -5; j < 5; j++)
		{
			glPushMatrix();
			glTranslated(floor1.slideX + i*SPACE, floor1.slideY, floor1.slideZ + j*SPACE);
			if (bWireFrame) {
				floor1.DrawWireframe();
			}
			else {
				floor1.Draw();
			}
			glPopMatrix();
		}
	}
}

void myDisplay()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	if (lookat) {
		gluLookAt(0, 5, 0, 0, 0, 0, 0, 0, 1);
	}
	else {
		gluLookAt(camX, camY, camZ, 0, 1, 0, 0, 1.0, 0.0);
	}
	float k = cam_dis / Rxz;
	glScalef(k, k, k);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, screenWidth, screenHeight);

	if (nChoice == 1)
		drawCube();
	else if (nChoice == 2)
		drawBase();
	else if (nChoice == 3)
		drawBody1();
	else if (nChoice == 4)
		drawCyl();
	
	

	
	
	glFlush();
	glutSwapBuffers();
}

void myInit()
{
	float	fHalfSize = 4;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);

	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
	GLfloat	lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat	lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat	lightAmbient[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat	lightAmbient2[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat 	light_position1[] = { 6.0f, 6.0f, 6.0f, 0.0f };
	GLfloat 	light_position2[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

	glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular);

	glEnable(GL_LIGHTING);


	glMatrixMode(GL_MODELVIEW);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "1. Hinh lap phuong" << endl;
	cout << "2. Hinh tru" << endl;
	cout << "3. Hinh hop chu nhat" << endl;
	cout << "4. Cylinder" << endl;
	cout << "Input the choice: " << endl;
	cin >> nChoice;

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("DCLV"); // open the screen window
	
	
	base.CreateCylinder(30, baseHeight, baseRadius);
	base.SetColor(2);
	base.slideY = baseHeight / 2.0;

	cyl.CreateCylinder(20, cylHeight, cylRadius);
	cyl.SetColor(0);
	cyl.slideY = cylHeight / 2.0;

	body1.CreateCuboid(body1SizeX, body1SizeY, body1SizeZ);
	body1.SetColor(4);

	groove.CreateGrooveBox(grooveLong, grooveLength1, grooveLength2, grooveLength3, grooveHeight1, grooveHeight2);
	groove.SetColor(3);
	groove.slideY = grooveHeight1 / 2.0;

	groove1.CreateGrooveBox(grooveLong1, grooveLength11, grooveLength12, grooveLength13, grooveHeight11, grooveHeight12);
	groove1.SetColor(5);
	groove1.slideY = grooveHeight11 / 2.0;

	ledge.CreateLedgeBox(ledgeLong, ledgeLength1, ledgeLength2, ledgeLength3, ledgeHeight1, ledgeHeight2);
	ledge.SetColor(6);
	ledge.slideY = ledgeHeight2 / 2.0;

	ledge1.CreateLedgeBox(ledgeLong1, ledgeLength11, ledgeLength12, ledgeLength13, ledgeHeight11, ledgeHeight12);
	ledge1.SetColor(7);
	ledge1.slideY = ledgeHeight12 / 2.0;

	cube.CreateCube(cubesize);
	cube.SetColor(8);
	cube.slideY = cubesize / 2.0;

	cylinder.CreateCylinder(20, cylinderHeight, cylindeRadius);
	cylinder.SetColor(9);
	cylinder.slideY = cylinderHeight / 2.0;

	floor1.CreateFloor();
	floor1.SetColor(10);
	floor1.slideY = 0;
	myInit();

	
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecialFunc);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}






