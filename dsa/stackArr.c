#include<stdio.h>
int top=-1;
int stack[100],n;
void print()
{
	printf("The stack now is:\n");
	for(int i=0;i<=top;i++)
	{
		printf("%d,",stack[i]);
	}
	printf("\n");
}

void push(int n)
{
	int p;
	if(top>=n-1)
	{
		printf("Stack is full, cannot push\n");
	}
	else
	{
		printf("Enter the element to be pushed:");
		scanf("%d",&p);
		stack[++top]=p;
	}
	print();
	
}

void pop()
{
	int p;
	if(top==-1)
	{
		printf("Stack is empty, cannot pop\n");
	}
	else
	{
		top--;
	}
	print();
	
}
void peak()
{
	if(top==-1)
	{
		printf("Stack empty");
	}
	else
	{
		printf("%d\n",stack[top]);
	}
}
void main()
{
	int n,ch;
	printf("Enter the limit of the stack:\n");
	scanf("%d",&n);
	while(1)
	{
		printf("1)push\n2)pop\n3)peak\n4)exit\nEnter your choice:");
		scanf("%d",&ch);
		if(ch==1)
			push(n);
		else if(ch==2)
			pop();
		else if(ch==3)
			peak();
		else if(ch==4)
			break;	
		else
			printf("Enter a valid option");	
		
	}
}
