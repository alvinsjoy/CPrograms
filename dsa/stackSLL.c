#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *newNode;
struct node *head = NULL;
struct node *temp;
struct node *prevTemp;

struct node *create(int d)
{
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = d;
    return newNode;
}
void push(int d)
{
    newNode = create(d);
    if (head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
    }
    head = newNode;
}
void pop()
{
    if (head == NULL)
    {
        printf("Stack Empty\n");
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
        temp = NULL;
    }
}
void peek()
{
    if (head == NULL)
    {
        printf("Stack Empty\n");
    }
    else
    {
        temp = head;
        printf("Top element: %d\n", temp->data);
    }
}
void display()
{
    if (head == NULL)
    {
        printf("Stack Empty\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main()
{
    int d, ch = 0;
    while (1)
    {
        printf("1) Push\n2) Pop\n3) Peek\n4) Display\n5) Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter new node data: ");
            scanf("%d", &d);
            push(d);
            display();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Enter a valid choice");
        }
    }
}
