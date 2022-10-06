#include <stdio.h>

int main() {
    int var1 = 5;
    char var2 = 'a';
    int *ptr1 = &var1;
    char *ptr2=&var2;
    *ptr2 = 'b';
    printf("var1 tem o endereco %p e o valor %d\n", ptr1, *ptr1);
    printf("var2 tem o endereco %p e o valor %d\n", ptr2, *ptr2);
    printf("ptr1+1 = %p\n", ++ptr1);
    printf("ptr2+1 = %p\n", ++ptr2);
    printf("Como podemos ver ^, o valor de ptr1+1 aumenta em 4 e o valor de ptr2+1 aumenta em apenas 1\n");
    printf("char tem tamanho %lu, *char tem tamanho %lu\n", sizeof(*ptr2), sizeof(ptr2));
    printf("int tem tamanho %lu e *int tem tamanho %lu\n", sizeof(*ptr1), sizeof(ptr1));
    printf("isto deve-se ao facto de, que, como pode ser visto, o tamanho de uma variavel de tipo int e 4B e o "
    "de uma variavel de tipo char e apenas 1");   
}