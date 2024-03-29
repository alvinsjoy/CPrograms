#include <stdio.h>
#include <stdlib.h>
#define max 100
int q[max];
int rear = -1;
int front = -1;
void enqueue(int item)
{
	if (rear == max - 1)
		printf("Queue is full.");
	else if (front == -1 && rear == -1)
	{
		front++;
		q[++rear] = item;
	}
	else
		q[++rear] = item;
}
void dequeue()
{
	int item;
	if (front == -1)
		printf("Queue is empty");
	else if (front == rear)
	{
		item = q[front];
		front = rear = -1;
	}
	else
	{
		item = q[front++];
	}
	printf("\nDeleted: %d", item);
}
void display()
{
	for (int i = front; i <= rear; i++)
	{
		printf("%d ", q[i]);
	}
}
void main()
{
	int ch = 0, item;
	while (1)
	{
		printf("\n1)Enqueue\n2)Dequeue\n3)Display Queue\n4)Exit\nEnter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter value to be added:");
			scanf("%d", &item);
			enqueue(item);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Enter a valid choice!");
		}
	}
}
