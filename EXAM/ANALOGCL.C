#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
void drawnums(int midx, int midy, int r)
{
	/* This Function plots the numbers on the outer side of clock boundary. */
	int angle,i,rads,x,y;
	char *nums;
	for( i=3,angle=0 ; angle<=360 ; i++,angle+=30)
	{
		sprintf(nums, "%d", i);
		x = midx + (int)(1.2 * r * cos(angle*((22.0/7.0)/180)));
		y = midy + (int)(1.2 * r * sin(angle*((22.0/7.0)/180)));
		outtextxy(x,y,nums);
		if(i==12)
			i = 0;
	}
}
void drawclock(int midx,int midy,int r)
{
	int i = 0;
	int x1,x2,y1,y2;
   /* draw the circle */
   circle(midx, midy, r);
   /* draws lines on circle peripheral */
   for( i = 0 ; i < 12 ; i++ )
   {
	x1 = midx + (int)(0.95*r * cos(i*((22.0/7.0)/6)));
	x2 = midx + (int)(r * cos(i*((22.0/7.0)/6)));
	y1 = midy + (int)(0.95*r * sin(i*((22.0/7.0)/6)));
	y2 = midy + (int)(r * sin(i*((22.0/7.0)/6)));
	line(x1,y1,x2,y2);
   }
   drawnums(midx,midy,r);
}
int main(void)
{
   int gdriver = DETECT, gmode;
   int midx, midy;
   int r = 100;
   int i,angle = 90;
   int x2,y2;
   int secs, mins, hrs;
   time_t now;
   struct tm *tm;
   initgraph(&gdriver, &gmode, "");
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(getmaxcolor());
   drawclock(midx, midy, r);
   while(!kbhit())
   {
	now = time(0);
	tm = localtime(&now);
	secs = tm->tm_sec;
	angle = 90 - secs*6;
	x2 = midx + (int)(0.8 * r * cos(angle * ((22.0/7.0)/180)));
	y2 = midy - (int)(0.8 * r * sin(angle * ((22.0/7.0)/180)));
	cleardevice();
	drawclock(midx, midy, r);
	line(midx, midy, x2, y2);
	mins = tm->tm_min;
	angle = 90 - mins*6 - (int)secs*0.1;
	x2 = midx + (int)(0.76 * r * cos(angle * ((22.0/7.0)/180)));
	y2 = midy - (int)(0.76 * r * sin(angle * ((22.0/7.0)/180)));
	line(midx, midy, x2, y2);
	hrs = tm->tm_hour;
	angle = 90 - hrs*30 - 30 * (mins/60.0) - (int)secs/120.0;
	x2 = midx + (int)(0.6 * r * cos(angle * ((22.0/7.0)/180)));
	y2 = midy - (int)(0.6 * r * sin(angle * ((22.0/7.0)/180)));
	line(midx, midy, x2, y2);
	delay(1000);
   }
   closegraph();
   return 0;
}