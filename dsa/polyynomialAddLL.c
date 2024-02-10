#include <stdio.h>
#include <stdlib.h>
struct node
{
    int pow;
    int coeff;
    struct node *next;
};
struct node *newnode;
struct node *poly1 = NULL;
struct node *poly2 = NULL;
struct node *result = NULL;
struct node *temp;
struct node *prevTemp;
int coeff;
struct node * createNode(int pow, int coeff){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->pow = pow;
    newnode->coeff = coeff;
    newnode->next = NULL;
    return newnode;
}
void insert(int pow, int coeff, struct node **head){
    newnode = createNode(pow, coeff);
    if(*head == NULL){
        *head = newnode;
    }
    else{
        temp = *head;
        while(temp->next != NULL){
            prevTemp = temp;
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void add(struct node *poly1, struct node *poly2){
    struct node *temp1 = poly1;
    struct node *temp2 = poly2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->pow == temp2->pow){
            coeff = temp1->coeff + temp2->coeff;
            insert(temp1->pow, coeff, &result);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->pow > temp2->pow){
            insert(temp1->pow, temp1->coeff, &result);
            temp1 = temp1->next;
        }
        else{
            insert(temp2->pow, temp2->coeff, &result);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL){
        insert(temp1->pow, temp1->coeff, &result);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        insert(temp2->pow, temp2->coeff, &result);
        temp2 = temp2->next;
    }
}
void display(struct node *head){
    temp = head;
    while(temp->next != NULL){
        printf("%dx^%d + ", temp->coeff, temp->pow);
        temp = temp->next;
    }
    printf("%dx^%d", temp->coeff, temp->pow);
}
void main(){
    int i, len1, len2, pow, coef;
    printf("\nEnter the number of terms of the polynomial 1: ");
    scanf("%d", &len1);
    printf("\nEnter the polynomial 1: ");
    for (i = 0; i < len1; i++)
    {
        printf("\nEnter the power of the %d th term: ", i + 1);
        scanf("%d", &pow);
        printf("\nEnter the coefficient of the %d th term: ", i + 1);
        scanf("%d", &coef);
        insert(pow, coef, &poly1);
    }
    printf("\nEnter the number of terms of the polynomial 2: ");
    scanf("%d", &len2);
    printf("\nEnter the polynomial 2:");
    for (i = 0; i < len2; i++)
    {
        printf("\nEnter the power of the %d th term: ", i + 1);
        scanf("%d", &pow);
        printf("\nEnter the coefficient of the %d th term: ", i + 1);
        scanf("%d", &coef);
        insert(pow, coef, &poly2);
    }
    printf("\nPolynomial 1: ");
    display(poly1);
    printf("\nPolynomial 2: ");
    display(poly2);
    add(poly1, poly2);
    printf("\nResultant polynomial after addition: ");
    display(result);
}
