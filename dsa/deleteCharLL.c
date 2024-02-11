// Delete all instances of given character in a string using Linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node *next;
};
struct node *newnode, *head, *temp, *prev, *deleted;
struct node *create(char data){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insert(char data){
    newnode = create(data);
    if(head == NULL)
        head = newnode;
    else{
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}
void display(struct node *head){
    while(head != NULL){
        printf("%c", head->data);
        head = head->next;
    }
}
void deleteChar(char c){
    temp = head;
    prev = NULL;
    while(temp != NULL){
        if(temp->data == c){
            if(prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;
            deleted = temp;
            temp = temp->next;
            free(deleted);
        }
        else{
            prev = temp;
            temp = temp->next;
        }
        
    }
    printf("Character %c deleted", c);
}
void main(){
    char c;
    int i = 0;
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]", &str);
    while(str[i] != '\0'){
        insert(str[i]);
        i++;
    }
    printf("\nThe current string: ");
    display(head);
    printf("\nEnter the character to delete: ");
    scanf(" %c", &c);
    deleteChar(c);
    printf("\nThe current string: ");
    display(head);
}