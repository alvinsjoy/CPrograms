#include <stdio.h>
#include <stdlib.h>
struct node{
    char data;
    struct node *next;
    struct node *prev;
};
struct node *newnode, *head, *tail, *prevtemp;
struct node *create(char data){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void insert(char data){
    newnode = create(data);
    if(head == NULL)
        head = tail = newnode;
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
int palindrome(){
    struct node *start = head;
    struct node *end = tail;
    while(start != end){
        if(start-> data != end->data){
            return 0;
        }
        start = start->next;
        end = end->prev;
    }
    return 1;
}
void main(){
    char str[50];
    printf("Enter the string: ");
    scanf("%[^\n]", &str);
    int i = 0;
    while(str[i] != '\0'){
        insert(str[i]);
        i++;
    }
    if(palindrome())
        printf("%s is a palindrome", str);
    else
        printf("%s is not a palindrome", str);
}