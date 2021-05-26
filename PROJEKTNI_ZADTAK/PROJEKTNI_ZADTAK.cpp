
#include <iostream>
#include <GL/freeglut.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include "Pistol.cpp"
#include "Model.cpp"


using namespace glm;
using namespace std;

vec4 camera(3, 3, 3, 1);
float FPS = 60;
float WIDTH = 1200;
float HEIGHT = 800;
int showHud = 0; //0 - main menu; 1-start game ; 2 - customize ; 3 - options ; 4-exit
float x = 0;
float y = 0;
float z = 0;
char naslov[] = "puska.txt";
Glock* pistol_1 = new Glock();
Model* model_1 = new Model(naslov);

void drawModel(Model* model)
{
	glColor3f(0.7, 0.7, 0.7);
	for (int i = 0; i < model->face_n; i++)
	{
		glBegin(GL_POLYGON);
		glVertex3f(model->centar.x + model->positions[model->faces[i][0]][0], model->centar.x + model->positions[model->faces[i][0]][1], model->centar.x + model->positions[model->faces[i][0]][2]);
		glVertex3f(model->centar.x + model->positions[model->faces[i][1]][0], model->centar.x + model->positions[model->faces[i][1]][1], model->centar.x + model->positions[model->faces[i][1]][2]);
		glVertex3f(model->centar.x + model->positions[model->faces[i][2]][0], model->centar.x + model->positions[model->faces[i][2]][1], model->centar.x + model->positions[model->faces[i][2]][2]);
		glVertex3f(model->centar.x + model->positions[model->faces[i][3]][0], model->centar.x + model->positions[model->faces[i][3]][1], model->centar.x + model->positions[model->faces[i][3]][2]);

		glEnd();
	}

}



void drawPistol(Glock* pistol)
{
	glColor3f(0.2, 0.2, 0.2);


// gornji deo pistolja
	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[0][0].x, pistol->glock_centar.y + pistol->glock[0][0].y, pistol->glock_centar.z + pistol->glock[0][0].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[0][1].x, pistol->glock_centar.y + pistol->glock[0][1].y, pistol->glock_centar.z + pistol->glock[0][1].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[0][2].x, pistol->glock_centar.y + pistol->glock[0][2].y, pistol->glock_centar.z + pistol->glock[0][2].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[0][3].x, pistol->glock_centar.y + pistol->glock[0][3].y, pistol->glock_centar.z + pistol->glock[0][3].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[0][4].x, pistol->glock_centar.y + pistol->glock[0][4].y, pistol->glock_centar.z + pistol->glock[0][4].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[0][5].x, pistol->glock_centar.y + pistol->glock[0][5].y, pistol->glock_centar.z + pistol->glock[0][5].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[0][6].x, pistol->glock_centar.y + pistol->glock[0][6].y, pistol->glock_centar.z + pistol->glock[0][6].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[0][7].x, pistol->glock_centar.y + pistol->glock[0][7].y, pistol->glock_centar.z + pistol->glock[0][7].z);
	glEnd();
//donji deo pistolja
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[1][0].x, pistol->glock_centar.y + pistol->glock[1][0].y, pistol->glock_centar.z + pistol->glock[1][0].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[1][1].x, pistol->glock_centar.y + pistol->glock[1][1].y, pistol->glock_centar.z + pistol->glock[1][1].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[1][2].x, pistol->glock_centar.y + pistol->glock[1][2].y, pistol->glock_centar.z + pistol->glock[1][2].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[1][3].x, pistol->glock_centar.y + pistol->glock[1][3].y, pistol->glock_centar.z + pistol->glock[1][3].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[1][4].x, pistol->glock_centar.y + pistol->glock[1][4].y, pistol->glock_centar.z + pistol->glock[1][4].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[1][5].x, pistol->glock_centar.y + pistol->glock[1][5].y, pistol->glock_centar.z + pistol->glock[1][5].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[1][6].x, pistol->glock_centar.y + pistol->glock[1][6].y, pistol->glock_centar.z + pistol->glock[1][6].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[1][7].x, pistol->glock_centar.y + pistol->glock[1][7].y, pistol->glock_centar.z + pistol->glock[1][7].z);
	glEnd();
