#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SLNode_ {
    struct _SLNode_ *next;
    void *data;
} SLNode;

typedef struct _SLList_ {
    SLNode *first;
} SLList;

SLList *sllCreate(void); 
int sllInsert(SLList *l, void *elm);
int sllDestroy(SLList *l);
void *sllQuery(SLList *l, void *key, int(*cmp)(void*, void*));
void *sllRemoveSpec(SLList *l, void *key, int(*cmp)(void*, void*));
void *listagemFormiga(SLList *l, void (*showElms)(void* elm));