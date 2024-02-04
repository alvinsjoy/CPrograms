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

struct node *create(int d)
{
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = d;
    return newNode;
}
void enqueue(int d)
{
    newNode = create(d);
    if (head == NULL)
    {
        head = newNode;
        temp = head;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void dequeue()
{
    if (head == NULL)
    {
        printf("Queue Empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void display()
{
    if (head == NULL)
    {
        printf("Queue Empty\n");
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
int main()
{
    int d, ch = 0;
    while (1)
    {
        printf("1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter new node data: ");
            scanf("%d", &d);
            enqueue(d);
            display();
            break;
        case 2:
            dequeue();
            display();
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
