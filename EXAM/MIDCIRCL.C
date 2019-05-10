#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
	int gdriver = DETECT, gmode;
	int midx, midy,x,y;
	float p0;
	int r = 100;
	initgraph(&gdriver, &gmode, "");
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	setcolor(getmaxcolor());
	x=0;
	y=r;
	p0 = (5/4) - r;
	while(x<y)
	{
		putpixel((midx+x),(midy+y),15);
		putpixel((midx+x),(midy-y),15);
		putpixel((midx+y),(midy+x),15);
		putpixel((midx+y),(midy-x),15);
		putpixel((midx-x),(midy-y),15);
		putpixel((midx-x),(midy+y),15);
		putpixel((midx-y),(midy-x),15);
		putpixel((midx-y),(midy+x),15);
		if(p0<0)
		{
			x= x+1;
			p0=p0+ 2*x +3;
		}
		if(p0>=0)
		{
			x=x+1;
			y=y-1;
			p0=p0+2*(x-y)+5;
		}
	}
	getch();
	closegraph();
	return 0;
}