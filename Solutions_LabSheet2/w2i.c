#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getCode(char course[]){
    char *code = malloc(5 * sizeof(char));

    if(!strcmp(course, "CS"))
        strcpy(code, "A7");
    
    else if(!strcmp(course, "ECE"))
        strcpy(code, "AA");
    
    else
        strcpy(code, "A3");
    
    return code;
}

int main(){

    char email[40];
    scanf("%s", email);

    char course[10];
    scanf("%s", course);

    char year[10] = {0}, id[10] = {0};

    strncpy(year, email + 1, 4);
    strncpy(id, email + 5, 4);

    char studentId[50];

    strcpy(studentId, year);
    strcat(studentId, getCode(course));
    strcat(studentId, "PS");
    strcat(studentId, id);
    strcat(studentId, "H");

    printf("%s\n", studentId);

}