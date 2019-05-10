#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
	int gdriver = DETECT, gmode;
	int i,x1,x2,y1,y2,p,temp,x,y,dx,dy;
	float m;
	initgraph(&gdriver, &gmode, "");
	setcolor(getmaxcolor());
	printf("Enter x1 & y1: ");
	scanf("%d%d",&x1,&y1);
	printf("Enter x2 & y2: ");
	scanf("%d%d",&x2,&y2);
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	m = (y2-y1) / (x2-x1);
	if(0.0<m<1.0 || -1.0<m<0.0)
	{
		p = (2 * dy) - dx;
		x = x1;
		y = y1;
		temp = x2;
		putpixel(x, y, 15);
		while(x < temp)
		{
			x++;
			if(p < 0)
				p += (2 * dy);
			else
			{
				y++;
				p += 2 * (dy - dx);
			}
			putpixel(x, y, 15);
		}
	}
	else
	{
		p = (2 * dx) - dy;
		x = x1;
		y = y1;
		temp = y2;
		putpixel(x, y, 15);
		while(y < temp)
		{
			y++;
			if(p < 0)
				p += (2 * dx);
			else
			{
				x++;
				p += 2 * (dx - dy);
			}
			putpixel(x, y, 15);
		}
	}
	getch();
	closegraph();
	return 0;
}