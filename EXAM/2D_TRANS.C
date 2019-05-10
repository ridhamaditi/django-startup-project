#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void translateRectangle ( int P[][2], int T[])
{
	int gd = DETECT, gm;
	initgraph (&gd, &gm, "");  
	setcolor (2);
	rectangle (P[0][0], P[0][1], P[1][0], P[1][1]); 
	P[0][0] = P[0][0] + T[0];
	P[0][1] = P[0][1] + T[1];
	P[1][0] = P[1][0] + T[0];
	P[1][1] = P[1][1] + T[1];
	rectangle (P[0][0], P[0][1], P[1][0], P[1][1]);
} 
void main(){
	int P[2][2] = {50, 80, 120, 180};
	int T[] = {20, 10};
	translateRectangle (P, T);
	getch();
}