// najdonji deo pistolja (drska)
	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][0].x, pistol->glock_centar.y + pistol->glock[2][0].y, pistol->glock_centar.z + pistol->glock[2][0].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][1].x, pistol->glock_centar.y + pistol->glock[2][1].y, pistol->glock_centar.z + pistol->glock[2][1].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][2].x, pistol->glock_centar.y + pistol->glock[2][2].y, pistol->glock_centar.z + pistol->glock[2][2].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][3].x, pistol->glock_centar.y + pistol->glock[2][3].y, pistol->glock_centar.z + pistol->glock[2][3].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][0].x, pistol->glock_centar.y + pistol->glock[2][0].y, pistol->glock_centar.z + pistol->glock[2][0].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][4].x, pistol->glock_centar.y + pistol->glock[2][4].y, pistol->glock_centar.z + pistol->glock[2][4].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][5].x, pistol->glock_centar.y + pistol->glock[2][5].y, pistol->glock_centar.z + pistol->glock[2][5].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][1].x, pistol->glock_centar.y + pistol->glock[2][1].y, pistol->glock_centar.z + pistol->glock[2][1].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][4].x, pistol->glock_centar.y + pistol->glock[2][4].y, pistol->glock_centar.z + pistol->glock[2][4].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][6].x, pistol->glock_centar.y + pistol->glock[2][6].y, pistol->glock_centar.z + pistol->glock[2][6].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][7].x, pistol->glock_centar.y + pistol->glock[2][7].y, pistol->glock_centar.z + pistol->glock[2][7].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][5].x, pistol->glock_centar.y + pistol->glock[2][5].y, pistol->glock_centar.z + pistol->glock[2][5].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][5].x, pistol->glock_centar.y + pistol->glock[2][5].y, pistol->glock_centar.z + pistol->glock[2][5].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][7].x, pistol->glock_centar.y + pistol->glock[2][7].y, pistol->glock_centar.z + pistol->glock[2][7].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][8].x, pistol->glock_centar.y + pistol->glock[2][8].y, pistol->glock_centar.z + pistol->glock[2][8].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][2].x, pistol->glock_centar.y + pistol->glock[2][2].y, pistol->glock_centar.z + pistol->glock[2][2].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][3].x, pistol->glock_centar.y + pistol->glock[2][3].y, pistol->glock_centar.z + pistol->glock[2][3].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][9].x, pistol->glock_centar.y + pistol->glock[2][9].y, pistol->glock_centar.z + pistol->glock[2][9].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][8].x, pistol->glock_centar.y + pistol->glock[2][8].y, pistol->glock_centar.z + pistol->glock[2][8].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][2].x, pistol->glock_centar.y + pistol->glock[2][2].y, pistol->glock_centar.z + pistol->glock[2][2].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][4].x, pistol->glock_centar.y + pistol->glock[2][4].y, pistol->glock_centar.z + pistol->glock[2][4].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][6].x, pistol->glock_centar.y + pistol->glock[2][6].y, pistol->glock_centar.z + pistol->glock[2][6].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][9].x, pistol->glock_centar.y + pistol->glock[2][9].y, pistol->glock_centar.z + pistol->glock[2][9].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][3].x, pistol->glock_centar.y + pistol->glock[2][3].y, pistol->glock_centar.z + pistol->glock[2][3].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][6].x, pistol->glock_centar.y + pistol->glock[2][5].y, pistol->glock_centar.z + pistol->glock[2][6].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][7].x, pistol->glock_centar.y + pistol->glock[2][7].y, pistol->glock_centar.z + pistol->glock[2][7].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][8].x, pistol->glock_centar.y + pistol->glock[2][8].y, pistol->glock_centar.z + pistol->glock[2][8].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][9].x, pistol->glock_centar.y + pistol->glock[2][9].y, pistol->glock_centar.z + pistol->glock[2][9].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][0].x, pistol->glock_centar.y + pistol->glock[2][0].y, pistol->glock_centar.z + pistol->glock[2][0].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][4].x, pistol->glock_centar.y + pistol->glock[2][4].y, pistol->glock_centar.z + pistol->glock[2][4].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][3].x, pistol->glock_centar.y + pistol->glock[2][3].y, pistol->glock_centar.z + pistol->glock[2][3].z);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][1].x, pistol->glock_centar.y + pistol->glock[2][1].y, pistol->glock_centar.z + pistol->glock[2][1].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][5].x, pistol->glock_centar.y + pistol->glock[2][5].y, pistol->glock_centar.z + pistol->glock[2][5].z);
	glVertex3f(pistol->glock_centar.x + pistol->glock[2][2].x, pistol->glock_centar.y + pistol->glock[2][2].y, pistol->glock_centar.z + pistol->glock[2][2].z);
	glEnd();




	for (int i = 0; i < 4; i++)
	{
		//cout << "GLOCK :" << this->glock[0][i].x << endl;
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_POLYGON);
		glVertex3f(pistol->glock_centar.x + pistol->glock[0][i].x, pistol->glock_centar.y + pistol->glock[0][i].y, pistol->glock_centar.z + pistol->glock[0][i].z);
		glVertex3f(pistol->glock_centar.x + pistol->glock[0][(i + 1) % 4].x, pistol->glock_centar.y + pistol->glock[0][(i + 1) % 4].y, pistol->glock_centar.z + pistol->glock[0][(i + 1) % 4].z);
		glVertex3f(pistol->glock_centar.x + pistol->glock[0][(i + 1) % 4 + 4].x, pistol->glock_centar.y + pistol->glock[0][(i + 1) % 4 + 4].y, pistol->glock_centar.z + pistol->glock[0][(i + 1) % 4 + 4].z);
		glVertex3f(pistol->glock_centar.x + pistol->glock[0][i + 4].x, pistol->glock_centar.y + pistol->glock[0][i + 4].y, pistol->glock_centar.z + pistol->glock[0][i + 4].z);
		glEnd();

		glColor3f(0.3, 0.3, 0.3);
		glBegin(GL_POLYGON);
		glVertex3f(pistol->glock_centar.x + pistol->glock[1][i].x, pistol->glock_centar.y + pistol->glock[1][i].y, pistol->glock_centar.z + pistol->glock[1][i].z);
		glVertex3f(pistol->glock_centar.x + pistol->glock[1][(i + 1) % 4].x, pistol->glock_centar.y + pistol->glock[1][(i + 1) % 4].y, pistol->glock_centar.z + pistol->glock[1][(i + 1) % 4].z);
		glVertex3f(pistol->glock_centar.x + pistol->glock[1][(i + 1) % 4 + 4].x, pistol->glock_centar.y + pistol->glock[1][(i + 1) % 4 + 4].y, pistol->glock_centar.z + pistol->glock[1][(i + 1) % 4 + 4].z);
		glVertex3f(pistol->glock_centar.x + pistol->glock[1][i + 4].x, pistol->glock_centar.y + pistol->glock[1][i + 4].y, pistol->glock_centar.z + pistol->glock[1][i + 4].z);
		glEnd();


	}
}

