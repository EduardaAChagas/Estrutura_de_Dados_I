#include <stdlib.h>
#include <stdio.h>

typedef struct _sequencia_{
    int *dados;
    int tam_max;
    int qtd_now;

}sequencia;

sequencia *criar( int tam);
int insert(sequencia *vetor, int dado);
int search(sequencia *vetor, int key);
int saca_fora(sequencia *vetor, int elm);



/*

typedef struct _Aguaviva_{
    char nome[100];
    int registro;
    float localizacao;
    char raça[100];
}Aguaviva;

typedef struct _Colecao_{
    int qtdeAgviva;
    int maxAgviva;
    Aguaviva *aguaviva;
}Colecao;

Aguaviva *criarAguaviva(int n);
Colecao *criarcolecao(int n);
int inserirAguaviva(Colecao *c,Aguaviva *agvv);
Aguaviva removeAguaviva(Colecao *c,int key_registro);
int pesquisarAguaviva(Colecao *c,int key_registro);
int destruirColecaoDeAguaviva(Colecao *c);

*/