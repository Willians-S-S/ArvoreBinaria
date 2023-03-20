
//arvore binaria em c

#include <stdio.h>
#include <stdlib.h>

typedef struct produto{
    int id, quant;
    char nome[100];
    float preco;
    struct produto *esquerda, *direita;
}Produto;

typedef struct arvore{
    Produto *raiz;
}Arvore;

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
}Arvore;

Arvore *criaArvore(int info){
    Arvore *a = (Arvore*)malloc(sizeof(Arvore));
    a->info = info;
    a->esq = NULL;
    a->dir = NULL;
    return a;
}

Arvore *insereArvore(Arvore *a, int info){
    if(a == NULL){
        a = criaArvore(info);
    }else{
        if(info < a->info){
            a->esq = insereArvore(a->esq, info);
        }else{
            a->dir = insereArvore(a->dir, info);
        }
    }
    return a;
}

//remover no da arvore

Arvore *removeArvore(Arvore *a, int info){
    if(a == NULL){
        return NULL;
    }else{
        if(info < a->info){
            a->esq = removeArvore(a->esq, info);
        }else{
            if(info > a->info){
                a->dir = removeArvore(a->dir, info);
            }else{
                if(a->esq == NULL && a->dir == NULL){
                    free(a);
                    a = NULL;
                }else{
                    if(a->esq == NULL){
                        Arvore *aux = a;
                        a = a->dir;
                        free(aux);
                    }else{
                        if(a->dir == NULL){
                            Arvore *aux = a;
                            a = a->esq;
                            free(aux);
                        }else{
                            Arvore *aux = a->dir;
                            while(aux->esq != NULL){
                                aux = aux->esq;
                            }
                            a->info = aux->info;
                            aux->info = info;
                            a->dir = removeArvore(a->dir, info);
                        }
                    }
                }
            }
        }
    }
    return a;
}

void imprimeArvore(Arvore *a){
    if(a != NULL){
        imprimeArvore(a->esq);
        printf("%d ", a->info);
        imprimeArvore(a->dir);
    }
}

int main(){
    Arvore *a = NULL;
    a = insereArvore(a, 10);
    a = insereArvore(a, 5);
    a = insereArvore(a, 15);
    a = insereArvore(a, 3);
    a = insereArvore(a, 7);
    a = insereArvore(a, 12);
    a = insereArvore(a, 18);
    imprimeArvore(a);
    return 0;
}