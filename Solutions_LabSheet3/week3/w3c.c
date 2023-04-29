#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
Problem C: Dyad Aggregate
Difficulty: Easy

This is a variation of Two Sum problem. Since the input sequence is sorted, 
we can use two pointers (left and right) to solve it. 
- We initialize the left pointer to the head of the linked list and 
right pointer to the tail of the linked list.
- We run a while loop until the left and right pointer do not meet.
- In every iteration, we check the sum of the nodes pointed to by
the left and right pointers. 
    - If the sum is less than target, then we increment the left pointer
    - Else if the sum is greater than target, then we decrement the right pointer
    - Else, we have found two distinct nodes whose values sum up to the target so
    we can return 1
- If we exit the while loop without returning 1, that means there are no two
distinct nodes in the linked list whose values sum up to the target. So we can
return 0

In the worst case the while loop will run for n iterations, so the time complexity 
would be O(n)

Other variations of two sum: https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
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
Node *readList()
{
    int n;
    scanf("%d", &n);

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

int twoSum(Node *head, int target) 
{
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    Node *left = head;
    Node *right = tail;
    while (left != right)   // can also do left->data != right->data here, since values are distinct
    {
        int sum = left->data + right->data;
        if (sum < target)
            left = left->next;
        else if (sum > target)
            right = right->prev;
        else
            return 1;
    }
    return 0;
}

// Function definition goes here
int main()
{
    int k;
    scanf("%d", &k);
    Node *head = readList();
    int ans = twoSum(head, k);
    printf("%d\n", ans);
    freeList(head);
    return 0;
}