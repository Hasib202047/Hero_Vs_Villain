#include "iGraphics.h"
#include "bitmap_loader.h"

int x = 0, y = 40;
int x2=0, y2=345;
int i1,i2,i3;
int t;
int speed=10,speed2=7;

/*
 function iDraw() is called again and again by the system.

 */



void iDraw()
{
	//place your drawing codes here
	iClear();
	iShowImage(0,0,1200,650,i3);
	iShowImage(x,y,200,100,i1);
	iShowImage(x2,y2, 200,100,i2);
	iText(10,10,"press b to set speed to previous one");
}

void iPassiveMouse(int x, int y)
{
	
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	//printf("x = %d, y= %d\n", mx, my);
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
	if (key == 'q')
	{
		exit(0);
	}
	else if (key == 'd')
		x+= speed;
	else if (key == 'a')
		 x-= speed;
	else if(key =='w' )
		y+=speed;
	else if(key=='s')
		y-=speed;
	
	else if(key=='b')
	{
	speed = 10;
	speed2= 7;
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

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	else if(key==GLUT_KEY_RIGHT)
	x2+=speed2;
	else if(key == GLUT_KEY_LEFT)	
		x2-=speed2;
	else if(key == GLUT_KEY_UP)
		y2+=speed2;

	else if(key == GLUT_KEY_DOWN)
		y2-=speed2;
	//place your codes for other keys here
}
void func(void)
	{

speed=speed+8;
speed2=speed2+6;

}

int main()
{
	//place your own initialization codes here.


	iInitialize(1200, 650, "Keyboard Func");
	t= iSetTimer(1000,func);
	i3=iLoadImage("road.png");
	i1= iLoadImage("car.png");
	i2= iLoadImage("car2.png");

	
	iStart();// it will start drawing
	return 0;
}

