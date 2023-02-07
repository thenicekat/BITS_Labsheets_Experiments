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

Song* playNext(FILE* file, Song* head, Song* curr){
    int val;
    fscanf(file, "%d", &val);

    //Search for it in playlist
    Song* temp = head;
    int found = 0;
    while(temp->next != NULL){
        if(temp->data == val){
            found = 1;
            // a b c d
            // a b d
            // Remove temp's connection
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            //a | b d
            // Separate all songs
            Song* rest = curr->next;

            //a | c b d
            temp->next = rest;
            rest->prev = temp;

            // a c b d
            temp->prev = curr;
            curr->next = temp;
            break;
        }else{
            temp = temp->next;
        }
    }

    if(found == 0){
        Song* newSong = createSong(val);
        Song* tempNext = curr->next;
        curr->next = newSong;
        newSong->prev = curr;
        newSong->next = tempNext;
        tempNext->prev = newSong;
    }
}

void main()
{
    FILE* file = fopen("B.txt", "r");
    Song *head = readSongs(file);
    Song* curr = head;

    int operation;
    while (fscanf(file, "%d", &operation))
    {
        if (operation == 1)
        {
            int song;
            fscanf(file, "%d", &song);
            addSong(head, song);
        }
        else if (operation == 2)
        {
            printf("%d\n", curr->data);
        }
        else if (operation == 3)
        {
            curr = forward(curr);
        }
        else if (operation == 4)
        {
            curr = previous(curr);
        }
        else if(operation == 5){
            break;
        }
        else if(operation == 6){
            playNext(file, head, curr);
        }
    }
}