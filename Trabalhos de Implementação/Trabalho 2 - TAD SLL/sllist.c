#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"
#define TRUE 1
#define FALSE 0

//cria uma lista vazia
SLList *sllCreate(){
    SLList *l;
    l = (SLList*)malloc(sizeof(SLList));
    if(l != NULL){
        l->first = NULL;
        return l;
    }
    return NULL;
}

//insere um elemento
int sllInsert(SLList *l, void *elm){
    SLNode *newnode;
    if(l!= NULL){
        newnode = (SLNode*)malloc(sizeof(SLNode));
        if(newnode != NULL){
            newnode->data = elm;
            if(l->first == NULL){
                newnode->next = NULL;
            }else{
                newnode->next = l->first;
            }
            l->first = newnode;
            return 1;
        }
    }
    return 0;
} 

//determina se uma lista esta vazia
int *sllisEmpty(SLList *l){
    if(l!=NULL){
        if(l->first!=NULL){
            return FALSE;
        }
    }
    return TRUE;
}


//remove um elemento
void *sllRemove(SLList *l){
    SLNode *aux;
    void *data;
    if(l != NULL){
        if(l->first != NULL){
            aux = l->first;
            data = aux->data;
            l->first = aux->next;
            free(aux);
            return data;
        }
    }
    return NULL;
}

//destroi uma lista vazia
int sllDestroy(SLList *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return 1;
        }
    }
    return 0;
}


//pesquisa um elemento da lista
void *sllQuery(SLList *l, void *key, int(*cmp)(void*, void*)){
    SLNode *cur;
    if(l != NULL){
        if(l->first != NULL){
            cur = l->first;
            while(cur->next != NULL && cmp(cur->data, key) != 1){
                cur = cur->next;
            }
            if(cmp(cur->data, key) == 1){
                return cur->data;
            }
        }
    }
    return NULL;
}


//remoção de um elemento
void *sllRemoveSpec(SLList *l, void *key, int(*cmp)(void*, void*)){
    SLNode *spec, *prev;
    void *data;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            prev = NULL;
            while(spec->next != NULL && cmp(spec->data, key) != 1){
                prev = spec;
                spec = spec->next;
            }
            if(cmp(spec->data, key) == 1){
                data = spec->data;
                if(spec == l->first){
                    l->first = spec->next;
                }else{
                    prev->next = spec->next;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

//printar lista inteira com dados
void *listagemFormiga(SLList *l, void (*showElms)(void* elm)){
    SLNode *cur;
    void *view;
    if(l != NULL){
        if(l->first != NULL){
            cur = l->first;
            showElms(cur->data);
            while(cur->next != NULL){
                cur = cur->next;
                showElms(cur->data);
            }
            
        }
    }
    return NULL; 
}

