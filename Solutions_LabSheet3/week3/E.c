#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*
Problem E: Rotating Places

This is a simple problem of doubly linked list implementation, we will remove the last node and add it to the front k times.
*/
 
struct Node_t
{
    int data;
    struct Node_t *prev;
    struct Node_t *next;
};
typedef struct Node_t Node;
 
// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
 
// Creates a doubly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList(int n)
{
    // int n;
    // scanf("%d", &n);
 
    Node *head = NULL;
    Node *last = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
 
        Node *newNode = createNode(x);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            last->next = newNode;
            newNode->prev = last;
        }
        last = newNode;
    }
    return head;
}
 
// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL)
    {
        nxt = cur->next;
 
        free(cur);
        cur = nxt;
    }
}

void printList(Node *head){
    Node *temp = head;
    while(temp){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
    return;
}


Node *rotateList(Node *head, int k){

    Node *tail = head;
    while(tail -> next){
        tail = tail -> next;
    }

    while(k--){
        Node *temp = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        temp -> next = head;
        head -> prev = temp;
        temp -> prev = NULL;
        head = temp;
    }

    return head;
}

 
// Function definition goes here
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    k %= n;
    Node *head = readList(n);
    head = rotateList(head, k);
    printList(head);
    freeList(head);
    return 0;
}