#include <stdio.h>
#include <string.h>

void main()
{
    FILE *file;
    file = fopen("input.txt", "r");

    int x, n;
    fscanf(file, "%d\n%d", &x, &n);

    int array[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    int indexOfHalf;
    int halfNumber = (x + 1) / 2;

    for (int i = 0; i < n; i++)
    {
        if (array[i] == halfNumber){
            indexOfHalf = i;
            break;
        }
    }

    for(int i=indexOfHalf; i>=0; ){
        if(array[i] > halfNumber){
            int temp = array[i];
            for (int j = i; j <= indexOfHalf; j++)
            {
                array[j] = array[j + 1];
            } 
            array[indexOfHalf] = temp;  
            indexOfHalf--;
        }
        else{
            i--;
        }
    }

    for (int i = indexOfHalf; i < n; i++)
    {
        if (array[i] < halfNumber)
        {
            int temp = array[i];
            for (int j = i; j > indexOfHalf; j--)
            {
                array[j] = array[j - 1];
            }
            array[indexOfHalf] = temp;
            indexOfHalf++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}