//hogehogewhale
/* main.cpp
*
*	main source for GRAPPA PAINT  
*		(c) M,Haroon, S.Suzuki 2017.4.26
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

#include<GL/glut.h>

/* Number of Windows */
const int WinNum = 1;
int WindowID[WinNum];

/* Function Prototype Declaration */
void WindowCanvas(void);
void PopUpMenu(void);
void Controler(void);
void init(void);
void idle(void);
void display(void);
void resize(int w, int h);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void menu(int val);
void keyboard(unsigned char key, int x, int y);
void keyboard_sp(int key, int x, int y);


/* main function */
int main(int argc, char *argv[]){
	srand((unsigned) time(NULL));
	glutInit(&argc, argv);
	/* histogram window */
	WindowCanvas();
	PopUpMenu();
	Controler();
	glutMainLoop();
	return 0;
}


/******** Functions *********/

void WindowCanvas(void){
	glutInitWindowPosition(350,0);
	glutInitWindowSize(809,500);
	glutInitDisplayMode(GLUT_RGBA);
	WindowID[0] = glutCreateWindow("GRAPPA PAINT");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	init();
}


void PopUpMenu(void){
	glutCreateMenu(menu);
	glutAddMenuEntry("Quit",0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void Controler(void){
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard_sp);
}


void init(void){
	glClearColor(0.1,0.1,0.1,1.0);
}


void idle(void){
	for(int i=0; i<WinNum; ++i){
		glutSetWindow(WindowID[i]);
		glutPostRedisplay();
	}
}


void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	double Cmargin = 10.0;		
	glColor3d(1.0,1.0,1.0);
	glBegin(GL_QUADS);
	glVertex2d(Cmargin/100,Cmargin/100);
	glVertex2d((100-Cmargin)/100,Cmargin/100);
	glVertex2d((100-Cmargin)/100,(100-Cmargin)/100);
	glVertex2d(Cmargin/100,(100-Cmargin)/100);
	glEnd();

	glFlush();
}


void resize(int w, int h){
	glViewport(0, 0, w ,h);
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}


/* mouse click */
void mouse(int button, int state, int x, int y){
	int ID = glutGetWindow();
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if(state==GLUT_UP){
				MFLAG = false;
			}
			if(state==GLUT_DOWN){
			}
			glutIdleFunc(idle);
			break;
		default:
			break;
	}
}


/* mouse motion */
void motion(int x, int y){
	static int xmouse;
	static int ymouse;

	if(MFLAG){
		int ID = glutGetWindow();
		if(ID==WindowID[0]){ /* for Histgram Window */
			glutIdleFunc(idle);
		}
	}
	glutIdleFunc(idle);
	xmouse = x;
	ymouse = y;
	MFLAG  = true;
}


void menu(int val){
	switch(val){
		case 0:  /* Quit */
			exit(0);
		default:
			break;
	}
}


void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'q': /* Quit */
		case 'Q':
		case '\033':
			printf("\033[39m\033[49m\n");
			exit(0);
		default:
			break;
	}
}


void keyboard_sp(int key, int x, int y){
	switch (key) {
		case GLUT_KEY_RIGHT:
			break;
		case GLUT_KEY_LEFT:
			break;
		case GLUT_KEY_UP:
			break;
		case GLUT_KEY_DOWN:
			break;
		default:
			break;
	}
}


