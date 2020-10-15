#include <stdlib.h>
#include <stdio.h>

typedef struct _colecao_ {
int qtd_atual;
int tam_max;
void **item;
}Colecao;

typedef struct _aguaviva_{
    char nome[100];
    int registro;
    float localizacao;
    char raca[100];
}Aguaviva;


Colecao *criarColecao( int tam_max);
void insert(Colecao *cofo, void *dado);
int search(Colecao *cofo, void *key);
int remove(Colecao *cofo, void *item);



/*
int colInserir( Colecao *c, void * item );
void *colRetirar( Colecao *c, void *item );
void *colBuscar( Coleca *c, void *chave );
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
Colecao *criarColecao(int n);
int inserirAguaviva(Colecao *c,Aguaviva *agvv);
Aguaviva removeAguaviva(Colecao *c,int key_registro);
int pesquisarAguaviva(Colecao *c,int key_registro);
int destruirColecaoDeAguaviva(Colecao *c);

*/