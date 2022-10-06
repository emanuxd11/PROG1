#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define TAM_MSG 200

char cifra(char original, char chave){
    return (original+chave-2*97)%26+97;
}

void codifica(char *msg_original, char *msg_codificada, char *chave){
    char chave2[TAM_MSG]="";
    int i=0;
    while(strlen(chave)<strlen(msg_original)) {
        strcpy(chave2, chave);
        strcat(chave, chave2);
    }
    while(msg_original[i]!='\0') {
        if(isalpha(msg_original[i])) {
            msg_codificada[i]=cifra(msg_original[i], chave[i]);
        } else {
            msg_codificada[i]=msg_original[i];
        }
        i++;
    }
}

char decifra(char codificada, char chave) {
    return (codificada-97-(chave-97)+26)%26+97;
}

void descodifica(char *msg_codificada, char *msg_original, char *chave) {
    char chave2[TAM_MSG]="";
    int i=0;
    while(strlen(chave)<strlen(msg_codificada)) {
        strcpy(chave2, chave);
        strcat(chave, chave2);
    }
    while(msg_codificada[i]!='\0') {
        if(isalpha(msg_codificada[i])) {
            msg_original[i]=decifra(msg_codificada[i], chave[i]);
        } else {
            msg_original[i]=msg_codificada[i];
        }
        i++;
    }
}

void ataque(char *msg_codificada, char *chave_parcial, char *chave){
    int i;
    char msg_original[TAM_MSG]="", ult_car[2]="a";
    strcat(chave_parcial, ult_car);
    //chave_parcial[strlen(chave_parcial)]=ult_car;
    strcpy(chave, chave_parcial);
    for(i=0; i<26; i++) {
        printf("chave: %s --> ", chave_parcial);
        descodifica(msg_codificada, msg_original, chave_parcial);
        printf("%s\n\n", msg_original);
        strcpy(chave_parcial, chave);
        chave_parcial[strlen(chave_parcial)-1]=++ult_car[0];
    }
}

void le_msg(char *msg){
    fgets(msg, TAM_MSG-1, stdin);
    msg[strlen(msg)-1]='\0';
}

int main(){
    char mensagem[TAM_MSG]="", cifrada[TAM_MSG]="s xiqw iiiiksfdyt al mqfwhey pzh unpsrj nhgdj dhla qcrk syhhjx wthklzhi s fhg-otp umjxvn.", decifrada[TAM_MSG]="", chave[TAM_MSG]="", chave_p[TAM_MSG]="";
    
    /*printf("texto? ");
    le_msg( mensagem);
    printf("chave? ");
    le_msg( chave);
    codifica(mensagem, cifrada, chave);
    printf("mensagem codificada: %s\n", cifrada);
    descodifica(cifrada, mensagem, chave);
    printf("mensagem descodificada: %s\n", mensagem);*/

    /*printf("Introduza mensagem Romana: ");
    le_msg(cifrada);*/
    printf("chave parcial? ");  //descomentando esta parte e removendo a inicialização das strings,
    le_msg(chave_p);      //o programa deixa de funcionar

    ataque(cifrada, chave_p, chave);

    /*descodifica(cifrada, mensagem, chave);
    printf("chave (%s): %s\n", chave, mensagem);*/
}

//mensagem romana: s xiqw iiiiksfdyt al mqfwhey pzh unpsrj nhgdj dhla qcrk syhhjx wthklzhi s fhg-otp umjxvn.
//chave parcial: struc