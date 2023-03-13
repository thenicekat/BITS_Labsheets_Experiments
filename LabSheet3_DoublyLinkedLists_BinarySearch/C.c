#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t* prev;
    struct node_t* next;
} Node;

Node* createNode(int val){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
}

Node* addToList(Node* head, int val){
    Node* newNode = createNode(val);
    if(head == NULL) head = newNode;
    else{
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;        
    }
}

Node* readList(FILE* file){
    int num;
    fscanf(file, "%d", &num);

    Node* head = NULL;

    for(int i=0; i<num; i++){
        int temp;
        fscanf(file, "%d", &temp);
        if(head == NULL) head = addToList(head, temp);
        else{
            addToList(head, temp);
        }
    }

    return head;
}

Node* printList(Node* head){
    Node* cur = head;
    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

Node* printListReverse(Node* head){
    Node* cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }

    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

int findIfNumbersAddUp(Node* head, int sumNeeded){
    Node* tail;
    while(tail->next != NULL){
        tail = tail->next;
    }

    int found = 0;

    while(head != tail){
        if(head->data + tail->data > sumNeeded){
            tail = tail->prev;
        }else if(head->data + tail->data < sumNeeded){
            head = head->next;
        }else{
            found = 1;
            break;
        }
    }

    return found;
}

void main(){
    FILE* file = fopen("C.txt", "r");
    int sumNeeded;
    fscanf(file, "%d ", &sumNeeded);

    Node* input = readList(file);
    printf("%d", findIfNumbersAddUp(input, sumNeeded));
}