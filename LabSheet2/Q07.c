#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node_t
{
    int data;
    struct Node_t *next;
};

typedef struct Node_t Node;

// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}

// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}

// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
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

Node *removeRepeatedNodes(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
        
    Node *temp = head;
    Node *prev = head;

    Node *currentPointer = head;
    // Pointer pointing to the first unique element of the series

    int data = temp->next->data;
    while (temp != NULL && temp->next != NULL)
    {
        // printf("\n%d %d %d %d->", data, temp->data, temp->next->data, currentPointer->data);
        // printList(head);
        if (data == temp->data && data == head->data)
        {
            head = temp->next;
            temp = temp->next;
            currentPointer = head;
        }
        else if (data == temp->data)
        {
            while (temp->data == data)
            {
                temp = temp->next;
            }
            currentPointer->next = temp;
            if(temp->next == NULL || temp->data != temp->next->data) currentPointer = temp;
            data = temp->data;
        }
        else
        {
            data = temp->data;
            if (temp->next == NULL || temp->next->data != data)
            {
                temp = temp->next;
            }
        }
    }
    return head;
}

// Function definition goes here
int main(void)
{
    Node *head = readList();
    Node *newList = removeRepeatedNodes(head);
    printList(newList);
    freeList(head);
    // Function calls go here
    return 0;
}