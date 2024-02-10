#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode, *temp, *root;

struct node *create(int data){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node *insert(struct node *root, int data){
    if(root == NULL)
        root = create(data);
    else if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
void preorder(struct node *root){
    if(root != NULL){
        printf("%d, ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d, ", root->data);
    }
}
void main(){
    int ch, data;
    while(1){
        printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                printf("Bye");
                exit(0);
        }
    }
}
