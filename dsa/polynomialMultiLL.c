#include <stdio.h>
#include <stdlib.h>

struct node{
    int powr;
    int coeff;
    struct node *next;
};
struct node *newnode, *poly1 = NULL, *poly2 = NULL, *result = NULL, *temp = NULL;
int coeff, powr;
struct node *createnode(int powr, int coeff){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->powr = powr;
    newnode->coeff = coeff;
    newnode->next = NULL;
    return newnode;
}
struct node *insert(int powr, int coeff, struct node *head){
    newnode = createnode(powr, coeff);
    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return head;
}
struct node *removeDupes(struct node *head){
    struct node *temp1 = head, *temp2;
    while(temp1 != NULL && temp1->next != NULL){
        temp2 = temp1;
        while(temp2->next != NULL){
            if(temp1->powr == temp2->next->powr){
                temp1->coeff = temp1->coeff + temp2->next->coeff;
                temp = temp2->next;
                temp2->next = temp2->next->next;
                free(temp);
            }
            else
                temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head;
}
void multi(struct node *poly1, struct node *poly2){
    struct node* temp1 = poly1, *temp2 = poly2;
    while(temp1 != NULL){
        while(temp2 != NULL){
            coeff = temp1->coeff * temp2->coeff;
            powr = temp1->powr + temp2->powr;
            result = insert(powr, coeff, result);
            temp2 = temp2->next;
        }
        temp2 = poly2;
        temp1 = temp1->next;
    }
    result = removeDupes(result);
}
void display(struct node *head){
    while(head->next != NULL){
        printf("%dx^%d + ", head->coeff, head->powr);
        head = head->next;
    }
    printf("%d x^%d", head->coeff, head->powr);
}
void main(){
    int i, len1, len2, powr, coef;
    printf("\nEnter the number of terms of the polynomial 1: ");
    scanf("%d", &len1);
    printf("\nEnter the polynomial 1: ");
    for (i = 0; i < len1; i++)
    {
        printf("\nEnter the power of the %d th term: ", i + 1);
        scanf("%d", &powr);
        printf("\nEnter the coefficient of the %d th term: ", i + 1);
        scanf("%d", &coef);
        poly1 = insert(powr, coef, poly1);
    }
    printf("\nEnter the number of terms of the polynomial 2: ");
    scanf("%d", &len2);
    printf("\nEnter the polynomial 2:");
    for (i = 0; i < len2; i++)
    {
        printf("\nEnter the power of the %d th term: ", i + 1);
        scanf("%d", &powr);
        printf("\nEnter the coefficient of the %d th term: ", i + 1);
        scanf("%d", &coef);
        poly2 = insert(powr, coef, poly2);
    }
    printf("\nPolynomial 1: ");
    display(poly1);
    printf("\nPolynomial 2: ");
    display(poly2);
    multi(poly1, poly2);
    printf("\nResultant polynomial after multiplication: ");
    display(result);
}