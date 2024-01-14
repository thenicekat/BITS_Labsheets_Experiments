// Implement Circular Queue
// CP Compre - Last Question

#include <stdio.h>
#include <stdlib.h>

#define int long long int

typedef struct node_t
{
    struct node_t *prev;
    struct node_t *next;
    int data;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *enqueue(Node *front, Node *rear, int data)
{
    Node *newNode = createNode(data);
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        // Adding node in the end
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;

        // Making them circular
        rear->next = front;
        front->prev = rear;
    }

    return rear;
}

Node *dequeue(Node *front, Node *rear, int data)
{
    if (front == NULL)
    {
        return front;
    }
    else
    {
        // Removing node from start
        Node *temp = front;
        front = front->next;
        free(temp);

        // Making them circular
        front->prev = rear;
        rear->next = front;
    }
    return front;
}

void display_queue(Node *front, Node *rear)
{
    Node *temp = front;
    printf("%lld ", temp->data);
    temp = temp->next;
    while (temp != front)
    {
        printf("%lld ", temp->data);
        temp = temp->next;
    }
}

Node* loop_through_queue(Node *front, Node *rear, int breakPoint)
{
    // display_queue(front, rear);
    // printf("\n");
    Node *temp = front;
    while (rear != front)
    {
        // Loop through until you find the node to be deleted
        for (int i = 0; i < breakPoint - 1; i++)
        {
            temp = temp->next;
        }
        Node *toBeDeleted = temp;
        // printf("::>%lld | ", toBeDeleted->data);
        // If the node to be deleted is the front, shift it forwards
        if(toBeDeleted == front){
            front = front->next;
        }
        // If the node to be deleted is the rear, shift it backwards
        else if(toBeDeleted == rear){
            rear = rear->prev;
        }

        // printf("::: %lld ::: %lld ::: ", front->data, rear->data);

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp = temp->next;
        free(toBeDeleted);

        // Printing Queue in every iteration
        // display_queue(front, rear);
        // printf("\n");
    }

    return front;
}

int main()
{
    FILE *file;
    file = fopen("H.txt", "r");

    int noOfTestCases;
    fscanf(file, "%lld", &noOfTestCases);

    for (int i = 0; i < noOfTestCases; i++)
    {
        printf("--------Test Case No: %lld----------\n", i);

        int sizeOfCircle, breakPoint;
        fscanf(file, "%lld %lld", &sizeOfCircle, &breakPoint);

        Node *front = NULL;
        Node *rear = NULL;
        for (int i = 1; i <= sizeOfCircle; i++)
        {
            if (front == NULL)
            {
                front = enqueue(front, rear, i);
                rear = front;
            }
            else
            {
                rear = enqueue(front, rear, i);
            }
        }

        front = loop_through_queue(front, rear, breakPoint);
        printf("%lld", front->data);

        printf("\n------------------------------------\n");
    }

    return 0;
}