#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
Problem D: Two Teams

This problem can be solved using two pointer method as in a doubly linked list one can traverse to the previous node.
We keep track of the prefix (leftSum) and suffix (rightSum) sum of the list, by making use of two pointers - left and right.
We also keep track of how many nodes are accounted for the prefix and suffix sum - leftCnt and rightCnt.
We will use a while loop to traverse the linked list using the left and right pointers, the breaking condition would be when left and right point to the same node.
    1) If the prefix and suffix sum are the same then the first leftCnt players and last rightCnt players can be divided into Team A and B, so we will update our answer for the same
        - We will advance the left pointer to the next node and right pointer to its previous node
        - We will update leftSum and rightSum to account for these nodes
        - We will also update leftCnt and rightCnt
    
    2) If the prefix sum (leftSum) is less than the suffix sum (rightSum), then we will advance the left pointer only
        - Update leftSum
        - Update leftCnt
    
    3) If the prefix sum (leftSum) is greater than the suffix sum (rightSum), then we will only advance the right pointer to its previous node.
        - Update rightSUm
        - Update rightCnt.
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

int max(int a, int b){
    return a > b ? a : b;
}
 
int* twoSum(Node *head) 
{
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
 
    Node *left = head;
    Node *right = tail;

    int *ans = malloc(2 * sizeof(int));
    ans[0] = ans[1] = 0;

    int leftSum = left -> data, rightSum = right -> data;
    int leftCnt = 1, rightCnt = 1;

    while (left != right)   // can also do left->data != right->data here, since values are distinct
    {

        if(leftSum == rightSum){
            ans[0] = leftCnt;
            ans[1] = rightCnt;

            left = left -> next;
            // right = right -> prev;

            leftCnt++;
            // rightCnt++;

            leftSum += left -> data;
            // rightSum += right -> data;
        }

        else if(leftSum < rightSum){
            left = left -> next;
            leftCnt++;
            leftSum += left -> data;
        }

        else{
            right = right -> prev;
            rightCnt++;
            rightSum += right -> data;
        }
    }
    return ans;
}
 
// Function definition goes here
int main()
{

    Node *head = readList();
    int *ans = twoSum(head);
    printf("%d %d\n", ans[0], ans[1]);
    freeList(head);
    return 0;
}