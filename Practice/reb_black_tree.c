#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int key;
    enum color_t
    {
        RED,
        BLACK
    } color;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->color = RED;
    return newNode;
}

void leftRotate(Node **root, Node *x)
{
    Node *toBeRoot = x->right;
    if (toBeRoot->left != NULL)
    {
        Node *toBeLeftRight = toBeRoot->left;
        x->right = toBeLeftRight;
        toBeRoot->left = NULL;
    }
    else
    {
        x->right = NULL;
    }

    toBeRoot->left = x;

    if(x->parent == NULL){
        *root = toBeRoot;
    }else if(x->parent->left == x){
        x->parent->left = toBeRoot;
    }else{
        x->parent->right = toBeRoot;
    }
    
    x->parent = toBeRoot;
}

void rightRotate(Node** root, Node* x){
    Node* toBeRoot = x->left;

    if(toBeRoot->right != NULL){
        Node* toBeRightLeft = toBeRoot->right;
        x->left = toBeRightLeft;
        toBeRoot->right = NULL;
    }else{
        x->left = NULL;
    }

    toBeRoot->right = x;

    if(x->parent == NULL){
        *root = toBeRoot;
    }else if(x->parent->left == x){
        x->parent->left = toBeRoot;
    }else{
        x->parent->right = toBeRoot;
    }
    
    x->parent = toBeRoot;
} 

int main(){
    
}