#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"


void main(){
    int tam;
    int dado;
    int log;
    int key;
    int elm;
    int i;
    Colecao *cofo;

    printf("tamanho");
    scanf("%i",&tam);
    cofo=criar(tam);

    for(i=0;i<tam;i++){
        printf("dado");
        scanf("%i",&dado);
        log=insert(cofo,dado);
    }
      for(i=0;i<cofo->qtd_atual;i++){
        printf("vet[%i]:%i \n",i+1,cofo->dados[i]);
    }

    printf("busca");
    scanf("%i",&key);

    log=search(cofo,key);
    printf("%i",log);

    printf("destroi");
    scanf("%i",&elm);
    log=saca_fora(cofo,elm);

      for(i=0;i<cofo->qtd_atual;i++){
        printf("vet[%i]:%i \n",i+1,cofo->dados[i]);
    }


}
