#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct countryS
{
    char name[1000];
    int gold;
    int silver;
    int bronze;
} Country;

void main()
{
    int n;
    scanf("%d", &n);

    Country *countries[n];

    for (int i = 0; i < n; i++)
    {
        countries[i] = (Country *)malloc(sizeof(Country));
        scanf("%s %d %d %d", countries[i]->name, &countries[i]->gold, &countries[i]->silver, &countries[i]->bronze);
    }

    for (int i = 0; i < n; i++)
    {
        int scoreOfi = countries[i]->gold * 100000 + countries[i]->silver * 1000 + countries[i]->bronze * 10;
        for (int j = i; j < n; j++)
        {
            int scoreOfj = countries[j]->gold * 100000 + countries[j]->silver * 1000 + countries[j]->bronze * 10;
            if(scoreOfi < scoreOfj){
                Country* temp = countries[i];
                countries[i] = countries[j];
                countries[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", countries[i]->name);
    }
}

// 4
// China 4 2 10
// USA 4 4 5
// Qatar 0 5 2
// India 1 4 1