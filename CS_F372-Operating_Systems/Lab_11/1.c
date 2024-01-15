#define _GNU_SOURCE

#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    int numberOfElements = 0;
    fscanf(fp, "%d", &numberOfElements);
    printf("Number of elements: %d\n", numberOfElements);

    int *ptr = mmap(NULL, numberOfElements * sizeof(int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

    if (ptr == MAP_FAILED)
    {
        perror("Mapping Failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numberOfElements; i++)
    {
        fscanf(fp, "%d", ptr + i);
    }

    fclose(fp);

    printf("The elements of the array => ");
    for (int i = numberOfElements - 1; i >= 0; i--)
        printf("[%d] ", ptr[i]);
    printf("\n");

    int err = munmap(ptr, 10 * sizeof(int));
    if (err != 0)
    {
        printf("UnMapping Failed\n");
        return 1;
    }
}