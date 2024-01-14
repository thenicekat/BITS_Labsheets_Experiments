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

Node *mergeLists(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *temp = NULL;

    if (head1->data < head2->data)
    {
        temp = head1;
        temp->next = mergeLists(head1->next, head2);
    }
    else
    {
        temp = head2;
        temp->next = mergeLists(head1, head2->next);
    }

    return temp;
}

Node *findMid(Node *head)
{
    Node *temp = head;
    int counter = 1;
    while (temp->next != NULL)
    {
        counter++;
        temp = temp->next;
    }

    int n = 1;
    temp = head;
    while (n != (counter) / 2)
    {
        n++;
        temp = temp->next;
    }
    return temp;
}

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* mid = findMid(head);

    Node *front = head;
    Node *back = mid->next;
    mid->next = NULL;

    front = sortList(front);
    back = sortList(back);

    head = mergeLists(front, back);

    return head;
}

// Function definition goes here
int main(void)
{
    Node *head = readList();
    Node *sorted = sortList(head);
    printList(sorted);
    freeList(head);
    freeList(sorted);
    // Function calls go here
    return 0;
}