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
    sequencia *vetor;

    printf("tamanho");
    scanf("%i",&tam);
    vetor=criar(tam);

    for(i=0;i<tam;i++){
        printf("dado");
        scanf("%i",&dado);
        log=insert(vetor,dado);
    }
      for(i=0;i<vetor->qtd_now;i++){
        printf("vet[%i]:%i \n",i+1,vetor->dados[i]);
    }

    printf("busca");
    scanf("%i",&key);

    log=search(vetor,key);
    printf("%i",log);

    printf("destroi");
    scanf("%i",&elm);
    log=saca_fora(vetor,elm);

      for(i=0;i<vetor->qtd_now;i++){
        printf("vet[%i]:%i \n",i+1,vetor->dados[i]);
    }


}
