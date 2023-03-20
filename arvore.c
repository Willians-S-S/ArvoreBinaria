#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "produto.h"

typedef struct arvore{
    Produto *raiz;
};

Arvore *criarArvore(){
    return NULL;
}

Arvore *inserirArvore(Arvore *a, int id){
    if(a == NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
    }
    a->raiz = insereNo(a->raiz, id);
    return a;
}

void imprimeArvores(Arvore *a){
    if(a != NULL){
        imprimeArvore(a->raiz);
    }
}