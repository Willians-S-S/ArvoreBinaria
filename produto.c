#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

struct produto{
    int id, quant;
    char nome[100];
    float preco;
    struct produto *esquerda, *direita;
};

Produto *criaNo(int id){
    Produto *newNo = (Produto*)malloc(sizeof(Produto));
    newNo->id = id;
    printf("Digite o nome do produto: ");
    scanf("%s", newNo->nome);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &newNo->quant);
    printf("Digite o preco do produto: ");
    scanf("%f", &newNo->preco);
    newNo->esquerda = NULL;
    newNo->direita = NULL;
    return newNo; 
}

Produto *insereNo(Produto *no, int id){
    if(no == NULL){
        no = criaNo(id);
    }else{
        if(id < no->id){
            no->esquerda = insereNo(no->esquerda, id);
        }else{
            no->direita = insereNo(no->direita, id);
        }
    }
    return no;
}

void imprimeArvore(Produto *no){
    if(no != NULL){
        imprimeArvore(no->esquerda);
        imprimeNo(no);
        imprimeArvore(no->direita);
    }
}

void imprimeNo(Produto *no){
    if(no != NULL){
        printf("ID: %d\nNome: %s\nQuantidade: %d\nPreco: %.2f\n", no->id, no->nome, no->quant, no->preco);
    }
}