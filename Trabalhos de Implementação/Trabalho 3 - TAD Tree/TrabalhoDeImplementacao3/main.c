#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct _Produto_{
    char nome[30];
    int codigo;
    float preco;
}Produto;

int cmp(void *elm, void *key){
    char *pelm = (char *)elm;
    Produto *pkey = (Produto *)key;
    return strcmp(pelm, pkey->nome);
}


void visit(void *objeto){
    Produto *produto = (Produto *)objeto;
    printf("\nNome: %s\n",produto->nome);
    printf("Codigo: %d\n",produto->codigo);
    printf("Preco: %.2f RS\n",produto->preco);
}

int main(){
    TNode *t = NULL;
    Produto *produto;
    int select;
    void **data;
    int codigo;
    char procura;
    do{
        printf("\n-----arvore-----");
        printf("\n1 - Inserir item");
        printf("\n2 - Remover item");
        printf("\n3 - Consultar item");
        printf("\n4 - Listar itens");
        printf("\n5 - Sair\n");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            //Inserir produto na arvore
            produto = (Produto *)malloc(sizeof(Produto));
            printf("\nQual o nome do item?\n");
            scanf("%s",&produto->nome);
            printf("Qual o codigo do item?\n");
            scanf("%d",&produto->codigo);
            printf("Qual o float do item?\n");
            scanf("%f",&produto->preco);

            if(t==NULL){
                t = treeInsert(NULL, produto, cmp);
                if(t){
                    printf("\nElemento inserido!\n");
                }else{
                    printf("\nElemento nao inserido!\n");
                }
            }else{
                if(treeInsert(t, produto, cmp)){
                    printf("Elemento inserido!\n");
                }else{
                    printf("Elemento nao inserido!\n");
                }
            }

            break;
        case 2:
            //Remover produto da arvore
            produto = (Produto *)malloc(sizeof(Produto));
            printf("\nInsira o nome do item que voce quer remover:\n");
            scanf("%s",&produto->nome);

            treeRemove(t,(void*)&produto->nome,cmp,&data);
            if(data!=NULL){
                printf("\nitem removido com sucesso!!!\n");
            }else{
                printf("\nFalha ao remover item!!\n");
            }

            break;
        case 3:
            //Procura produto na papelaria
            produto = (Produto *)malloc(sizeof(Produto));
            printf("\nInsira o nome do item que voce quer procurar:\n");
            scanf("%s",&produto->nome);

            produto = treeQuery(t,&produto->nome,cmp);

            if(produto == NULL){
                printf("\nNao existe esse item na arvore !!!\n");
            }else{
                printf("\nNome: %s\n",produto->nome);
                printf("Codigo: %d\n",produto->codigo);
                printf("peso: %.2f RS\n",produto->preco);
            }
            break;
        case 4:
            //Lista os produtos inseridos na arvore de forma SIMETRICA
            if(t==NULL){
                printf("\nNao temos itens no momento!!!\n");
            }
            printf("\nitens:");
            simetrico(t,visit);
            break;

        case 5:
            printf("\nObrigado!!!\n");
            break;
        default:
            printf("\nEsta opcao e invalida!!!\n");
            break;
        }
    }
    while (select != 5);    

    return 0;
}