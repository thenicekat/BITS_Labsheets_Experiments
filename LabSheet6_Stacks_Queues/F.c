// Given an array of integers
// Need to create a new list from the given array following a sequence of operations
// In each operation, you remove the first element of the given array and add it either to the beginning of the end of the list

// We need to find the lexographically smallest list - meaning sorted list or the numbers are the smallest
// Need to implement a double-ended queue

// I am thinking using dequeue and trying to sort them the least possible way will work
// As in if the digit is greater than the first one, it goes to the back
// else it goes to the front

// let's say you have numbers 3 1 4 2 -> 1 3 4 2
#include <stdio.h>
#include <stdlib.h>

#define int long long int

typedef struct node_t
{
    struct node_t *prev;
    int data;
    struct node_t *next;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *deque_push_back(Node *front, Node *back, int val)
{
    Node *newNode = createNode(val);
    if (back == NULL)
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->prev = newNode;
        newNode->next = back;
        back = back->prev;
    }
    return back;
}

Node *deque_push_front(Node *front, Node *back, int val)
{
    Node *newNode = createNode(val);
    if (front == NULL)
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        front->next = newNode;
        newNode->prev = front;
        front = front->next;
    }
    return front;
}

void deque_display(Node *back)
{
    Node *temp = back;
    if (temp == NULL)
        return;

    while (temp->next != NULL)
    {
        printf("%lld ", temp->data);
        temp = temp->next;
    }
    printf("%lld ", temp->data);
}

void main()
{
    FILE *file;
    file = fopen("F.txt", "r");

    int noOfTestCases;
    fscanf(file, "%lld", &noOfTestCases);

    for (int i = 0; i < noOfTestCases; i++)
    {
        printf("--------Test Case No: %lld----------\n", i);

        int inputLength;
        fscanf(file, "%lld", &inputLength);

        int input[inputLength];
        for (int i = 0; i < inputLength; i++)
            fscanf(file, "%lld", &input[i]);

        Node *front = NULL;
        Node *back = NULL;

        for (int i = 0; i < inputLength; i++)
        {
            if (front == NULL && back == NULL)
            {
                front = deque_push_front(front, back, input[i]);
                back = front;
            }
            else
            {
                if (back->data > input[i])
                {
                    back = deque_push_back(front, back, input[i]);
                }
                else
                {
                    front = deque_push_front(front, back, input[i]);
                }
            }
        }

        deque_display(back);

        printf("\n------------------------------------\n");
    }
}