// Implement Circular Queue
// CP Compre - Last Question

#include <stdio.h>

#define int long long int

typedef struct node_t {
    struct node_t* prev;
    int data;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    return newNode;
}

Node* add_to_queue(Node* front, int data){
    Node* newNode = createNode(data);
    if(front == NULL){
        front = newNode;
    }else{

    }
}

void main(){
    FILE* file;
    file = fopen("H.txt", "r");
    

}