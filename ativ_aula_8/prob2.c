#include <stdio.h>

int main() {
    int i, j, *p_1, *p_2, **p_p_1, **p_p_2;
    i = 4;
    j = 5;
    p_1 = &i;
    p_2 = &j;
    p_p_1 = &p_2;
    p_p_2 = &p_1;

    printf("value p_1 = %p\n", p_1);
    printf("value p_2 = %d\n", *p_2);
    printf("value p_p_2 = %p\n", &p_2);      //p_p_1 é igual ao endereço de p_2
    printf("value p_p_2 = %p\n", &i);      //p_p_2 é igual ao endereço de p_1

    printf("i = %d\n", i);
    printf("*p_2 = %d\n", *p_2);
    printf("**p_p_1 = %d\n", j);        //valor apontado pelo valor apontado por p_p_2 (*p_p_2 = p_1 = &i) | logo, é o valor apontado por &i, *(&i)
    //printf("**p_p_1 = %d\n", **p_p_1);
    printf("**p_p_2 = %d\n", i);        //valor apontado pelo valor apontado por p_p_2 (*p_p_2 = p_1 = &i) | logo, é o valor apontado por &i, *(&i)
    //printf("**p_p_2 = %d\n", **p_p_2);
    printf("*(&p_1) = %p", *(&p_1));       //o valor apontado pelo endereço de uma variável é a própria variável

    //(...)
}