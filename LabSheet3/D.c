#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define int long long int

typedef struct node_t
{
    int data;
    struct node_t *prev;
    struct node_t *next;
} Node;

int max(int a, int b)
{
    return a > b ? a : b;
}

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
}

Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
        head = newNode;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

Node *readList(FILE *file)
{
    int num;
    fscanf(file, "%lld", &num);

    Node *head = NULL;

    for (int i = 0; i < num; i++)
    {
        int temp;
        fscanf(file, "%lld", &temp);
        if (head == NULL)
            head = addToList(head, temp);
        else
        {
            addToList(head, temp);
        }
    }

    return head;
}

Node *printList(Node *head)
{
    Node *cur = head;
    while (cur != NULL)
    {
        printf("%lld ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

Node *printListReverse(Node *head)
{
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    while (cur != NULL)
    {
        printf("%lld ", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

void splitTeams(Node *head)
{
    Node *left = head;
    Node *right = head;
    while (right->next != NULL)
    {
        right = right->next;
    }

    int maxLeft = 0;
    int maxRight = 0;

    int leftC = 1;
    int rightC = 1;

    int leftSum = left->data;
    int rightSum = right->data;

    while (left != right)
    {
        printf("%d %d\n", leftSum, rightSum);
        if (leftSum == rightSum)
        {
            maxLeft = max(leftC, maxLeft);
            maxRight = max(rightC, maxRight);

            left = left->next;
            if (left != right)
            {
                leftSum += left->data;
                leftC++;
            }
        }

        if (leftSum < rightSum)
        {
            left = left->next;
            if (left != right)
            {
                leftSum += left->data;
                leftC++;
            }
        }

        if (leftSum > rightSum)
        {
            right = right->prev;
            if (left != right)
            {
                rightSum += right->data;
                rightC++;
            }
        }
    }

    printf("%lld %lld", maxLeft, maxRight);
}

void main()
{
    FILE *file = fopen("D.txt", "r");
    Node *input = readList(file);
    printList(input);
    splitTeams(input);
}