#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int data;
    struct node_t *prev;
    struct node_t *next;
} Song;

Song *createSong(int val)
{
    Song *newSong = (Song *)malloc(sizeof(Song));
    newSong->data = val;
    newSong->prev = NULL;
    newSong->next = NULL;
}

Song *addSong(Song *head, int val)
{
    Song *newSong = createSong(val);
    if (head == NULL)
        head = newSong;
    else
    {
        Song *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newSong;
        newSong->prev = temp;
    }
}

Song *readSongs(FILE* file)
{
    int num;
    fscanf(file, "%d", &num);

    Song *head = NULL;

    for (int i = 0; i < num; i++)
    {
        int temp;
        fscanf(file, "%d", &temp);
        if (head == NULL)
            head = addSong(head, temp);
        else
        {
            addSong(head, temp);
        }
    }

    return head;
}

Song *printSongs(Song *head)
{
    Song *cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

Song *printSongsReverse(Song *head)
{
    Song *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

Song* forward(Song *head)
{
    if (head->next != NULL)
        head = head->next;
    return head;
}

Song* previous(Song *head)
{
    if (head->prev != NULL)
        head = head->prev;
    return head;
}

void main()
{
    FILE* file = fopen("A.txt", "r");
    Song *head = readSongs(file);

    int operation;
    while (fscanf(file, "%d", &operation))
    {
        if (operation == 1)
        {
            int song;
            fscanf(file, "%d", &song);
            addSong(head, song);
            printSongs(head);
        }
        else if (operation == 2)
        {
            printf("%d\n", head->data);
        }
        else if (operation == 3)
        {
            head = forward(head);
        }
        else if (operation == 4)
        {
            head = previous(head);
        }
        else{
            break;
        }
    }
}