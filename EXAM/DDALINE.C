#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void main()
{
	int gdriver = DETECT, gmode;
	int x1,x2,y1,y2,i;
	float m,dx,dy,step,x,y;
	initgraph(&gdriver, &gmode, "");
	printf("Enter first point's coordinates: ");
	scanf("%d%d",&x1,&y1);
	printf("Enter second point's coordinates: ");
	scanf("%d%d",&x2,&y2);
	dx = x2 - x1;
	dy = y2 - y1;
	m = dy / dx;
	if(m>1.0)
	{
		step = dy;
	}
	else
	{
		step = dx;
	}
	dx = dx / step;
	dy = dy / step;
	x = x1;
	y = y1;
	for(i = x1; i <= x2; i++)
	{
		x = x + dx;
		y = y + dy;
		putpixel((int)x,(int)y,15);
	}
	getch();
	closegraph();
}