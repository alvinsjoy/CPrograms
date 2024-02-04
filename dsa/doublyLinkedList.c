#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *newNode;
struct node *head = NULL;
struct node *temp;
struct node *prevTemp;

struct node *create(int d)
{
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = d;
    return newNode;
}

void addElement(int d)
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
        newNode->prev = temp;
    }
}

void addAfter(int d, int p)
{
    temp = head;
    newNode = create(d);
    while (temp->data != p)
        temp = temp->next;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void addBefore(int d, int p)
{
    temp = head;
    newNode = create(d);
    while (temp->data != p)
    {
        prevTemp = temp;
        temp = temp->next;
    }
    newNode->next = temp;
    newNode->prev = prevTemp;
    if (prevTemp != NULL)
    {
        prevTemp->next = newNode;
    }
    else
    {
        head = newNode;
    }
}

void addPosition(int d, int p)
{
    int i = 1;
    temp = head;
    newNode = create(d);
    while (i < p && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (temp != NULL)
    {
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL)
        {
            temp->prev->next = newNode;
        }
        else
        {
            head = newNode;
        }
        temp->prev = newNode;
    }
    else
    {
        printf("Position exceeds the length of the list.\n");
    }
}

void deleteData(int d)
{
    temp = head;
    while (temp != NULL && temp->data != d)
    {
        prevTemp = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

void deletePosition(int p)
{
    temp = head;
    int i = 1;
    while (i < p && temp != NULL)
    {
        prevTemp = temp;
        temp = temp->next;
        i++;
    }
    if (temp != NULL)
    {
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
    else
    {
        printf("Position exceeds the length of the list.\n");
    }
}

void deleteSmall()
{
    temp = head;
    struct node *minNode = head;
    struct node *prevMinNode = NULL;
    prevTemp = NULL;
    int min = head->data;

    while (temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp->data;
            minNode = temp;
            prevMinNode = prevTemp;
        }
        prevTemp = temp;
        temp = temp->next;
    }
    if (minNode == head)
    {
        head = minNode->next;
    }
    else
    {
        prevMinNode->next = minNode->next;
    }
    if (minNode->next != NULL)
    {
        minNode->next->prev = prevMinNode;
    }
    free(minNode);
}

void search(int d)
{
    temp = head;
    int i = 1;
    while (temp != NULL && temp->data != d)
    {
        temp = temp->next;
        i++;
    }
    if (temp != NULL)
        printf("\nElement at position %d", i);
    else
        printf("\nElement not found in the list");
}

void display()
{
    if (head == NULL)
        printf("List is Empty");
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

int main()
{
    int d, ch = 0, p;
    while (1)
    {
        printf("\n1)Add Element\n2)Add after\n3)Add before\n4)Add at position\n5)Delete data\n6)Delete position\n7)Delete smallest\n8)Search\n9)Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter new node data: ");
            scanf("%d", &d);
            addElement(d);
            display();
            break;
        case 2:
            printf("Enter new node data: ");
            scanf("%d", &d);
            printf("After which element new node must be placed: ");
            scanf("%d", &p);
            addAfter(d, p);
            display();
            break;
        case 3:
            printf("Enter new node data: ");
            scanf("%d", &d);
            printf("Before which element new node must be placed: ");
            scanf("%d", &p);
            addBefore(d, p);
            display();
            break;
        case 4:
            printf("Enter new node data: ");
            scanf("%d", &d);
            printf("Position at which element new node must be placed: ");
            scanf("%d", &p);
            addPosition(d, p);
            display();
            break;
        case 5:
            printf("Enter the data to be deleted: ");
            scanf("%d", &d);
            deleteData(d);
            display();
            break;
        case 6:
            printf("Enter the position to be deleted: ");
            scanf("%d", &p);
            deletePosition(p);
            display();
            break;
        case 7:
            printf("Smallest element deleted: ");
            deleteSmall();
            display();
            break;
        case 8:
            printf("Enter element to be searched: ");
            scanf("%d", &d);
            search(d);
            break;
        case 9:
            exit(0);
        default:
            printf("Enter a valid choice!");
        }
    }
    return 0;
}