void drawAxis()
{
	glLineWidth(5);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(2, 0, 0);
	glEnd();

	glColor3f(0,1, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 2, 0);
	glEnd();
	glColor3f(0,0,1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 2);
	glEnd();
	glLineWidth(1);

}
void drawGround()
{
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex3f(-5, -0.01, -5);
	glVertex3f(5, -0.01, -5);
	glVertex3f(5, -0.01, 5);
	glVertex3f(-5,-0.01, 5);

	glEnd();
}
void drawHud()
{
	glColor3f(0, 0, 0);
	//BACKGROUND
	glBegin(GL_POLYGON);
	glVertex2f(-1, -1);
	glVertex2f(-0.5, -1);
	glVertex2f(-0.5, 1);
	glVertex2f(-1, 1);
	glEnd();


	//TEXT
	glColor3f(1, 1, 1);
	glRasterPos2d(-0.9, 0.8);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Rust");
	if (showHud == 0)
	{
		//MAIN MENU
		glRasterPos2d(-0.9, 0.6);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)"start");
		glRasterPos2d(-0.9, 0.5);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)"costumize");
		glRasterPos2d(-0.9, 0.4);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)"options");
		glRasterPos2d(-0.9, 0.3);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)"exit");
	}
	else if (showHud == 1)
	{
		//START GAME

	}
	else if (showHud == 4)
	{
		//EXIT GAME
		glRasterPos2d(-0.9, 0.6);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)"Sure?");
		glRasterPos2d(-0.9, 0.5);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)"yes");
		glRasterPos2d(-0.9, 0.4);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)"no");
	}

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluPerspective(80.f, 16.f / 9.f, 0.1f, 50.f);
	gluLookAt(camera.x, camera.y, camera.z, 0, 0, 0, 0, 1, 0);
	
	
	//drawAxis();
	//drawGround();
	drawPistol(pistol_1);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);

	drawHud();


	glEnable(GL_DEPTH_TEST);
	
	glutSwapBuffers();
}

