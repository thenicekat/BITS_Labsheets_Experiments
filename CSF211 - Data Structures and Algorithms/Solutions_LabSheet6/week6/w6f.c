#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Dequeue Dequeue;

struct Node{
    int val;
    Node *next;
    Node *prev;
};

struct Dequeue{
    Node *head;
    Node *tail;
};

Node *create_node(int val){
    Node *temp = malloc(sizeof(Node));
    temp -> val = val;

    return temp;
}

void insert_front(Dequeue *q, int val){
    if(q -> head == NULL){
        q -> head = q -> tail = create_node(val);
        return;
    }

    Node *temp = create_node(val);
    temp -> next = q -> head;
    q -> head -> prev = temp;
    q -> head = temp;

    return;
}

void insert_back(Dequeue *q, int val){
    if(q -> tail == NULL){
        q -> head = q -> tail = create_node(val);
        return;
    }

    Node *temp = create_node(val);
    temp -> prev = q -> tail;
    q -> tail -> next = temp;
    q -> tail = temp;

    return;
}

void pop_front(Dequeue *q){
    if(!q || !q -> head)
        return;
    
    Node *temp = q -> head;
    q -> head = q -> head -> next;
    free(temp);
}

void pop_back(Dequeue *q){
    if(!q || !q -> tail)
        return;
    
    Node *temp = q -> tail;
    q -> tail = q -> tail -> prev;
    free(temp);
}

void print_dequeu(Dequeue *q){
    Node *temp = q -> head;
    while(temp){
        printf("%d ", temp -> val);
        temp = temp -> next;
    }
}

void delete_queue(Dequeue *q){
    while(q -> head){
        Node *temp = q -> head;
        q -> head = q -> head -> next;
        free(temp);
    }
    free(q);
}

int get_front(Dequeue* q){
    return q -> head -> val;
}

int get_back(Dequeue* q){
    return q -> tail -> val;
}


int main(){

    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
    }

    Dequeue *q = malloc(sizeof(Dequeue));

    for(int i = 0; i < n; i++){
        if(!q -> head || get_front(q) > a[i])
            insert_front(q, a[i]);
        else
            insert_back(q, a[i]);
    }

    print_dequeu(q);
    printf("\n");

    delete_queue(q);

    return 0;
}