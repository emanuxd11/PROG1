#include <stdio.h>

int main()
{
    int a=0, e=0, i=0, o=0, u=0;
    char caracter;
    while(caracter!='.' & caracter!='!' & caracter!='?')
    {
        scanf("%c", &caracter);
        switch(caracter)
        {
            case 'a': 
            case 'A': a++; break;
            case 'e':
            case 'E': e++; break;
            case 'i':
            case 'I': i++; break;
            case 'o':
            case 'O': o++; break;
            case 'u':
            case 'U': u++; break;
        }
    }
    printf("A -> %d\nE -> %d\nI -> %d\nO -> %d\nU -> %d\n", a, e, i, o, u);
}