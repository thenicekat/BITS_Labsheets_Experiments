#include <stdio.h>
#include <string.h>

void main()
{
    FILE *file;
    file = fopen("input.txt", "r");

    int n;
    fscanf(file, "%d", &n);

    int matrix[2*n-1][2*n-1];

    int isVertical = 0;
    int isHorizontal = 1;

    int number = (n * n) * 2;

    // Default Values
    for (int i = 0; i < 2*n-1; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            matrix[i][j] = 0;
        }
    }

    int rowNumberB = 2*(n-1);
    int colNumberB = 2*(n-1);

    int rowNumberL = 2*(n-1);
    int colNumberL = 0;

    int rowNumberT = 0;
    int colNumberT = 0;

    int rowNumberR = 0;
    int colNumberR = 2*(n-1);

    while (number > 0)
    {
        // Bottom;
        for (int i = colNumberB; i >= 2*(n-1)-colNumberB; i-=2)
        {
            matrix[rowNumberB][i] = number;
            if(matrix[rowNumberB][i-1] != -2) matrix[rowNumberB][i+1] = -1;
            number -= 2;
        }
        rowNumberB-=2;
        colNumberB-=2;

        // Left;
        for (int i = rowNumberL - 2; i >= colNumberL; i-=2)
        {
            matrix[i][colNumberL] = number;
            if(matrix[i+1][colNumberL] != -1) matrix[i+1][colNumberL] = -2;
            number -= 2;
        }
        rowNumberL-=2;
        colNumberL+=2;

        // Top;
        for (int i = rowNumberT + 2; i < 2*n-1 - colNumberT; i+=2)
        {
            matrix[rowNumberT][i] = number;
            if(matrix[rowNumberT][i-1] != -2) matrix[rowNumberT][i-1] = -1;
            number -= 2;
        }
        rowNumberT+=2;
        colNumberT+=2;

        // Right;
        for (int i = rowNumberR + 2; i < colNumberR; i+=2)
        {
            matrix[i][colNumberR] = number;
            if(matrix[i-1][colNumberR] != -1) matrix[i-1][colNumberR] = -2;
            number -= 2;
        }
        rowNumberR+=2;
        colNumberR-=2;
    }

    // Printing Function
    for (int i = 0; i < 2*n-1; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            if(matrix[i][j] == -1) printf("---");
            else if(matrix[i][j] == -2) printf(" | ");
            else if(matrix[i][j] == 0 && i%2 == 0) printf("   ");
            else if(matrix[i][j] == 0 && i%2 == 1 && j%2 == 0) printf("   ");
            else if(matrix[i][j] == 0 && i%2 == 1 && j%2 == 1) printf("    ");
            else printf("%04d", matrix[i][j]);
        }
        printf("\n");
    }
}