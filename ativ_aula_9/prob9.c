#include <stdio.h>
#include <string.h>
#define MAX 100

int capicua(char * str);

int main() {
    char string[MAX];
    while(fgets(string, MAX, stdin)!=NULL) {
        *strchr(string, '\n')='\0';
        if(capicua(string)) {
            printf("A string e capicua!!\n");
        } else {
            printf("A string nao e capicua :((\n");
        }
    }
}

int capicua(char * str) {
    int i, j;
    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        if(str[i]!=str[j]) {
            return 0;
        }
    }
    return 1;
}