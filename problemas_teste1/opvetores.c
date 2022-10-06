#include <stdio.h>

float prodEsc(float ux, float uy, float uz, float vx, float vy, float vz);

int main() {
    float ux, uy, uz, vx, vy, vz, c;
    int ad_vet=0, prod_d_esc=0, prod_esc=0;
    char op;
    while(scanf("%c", &op)==1) {
        switch(op) {
            case 'A':
            scanf("%f %f %f %f %f %f", &ux, &uy, &uz, &vx, &vy, &vz);
            printf("\nu + v = (%f, %f, %f)", ux+vx, uy+vy, uz+vz);
            ad_vet++;
            break;
            case 'B':
            scanf("%f %f %f %f", &c, &ux, &uy, &uz);
            printf("\nc u = (%f, %f, %f)", c*ux, c*uy, c*uz);
            prod_d_esc++;
            break;
            case 'C':
            scanf("%f %f %f %f %f %f", &ux, &uy, &uz, &vx, &vy, &vz);
            printf("\nu . v = %f", prodEsc(ux, uy, uz, vx, vy, vz));
            prod_esc++;
            break;
        }
    }
    printf("\nAdicao de vetores: %d", ad_vet);
    printf("\nProduto de um escalar: %d", prod_d_esc);
    printf("\nProduto escalar de vetores: %d", prod_esc);
}

float prodEsc(float ux, float uy, float uz, float vx, float vy, float vz) {
    return ux*vx+uy*vy+uz*vz;
}