void initGL()
{
	
	glClearColor(0.9, 0.9,0.9, 1);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}
void reshape(GLsizei width, GLsizei height)
{
	if (height == 0)
		height = 1;
	GLfloat ass_pect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, ass_pect, 0.1, 600);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera.x, camera.y, camera.z, 0, 0, 0, 0, 1, 0);
}
void rotateCamera()
{
	float angle = 2 * 3.14 / 720;
	mat4 rotateMatrix = glm::rotate(mat4(1.0f), angle,vec3(0, 1, 0));
	camera = rotateMatrix * camera;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera.x, camera.y, camera.z, 0, 0, 0, 0, 1, 0);
}
void timer(int val)
{
	rotateCamera();
	glutTimerFunc(1000 / FPS, timer, val);
	glutPostRedisplay();
}

void KeyboardKeyPressed(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:    //ESC key
		exit(0);
		break;
	case 'w':
		cout << "w pressed -> moving forward, speed up" << endl;
		//speedUp();
		break;
	case 's':
		cout << "s pressed -> moving forward, speed down" << endl;
		//speedDown();
		break;
	case 'a':
		cout << "a pressed -> roll left" << endl;
	//	roll(1);
		break;
	case 'd':
		cout << "a pressed -> roll right" << endl;
		//roll(-1);
		break;

	case 'u':
		cout << "u pressed -> SpeedUp" << endl;
	//	speedUp();
		break;
	case 'i':
		cout << "j pressed -> SpeedDown" << endl;
	//	speedDown();
		break;
	case 52:
		cout << "4 pressed -> turning left" << endl;
	//	turnLeft();
		break;
	case 54:
		cout << "6 pressed -> turning right" << endl;
	//	turnRight();
		break;
	case 50:
		cout << "2 pressed -> look up" << endl;
	//	lookDown();
		break;
	case 56:
		cout << "8 pressed -> look down" << endl;
	//	lookUp();
		break;
	}

	glutPostRedisplay();
}
void mouseFunction(int button, int state, int x, int y)
{	

	cout << "BUTTON : " << button << endl;
	cout << "STATE : " << state << endl;
	cout << "X : " << x << endl;
	cout << "Y : " << y << endl;
	cout << "-------------" << endl;
	if (showHud == 0)
	{
		if (x >= 53 && x <= 85 && y >= 147 && y <= 160)
			cout << "START";
		if (x >= 53 && x <= 105 && y >= 189 && y <= 202)
			cout << "CUSTOMIZE";
		if (x >= 53 && x <= 99 && y >= 230 && y <= 241)
			cout << "OPTIONS";
		if (x >= 53 && x <= 84 && y >= 270 && y <= 279)
			showHud = 4;
	}
	if (showHud == 4)
	{
		if (x >= 53 && x <= 70 && y >= 189 && y <= 202)
			exit(0);
		if (x >= 53 && x <= 70 && y >= 230 && y <= 241)
			showHud = 0;
	}



	glutPostRedisplay();
}
void mouseMove(int x, int y)
{

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(30, 30);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("WALKING SIMULATOR");
	initGL();
	
	glutDisplayFunc(display);
	glutTimerFunc(1000 / FPS, timer, 0);
	glutKeyboardFunc(KeyboardKeyPressed);
	glutMouseFunc(mouseFunction); //mouse click
	//glutPassiveMotionFunc(mouseMove); //mouse move
	glutReshapeFunc(reshape);
	glutMainLoop();
}