#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void main()
{
    struct node *root = NULL;
    int data, ch;
    while (1)
    {
        printf("\n1.Insert\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n5.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
