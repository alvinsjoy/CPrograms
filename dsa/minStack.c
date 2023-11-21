#include <stdio.h>
int stack[100],minstack[1];
int top1=-1;
int top2=0;
void push(int n)
{
	int p;
	if(top1>=n-1)
	{
		printf("Stack is full, cannot push\n");
	}
	else
	{
		printf("Enter the element to be pushed:");
		scanf("%d",&p);
		stack[++top1]=p;
		minstack[top2]=stack[0];
		if(stack[top1]<minstack[0])
		{
			minstack[top2]=stack[top1];
			top1++;
		}
	}
}
void display()
{
	printf("Minimum element is: %d\n",minstack[0]);
}
void main()
{
	int n,ch;
	printf("Enter the limit of the stack:\n");
	scanf("%d",&n);
	while(1)
	{
		printf("1)push\n2)Display\n3)Exit\nEnter your choice:");
		scanf("%d",&ch);
		if(ch==1)
			push(n);
		else if(ch==2)
			display();
		else if(ch==3)
			break;
		else
			printf("Enter a valid option\n");	
		
	}
}

