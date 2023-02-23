#include <stdio.h>

#define int long long int

void parenthesisCounter(char* answer, int curr, int open, int close, int max, int* counter)
{
    if (close == max && open == max)
    {
        (*counter)++;
        return ;
    }
    else
    {
        if (open < max)
        {
            answer[curr] = '(';
            parenthesisCounter(answer, curr + 1, open + 1, close, max, counter);
        }
        if (open > close)
        {
            answer[curr] = ')';
            parenthesisCounter(answer, curr + 1, open, close + 1, max, counter);
        }
    }
}

void printParenthesis(char* answer, int curr, int open, int close, int max)
{
    if (close == max && open == max)
    {
        printf("%s \n", answer);
        return;
    }
    else
    {
        if (open < max)
        {
            answer[curr] = '(';
            printParenthesis(answer, curr + 1, open + 1, close, max);
        }
        if (open > close)
        {
            answer[curr] = ')';
            printParenthesis(answer, curr + 1, open, close + 1, max);
        }
    }
}

void main()
{
    FILE *file;
    file = fopen("A.txt", "r");

    int length;
    fscanf(file, "%lld", &length);

    char answer[100];
    int answerCount = 0;

    parenthesisCounter(answer, 0, 0, 0, length / 2, &answerCount);

    printf("%lld\n", answerCount);
    printParenthesis(answer, 0, 0, 0, length / 2);
}