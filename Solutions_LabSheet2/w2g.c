#include <assert.h>

#include <stdio.h>

#include <stdlib.h>

struct Node_t {
    int data;
    struct Node_t * next;
};
typedef struct Node_t Node;
// Creates a new node with given value and returns a pointer to it
Node * createNode(int value) {
    Node * newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}
// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node * addToList(Node * head, int val) {
    Node * newNode = createNode(val);
    if (head == NULL) {
        return newNode;
    }
    Node * cur = head;
    while (cur -> next != NULL) {
        cur = cur -> next;
    }
    cur -> next = newNode;
    return newNode;
}
// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node * readList() {
    int n;
    scanf("%d", & n);
    Node * head = NULL;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", & x);

        if (head == NULL) {
            head = addToList(head, x);
        } else {
            addToList(head, x);
        }
    }
    return head;
}
// Prints the values stored in the nodes of the given singly linked list
void printList(Node * head) {
    Node * ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
    return;
}
// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node * head) {
    Node * cur, * nxt;
    cur = head;
    while (cur != NULL) {
        nxt = cur -> next;
        free(cur);
        cur = nxt;
    }
}

Node* rearrangeList(Node *head){
    Node *head_odd = head, *tail_odd = head;
    Node *head_even = head -> next, *tail_even = head -> next;

    while(tail_odd -> next && tail_even -> next){
        tail_odd -> next = tail_odd -> next -> next;
        tail_even -> next = tail_even -> next -> next;

        tail_odd = tail_odd -> next;
        tail_even = tail_even -> next;
    }

    if(tail_even)
        tail_even -> next = NULL;
    
    tail_odd -> next = head_even;

    return head_odd;
}

Node* removeRepeatedNodes(Node *head){
    Node *temp_head = createNode(0);
    temp_head -> next = head;

    Node *itr = temp_head;
    while(itr -> next && itr -> next -> next){
        if(itr -> next -> data == itr -> next -> next -> data){
            int val = itr -> next -> data;
            while(itr -> next && itr -> next -> data == val){
                itr -> next = itr -> next -> next;
            }
        }
        else{
            itr = itr -> next;
        }
    }

    head = temp_head -> next;
    free(temp_head);

    return head;

}

// Function definition goes here
int main(void) {
    // Function calls go here
    Node *head = readList();
    head = removeRepeatedNodes(head);
    printList(head);
    freeList(head);
    
    return 0;
}