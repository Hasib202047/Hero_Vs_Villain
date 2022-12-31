#include "iGraphics.h"
#include "bitmap_loader.h"

int x = 0, y = 300, r = 50,g=90,b=230;
int r1 = 50,g1=90,b1=30;
int r2 = 180,g2=90,b2=230;
int r3 = 50,g3=190,b3=230;
int win_b = 400, win_l = 400;
float delay = 0;
int speed = 4;
int counter =0;
int cx=200,cy=100;
int cx2=600,cy2=250;
int cx3=900,cy3=530;
int radius=50;
int height=100;
int width=1000;
int image1,image2,image3;

 //function iDraw() is called again and again by the system.

void objectspeed()
{
	cx=cx-speed;
	
}
void objectspeed2()
{
	
	cx2=cx2-speed;
	
}
void objectspeed3()
{
	
	cx3=cx3-speed;
	
}
void colorchange()
{
	r=133;
	g=145;
	b=30;
}

void iDraw()
{
	//place your drawing codes here
	iClear();
	iShowImage(0,0,1000,800,image1);
	iShowImage(x,y,100,90,image2);
	iShowImage(cx,cy,50,50,image3);
	iShowImage(cx2,cy2,50,50,image3);
	iShowImage(cx3,cy3,50,50,image3);
	
	
	
	if(cx <=0)
		cx=width;
	if(cx2 <=0)
		cx2=width;
	if(cx3 <=0)
		cx3=width;
	iSetColor(0,0,0);
	iText(10,20,"Press p for pause, r for resume, END for exit.");
	
	
}

void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		

	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		y=y+15;
	}
	if (key == 's')
	{
		y=y-15;
	}
	if (key == 'd')
	{
		x=x+15;
	}
	if (key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
	}
	else if (key == 'r')
	{
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}
	//place your codes for other keys here
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_UP)
	{
		y=y+15;
	}
	if (key == GLUT_KEY_DOWN)
	{
		y=y-15;
	}
	if (key == GLUT_KEY_LEFT)
	{
		x=x-15;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		x=x+15;
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.


	iInitialize(1000, 600, "Offline");
	iSetTimer(15,objectspeed);
	iSetTimer(20,objectspeed2);
	iSetTimer(25,objectspeed3);
	
	
	image1=iLoadImage("images\\sky1.png");
	image2=iLoadImage("images\\palne.jpg");
	image3=iLoadImage("images\\fireball.jpg");
	
	iStart(); // it will start drawing

	return 0;
}

