#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO: Modify function mystrcat so it does the following: 
//This function should create a string allocated on heap. This string should be the two
//input strings combined (this is called "concatenation" or "concatenating" the strings)
//The function should return this combined string.
//You ARE NOT allowed to use strcat or strcpy
//You ARE allowed to use strlen
//Please only modify mystrcat
char* mystrcat(char * first, char * second){

    char *temp1 = first;
    char *temp2 = second;

    char *total_end = malloc(strlen(first)+strlen(temp2)+1);
    char *total = total_end;

    for(int i = 0; i < strlen(first);i++) {
        *total = *temp1;
        temp1++;
        total++;
    }
    for(int i = 0; i < strlen(second);i++) {
        *total = *temp2;
        temp2++;
        total++;
    }
    return total_end;



}

int main(void) {
    char first[21];
    printf("Please enter first string(less than 20 chars):\n");
    scanf("%s", first);
    char second[21];
    printf("Please enter second string(less than 20 chars):\n");
    scanf("%s", second);

    char * combined = mystrcat(first, second);

    printf("%s + %s = %s\n", first, second, combined);

    free(combined);
}