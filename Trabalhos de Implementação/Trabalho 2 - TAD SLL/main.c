#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"

typedef struct _Formiga_{
    char nome[30];
    int registro;
    float peso;
}Formiga;


/*
Implemente o TAD SLL e o utilize para fazer um programa com os seguintes requisitos: 
- Defina uma estrutura do TIPO ESCOLHIDO ( tipo aluno, ou tipo disco, ou tipo Time, etc...) que tenha pelo menos os seguintes campos: 
---- um campo char [30] 
---- um campo inteiro 
----- um campo float 
- Implemente as seguintes operações: 
 ---- criar uma coleção 
--- Inserir um TIPO ESCOLHIDO na coleção 
---- Remover um TIPO ESCOLHIDO na coleção identificado pelo campo char, int e float 
---- Consultar um TIPO ESCOLHIDO na coleção identificado pelo campo char, int e float 
--- listar os elementos na coleção. 
-- destruir a coleção 

Importante: dentro do arquivo sll.c é proibido printf e scanf ou qualquer coisa similar. O trabalho pode ser feito em duplas.

*/
int cmp(void *elm, void *key){

    Formiga *fomiga = (Formiga *)elm;
    int *pkey = (int *)key;
    if(fomiga->registro == pkey){

        return 1;
    }else{
        return 0;
    };

}

void showElms(void *elm){
    Formiga *fomirga = (Formiga*)elm;
    printf("\n~Dados da formiga~");
    printf("\nNome: %s",fomirga->nome);
    printf("\nRegistro: %i", fomirga->registro); // matricula sempre levado como um inteiro
    printf("\nPeso: %.2f", fomirga->peso); // media de pontos como float
    printf("\n");
}

int main(){
    int option, aux;
    SLList *fazenda;
    fazenda=NULL;
    Formiga *fumiga;
    int key;
    void *flag;
    do{
        printf("1 - Criar Fazenda de Formigas\n");
        printf ("2 - Inserir Formiga\n");
        printf ("3 - Remover Formiga\n");
        printf ("4 - Consultar Formiga\n");
        printf ("5 - Listar Formigas\n");
        printf ("6 - Destruir Fazenda Vazia\n");
        printf ("7 - Sair\n");
        scanf("%d",&option);

        switch (option){
            case 1 :
            //criar uma fazenda de formigas
            if(fazenda!=NULL){
                printf("Esta fazenda já existe!!\n");
                break;
            }
            fazenda = sllCreate();
            if(fazenda!=NULL){
                printf("Fazenda criada com sucesso!\n");
            }else{
                printf("Falha ao criar fazenda!\n");
            }
            break;
    
            case 2 :
            //inserir tipo formiga da fazenda
            if(fazenda==NULL){
                printf("A fazenda ainda nao foi criada!\n");
                break;
            }else{
                printf("Quantas formigas voce quer colocar?\n");
                scanf("%d",&aux);

                for(int i=0;i<aux;i++){
                    fumiga = (Formiga *)malloc(sizeof(Formiga));
                    if(fumiga!=NULL){
                        printf("Insira os dados da sua formiga!\n");
                        printf("Nome da formiga: \n");
                        scanf("%s",&fumiga->nome);
                        printf("Qual o peso da sua formiga:\n");
                        scanf("%f",&fumiga->peso);
                        printf("Qual o numero de registro da sua formiga:\n");
                        scanf("%d",&fumiga->registro);
                        sllInsert(fazenda,fumiga);
                    }

                }
            }
            break;
            case 3 :
            //remover uma formiga da fazenda
            if(fazenda==NULL){
                printf("A fazenda ainda nao foi criada!\n");
                break;
            }
            if(sllisEmpty(fazenda)) {
                printf("A fazenda esta vazia, n tem oq remover\n");
                break;
            }
            printf("Informe o registro da formiga que voce deseja remover:\n");
            scanf("%d",&key);
            flag = NULL;
            flag = sllRemoveSpec(fazenda,key,cmp);
            if(flag!=NULL){
                printf("Formiga removida!!\n");
            }else{
                printf("Sua formiga nao esta na fazenda!\n");
            }
            break;
            case 4 :
            //cosnultar formiga na fazenda
            if(fazenda==NULL){
                printf("A fazenda ainda nao foi criada!\n");
                break;
            }
            if(sllisEmpty(fazenda)) {
                printf("A fazenda esta vazia\n");
                break;
            }            
            flag = NULL;
            printf("Informe o registro da formiga que voce deseja pesquisar:\n");
            scanf("%d",&key);
            flag = sllQuery(fazenda,key,cmp);
            if(flag!=NULL){
                printf("Sua formiga esta na fazenda!\n");
            }else{
                printf("Sua formiga nao esta na fazenda!\n");
            }
            break;
            
            case 5 :
            //listagem de formigas da fazenda
            if(fazenda==NULL){
                printf("A fazenda ainda nao foi criada!\n");
                break;
            }
            if(sllisEmpty(fazenda)) {
                printf("A fazenda esta vazia\n");
                break;
            }
            listagemFormiga(fazenda, showElms);
            break;
            
            case 6 :
            //destroi fazenda se ela estiver vazia
            if(fazenda==NULL){
                printf("A fazenda ainda nao foi criada!\n");
                break;
            }
            if(sllisEmpty(fazenda)) {
                int destruido = sllDestroy(fazenda);
                fazenda = NULL;
                if(destruido = 1){
                    printf("A fazenda nao existe mais :(\n");
                }else{
                    printf("Erro ao destruir a fazenda\n");
                }
            }else{
                printf("Nao eh possivel destruir a fazenda com formigas nela!\n");
            }      
            break;
            
            case 7 :
            
            //fecha o programa
            break;
            
            default :
            printf ("Opcao invalida!\n");
            break;
        }
    }while(option!=7);
    return 0;
}