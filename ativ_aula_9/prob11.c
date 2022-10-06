#include <stdio.h>
#include <string.h>
#define MAX 200

int main() {
    char endereco[MAX];
    int i;
    while(fgets(endereco, MAX, stdin)) {
        strstr(endereco, "src=");
    }
}