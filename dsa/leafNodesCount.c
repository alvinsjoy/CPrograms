#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode, *root;
int count = 0;
struct node *create(int data){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int leafNode(struct node *root){
    if(root != NULL){
        if(root->left == NULL && root->right == NULL)
            count++;
        else{
            leafNode(root->left);
            leafNode(root->right);
        }
    }
    return count;
}
int main(){
    int count;
    struct node *root = create(1);
    root->left        = create(2);
    root->right       = create(3);
    root->left->left  = create(4);
    root->left->right = create(5);
    count = leafNode(root);
    printf("Number of leaf nodes: %d", count);
}