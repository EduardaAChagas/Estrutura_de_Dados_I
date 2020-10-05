/* Faça um programa para:
- ler a opção ( 1- Inteiro, 2 - Real)
- ler um numero n;
- alocar um vetor de n posições de números de acordo com a opçao do usuario;
- ler os n numeros e guardar no vetor alocado;
- usar a funcao qsort do C para ordenar esses dados;
- imprimiri os dados ordenados.
*/

#include <stdio.h>
#include <stdlib.h>

int ordenacaoInt(const void *a, const void *b){
    if(*(int*)a == *(int*)b){
        return 0;
    }
    else
        if(*(int*)a < *(int*)b){
            return -1;
    }
    else{
        return 1;
    }
}

int ordenacaofloat(const void *a, const void *b){
    if(*(const float*)a < *(const float*)b)
        return -1;
    return *(const float*)a > *(const float*)b;
}


int main(void) {
    int tipo;
    int ni, *veti, nf;
    float *vetf;

    printf("Insira um tipo de sua escolha:\n");
    printf("1- Inteiro, 2- Real\n");
    scanf("%d", &tipo);

    switch(tipo){
        case 1:
            printf("Digite um numero inteiro n:\n");
            scanf("%d", &ni);

            veti = (int*)malloc(sizeof(int)*ni);
            if(veti == NULL){
            printf("ERRO!");
            break;
            return 0;
            }
    for(int i=0; i<ni; i++){
        printf("insira um elemento no vetor:\n");
        scanf("%d", &veti[i]);
    }

    qsort(veti, ni, sizeof(int), ordenacaoInt);

    printf("Vetor ordenado: \n");
    for(int i=0; i<ni; i++){
        printf("%d ", veti[i]);
    }
    printf("\n");

    break;
    /////////////////
    case 2:
        printf("Digite um numero real n:\n");
        scanf("%d", &nf);

        vetf = (float*)malloc(sizeof(float)*nf);
        if(vetf == NULL){
            printf("ERRO!");
            break;
            return 0;
        }
        for(int i=0; i<nf; i++){
            printf("insira um elemento no vetor:\n");
            scanf("%f", &vetf[i]);
        }

        qsort(vetf, nf, sizeof(float), ordenacaofloat);

        printf("Vetor Ordenado:\n");
        for(int i=0; i<nf; i++){
            printf("%.1f ", vetf[i]);
        }
        printf("\n");      
        }

    return 0;
}