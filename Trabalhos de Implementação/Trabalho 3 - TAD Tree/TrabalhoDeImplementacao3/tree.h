#ifndef _tree_h_
    #define _tree_h_
    #ifndef _tree_c_
        typedef struct _t_node_ {
            void *item;
            struct t_node *left;
            struct t_node *right;
        }TNode;

        TNode *treeInsert(TNode *t, void *key, int (*cmp)(void *, void *));
        TNode *treeRemove(TNode* t, void *key, int(*cmp)(void*, void*), void **data);
        TNode *treeQuery(TNode *t, void *key, int(*cmp)(void*, void*));
        void *abpRemoveMenor(TNode *t, void **data);
        int treeDestroy(TNode *t);
    #endif
#endif // _tree_h_