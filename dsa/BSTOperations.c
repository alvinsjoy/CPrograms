#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode, *root, *temp;
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
void search(struct node *root, int key){
    if(root == NULL)
        printf("\nElement not found");
    else if(root->data == key)
        printf("\nElement %d found", key);
    else if(key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}
void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}
struct node *minNode(struct node *root){
    while(root->left != NULL)
        root = root->left;
    return root;
}
struct node *delete(struct node *root, int key){
    if(root == NULL){
        printf("\nElement %d not found", key);
        return NULL;
    }
    else if(key < root->data)
        root->left = delete(root->left, key);
    else if(key > root->data)
        root->right = delete(root->right, key);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL || root->right == NULL){
            temp = root;
            if(root->left != NULL)
                root = root->left;
            else
                root = root->right;
            free(temp);
        }
        else{
            temp = minNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
        printf("\nElement %d deleted", key);
    }
    return root;
}
void main(){
    int ch, data;
    while(1){
        printf("\n1.Insert\n2.Search\n3.Display\n4.Delete\n5.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                search(root, data);
                break;
            case 3:
                printf("Inorder traversal:\n");
                inorder(root);
                break;
            case 4:
                printf("Enter the element to be deleted: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 5:
                printf("Bye");
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }
}