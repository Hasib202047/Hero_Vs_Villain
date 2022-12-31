# include "iGraphics.h"
//#include"myheader.h"
int i;
int x[100],y[100];
int dx, dy;
int balltimer_1;
int moveX,total ;


void drawBall(int x, int y)
{ iSetColor(255, 0, 0);
	iFilledCircle(x, y, 10,100);
}
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	iClear();
	iSetColor(255,255,255);
	iFilledRectangle(0,0,1200,650);
	iSetColor(0,0,255);
	iFilledRectangle(moveX,0,150,30);
	for(i = 0; i < total; i++)
	{ drawBall(x[i], y[i]);}
    
	
	iText(10, 10, "Press p for pause, r for resume, END for exit.");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	moveX=mx;
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(total < 100)
		{
			x[total] = mx;
			y[total] = my;
			total++;
		}
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if(total>0)
		{
			total--;
		}
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(balltimer_1);
       

	}
	if(key == 'r')
	{
		iResumeTimer(balltimer_1);
       

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

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

void ballChange1(){
	for(i=0;i<total;i++)
	{x[i] += dx;
	y[i] += dy;

	if(x[i] > 1200 || x[i] < 0)dx = -dx;
	if(y[i] > 650 || y[i] < 0)dy = -dy;
}
}



int main()
{
	//place your own initialization codes here.
	balltimer_1 = iSetTimer(10, ballChange1);
	

	dx = 4;
	dy = 8;
	iInitialize(1200, 650, "Mouse Func");
    iStart();
	return 0;
}

