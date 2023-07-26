#include <stdio.h>
struct point
{
	int x;
	int y;
} p[2];
void main()
{
	printf("Enter point 1: ");
	scanf("%d %d",&p[0].x,&p[0].y);
	printf("Enter second point: ");
	scanf("%d %d",&p[1].x,&p[1].y);
	p[2].x=p[0].x+p[1].x;
	p[2].y=p[0].y+p[1].y;
	printf("The new point is %d %d",p[2].x,p[2].y);   
}
