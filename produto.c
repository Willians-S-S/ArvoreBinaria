#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("\n");
    printf("Digite o nome do produto: ");
    scanf("%s", newNo->nome);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &newNo->quant);
    printf("Digite o preco do produto: ");
    scanf("%f", &newNo->preco);
    printf("\n");
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
        printf("\nID: %d\nNome: %s\nQuantidade: %d\nPreco: %.2f\n", no->id, no->nome, no->quant, no->preco);
    }
}

Produto *buscarNo(Produto *no, int id){
    if(no != NULL){
        if(id == no->id){
            return no;
        }else{
            if(id < no->id){
                buscarNo(no->esquerda, id);
            }else{
                buscarNo(no->direita, id);
            }
        }
    }
    // return NULL;
}

Produto *atualizarNo(Produto *aux){
    int op;
    printf("\nAtualize a quantidade do produto: ");
    scanf("%d", &aux->quant);
    printf("Deseja atualizar o preco do produto? (1 - Sim | 2 - Nao): ");
    scanf("%d", &op);

    if(op == 1){
        printf("Digite o preco do produto: ");
        scanf("%f", &aux->preco);
    }
    printf("\n");
    return aux; 
}

Produto *removerNo(Produto *no, int id){
    if(!no){
        printf("\nProduto nao encontrado!\n");
        return NULL;
    }else{
        if (no->id == id){
            //remove no folha, ou seja, aquele que não tem filho
            if(no->esquerda == NULL && no->direita == NULL){
                free(no);
                return NULL;
            }else{
                //remove no que tem somente um filho
                if(no->esquerda == NULL || no->direita == NULL){
                    Produto *aux;
                    if(no->esquerda)aux = no->esquerda;
                    else aux = no->direita;
                    free(no);
                    return aux;
                }else{
                    //remove no que tem dois filhos
                    Produto *aux = no->esquerda, *copia = no;
                    while(aux->direita != NULL) aux = aux->direita;
                    no->id = aux->id;
                    strcpy(no->nome, aux->nome);
                    no->quant = aux->quant;
                    no->preco = aux->preco;
                    aux->id = id;
                    no->esquerda = removerNo(no->esquerda, id);
                    return no;
                }
            }
        }else{
            if(id < no->id) no->esquerda = removerNo(no->esquerda, id);
            else no->direita = removerNo(no->direita, id);
            return no;
        }
    }
}