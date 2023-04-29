#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int val;
    Node *prev;
    Node *next;
};

Node* insert(Node *head, int v){

    if(head == NULL){
        head = malloc(sizeof(Node));
        head -> val = v;
        head -> next = head -> prev = head;
        return head;
    }

    Node *tail = head -> prev;
    Node *temp = malloc(sizeof(Node));
    temp -> val = v;
    temp -> next = head;
    head -> prev = temp;
    tail -> next = temp;
    temp -> prev = tail;

    return head;  
}

void delete(Node *curr){
    Node *curr_prev = curr -> prev;
    Node *curr_next = curr -> next;

    curr_prev -> next = curr_next;
    curr_next -> prev = curr_prev;
}

int solve(Node *start, int k){

    if(start -> next == start)
        return start -> val;

    Node *temp = start;
    for(int i = 0; i < k - 1; i++){
        temp = temp -> next;
    }

    start = temp -> next;
    delete(temp);

    return solve(start, k);
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    Node *head = NULL;
    for(int i = 1; i <= n; i++){
        head = insert(head, i);
    }

    printf("%d\n", solve(head, k));

    return 0;
}