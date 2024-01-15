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

Node* reorder(Node* head, int n){
    int counter = 0;
    Node* counterHead = head;
    while(counterHead != NULL){
        counter++;
        counterHead = counterHead->next;
    }

    n = n%counter;

    Node* temp = head;
    while(temp->next != NULL){ temp = temp->next; }
    temp->next = head;
    head->prev = temp;

    temp = head;
    for(int i=0; i<counter-n-1; i++){
        temp = temp->next;
    }

    head = temp->next;
    head->prev->next = NULL;
    head->prev = NULL;

    return head;

}


void main(){
    FILE* file = fopen("E.txt", "r");

    int shift;
    fscanf(file, "%d ", &shift);

    Node* head = readList(file);
    
    head = reorder(head, shift);
    printList(head);
}