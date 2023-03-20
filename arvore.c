#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "produto.h"

struct arvore{
    Produto *raiz;
};

Arvore *criarArvore(){
    return NULL;
}

Arvore *inserirArvore(Arvore *a){
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);
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

void buscarArvore(Arvore *a, int id){
    Produto *aux;
    if(a != NULL){
        aux = buscarNo(a->raiz, id);
        if(aux) imprimeNo(aux);
        else printf("\nProduto nao encontrado!\n\n");
    }
}

Arvore *atualizarProduto(Arvore *a, int id){
    if(a != NULL){
        Produto *aux = buscarNo(a->raiz, id);
        if(aux){
           aux = atualizarNo(aux);
        }else{
            printf("Produto nao encontrado!\n");
        }
    }
    return a;
}

Arvore *removerArvore(Arvore *a, int id){
    if(a != NULL){
        a->raiz = removerNo(a->raiz, id);
    }
    return a;
}