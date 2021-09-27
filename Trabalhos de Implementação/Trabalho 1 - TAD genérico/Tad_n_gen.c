#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include <string.h>
#define true 1
#define false 0



int main(void){

    Colecao *colecao;
    colecao = criarcolecao(6);
    printf("Bem vindx ao sistema de rastreamento de Água-vivas para a ONG de proteção a animais marinhos\n");
    printf("Gostaríamos de informmar que cada raça de água-viva vive em locais diferentes no oceano\n");
    
    switch(){
        case 1:

    }

    //Aguaviva agua, remov;
    //int search,key_registro;
    //strcpy(agua.nome,"viva");
    //printf("Boa tarde, você acionou o sistema de rastreamento de Agua-vivas\n");
    //printf("Gostaria de inserir uma ");
    //agua.registro = 475163;
    //agua.localizacao = 8.7832;
    /*inserirAguaviva(colecao,&agua);
    printf("insira o registro para pesquisar: ");
    scanf("%d",&key_registro);
    search=pesquisarAguaviva(colecao,key_registro);
    printf("%d",search);
    remov=removeAguaviva(colecao,key_registro);
    printf("%s --- %i --- %f",remov.nome,remov.registro,remov.localizacao);
    destruirColecaoDeAguaviva(colecao);
    */
    return 0;
}

Colecao *criarcolecao(int n){
    /*
    Cofo *c;
    if(n>0){
        c=((Cofo*)malloc(sizeof(Cofo)));
        if(c!=NULL){
            c->aguaviva=((Aluno*)malloc(sizeof(Aluno)*numero));
            if (c->aguaviva!=NULL){
                c->qtdeAgviva=0;
                c->maxAlunes=numero;
                return c;
            }
        }
    }
    return NULL;
    */

   if(n>0){
       Colecao *c;

       c=(Colecao*)malloc(sizeof(Colecao));
       if(c!=NULL){
           c->aguaviva=(Aguaviva*)malloc(n*sizeof(Aguaviva));
           c->qtdeAgviva=0;
           c->maxAgviva=n;
           return c;
       }
       return NULL;
   }
   return NULL;
}

int inserirAguaviva(Colecao *c,Aguaviva *agua){
    if(c!=NULL){
        if((c->qtdeAgviva)<(c->maxAgviva)){
            c->aguaviva[c->qtdeAgviva]=*agua;
            c->qtdeAgviva++;
            return true;
        }
    }
    return false;
}


Aguaviva removeAguaviva(Colecao *c,int key_registro){
    int i,j;
    Aguaviva agua;
    if (c!=NULL){
        if(c->qtdeAgviva>0){
            i=0;
            while((c->aguaviva[i].registro!=key_registro) && (i<c->qtdeAgviva)){
                i++;
            }
            if (c->aguaviva[i].registro==key_registro){
                agua=c->aguaviva[i];
                for (j=i;j<c->qtdeAgviva-2;j++){
                    c->aguaviva[j]=c->aguaviva[j+1];
                }
                c->qtdeAgviva--;
                return agua;
            }
        }
    }
}


int pesquisarAguaviva(Colecao *c,int key_registro){
    int i;
    if (c!=NULL){
        if (c->qtdeAgviva>0)
            i=0;
        while ((c->aguaviva[i].registro!=key_registro) && (i<c->qtdeAgviva)){
            i++;
        }
        if (c->aguaviva[i].registro==key_registro){
            return c->aguaviva[i].registro;
        }
    }
    return -1;
}


int destruirColecaoDeAguaviva(Colecao *c){
    if (c!=NULL){
        if (c->qtdeAgviva==0){
            free(c->aguaviva);
            free(c);
            return true;
        }
    }
    return false;
}