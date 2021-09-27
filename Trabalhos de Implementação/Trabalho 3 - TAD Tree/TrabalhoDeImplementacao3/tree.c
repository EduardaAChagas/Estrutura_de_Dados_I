#include <stdlib.h>
#include "tree.h"


TNode *treeInsert(TNode *t, void *key, int (*cmp)(void *, void *)){
    TNode *newnode;
    if (t == NULL){
        newnode = (TNode *)malloc(sizeof(TNode));
        if(newnode != NULL){
            newnode->item = key;
            newnode->left = newnode->right = NULL;
            return newnode;
        }else{
            return NULL;
        }
    }else{
        if(cmp(key, t->item) < 0){
            t->left = treeInsert(t->left, key, cmp);
        }
        if(cmp(key, t->item) > 0){
            t->right = treeInsert(t->right, key, cmp);
        }
        return t;
    }
}

TNode *treeQuery(TNode *t, void *key, int(*cmp)(void*, void*)){
    if (t == NULL){
        return NULL;
    }
    if(cmp(key,t->item) == 0){
        return t->item;
    }
    if(cmp(key,t->item) < 0){
        return treeQuery(t->left, key, cmp);
    }else{
        return treeQuery(t->right, key, cmp);
    }
}

void simetrico(TNode *t, void (*visit)(void *)){
    if (t != NULL){
        simetrico(t->left, visit);
        visit(t->item);
        simetrico(t->right, visit);
    }
}

TNode *treeRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data){
    TNode *aux;
    void **data2;

    if(t != NULL){
        if (cmp(key, t->item) < 0){
            t->left = treeRemove(t->left, key, cmp, &data);
            return t;
        }else{
            if(cmp(key, t->item) > 0){
                t->right = treeRemove(t->right, key, cmp, &data);
                return t;
            }else{
                if(t->left == NULL && t->right == NULL){
                    *data = t->item;
                    free(t);
                    return NULL;
                }else{
                    if(t->left == NULL){
                        *data = t->item;
                        aux = t->right;
                        free(t);
                        return aux;
                    }else{
                        if(t->right == NULL){
                            *data = t->item;
                            aux = t->left;
                            free(t);
                            return aux;
                        }else{
                            *data = t->item;
                            t->right = abpRemoveMenor(t->right, &data2);
                            t->item = data2;
                            return t;
                        }
                    }
                }
            }
        }
    }
    *data = NULL;
    return NULL;
}

void *abpRemoveMenor(TNode *t, void **data){
    if(t->left == NULL){
        *data = t->item;
        return NULL;
    }else{
        return abpRemoveMenor(t->left, &data);
    }
}