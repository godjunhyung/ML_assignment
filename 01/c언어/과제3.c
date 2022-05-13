#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;


int arr[1024];
int n = 0;
Node* root;


Node* insert_node(Node* root, int data) // 트리에 값 삽입하기
{
    if (root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->left = root->right = NULL;
        root->data = data;
        return root;

    }
    else
    {
        if (root->data > data) 
            root->left = insert_node(root->left, data);

        else 
            root->right = insert_node(root->right, data);
    }
    return root;
}

void preorderPrint(Node* root)
{ if (root == NULL) 
        return; 
    printf("%d ", root->data);
    preorderPrint(root->left);
    preorderPrint(root->right);

}


void inorderPrint(Node* root) {
    if (root == NULL) 
        return;

    inorderPrint(root->left);
    arr[n++] = root->data;
    inorderPrint(root->right);
}


int isBST(Node* root) {

    inorderPrint(root);

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] >= arr[i + 1]) 
            return 0;
    }

    return 1;
}




void main(void)
{

    root = insert_node(root, 8);
    root = insert_node(root, 3);
    root = insert_node(root, 9);
    root = insert_node(root, NULL);
    root = insert_node(root, NULL);
    root = insert_node(root, 4); 
    root = insert_node(root, 7);



    preorderPrint(root);
    if (isBST(root))
    {
        printf("유효한 이진트리입니다\n\n");
    }
    else
    {
        printf("유효하지않은 이진트리입니다.\n\n");
    }



}

