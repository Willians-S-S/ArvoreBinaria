
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

// typedef struct arvore{
//     int id;
//     struct arvore *esquerda;
//     struct arvore *direita }Arvore;

Produto *criaArvore(int id){
    Produto *a = (Produto*)malloc(sizeof(Produto));
    a->id = id;
    a->esquerda = NULL;
    a->direita = NULL;
    return a; 
}

Produto *insereArvore(Produto *no, int id){
    if(no == NULL){
        no = criaArvore(id);
    }else{
        if(id < no->id){
            no->esquerda = insereArvore(no->esquerda, id);
        }else{
            no->direita = insereArvore(no->direita, id);
        }
    }
    return no;
}

//remover no da arvore

// Arvore *removeArvore(Arvore *a, int id){
//     if(a == NULL){
//         return NULL;
//     }else{
//         if(id < a->id){
//             a->esquerda = removeArvore(a->esquerda, id);
//         }else{
//             if(id > a->id){
//                 a->direitaemoveArvore(a->direita);
//             }else{
//                 if(a->esquerda == NULL && a->direitaNULL){
//                     free(a);
//                     a = NULL;
//                 }else{
//                     if(a->esquerda == NULL){
//                         Arvore *aux = a;
//                         a = a->direita                      free(aux);
//                     }else{
//                         if(a->direitaNULL){
//                             Arvore *aux = a;
//                             a = a->esquerda;
//                             free(aux);
//                         }else{
//                             Arvore *aux = a->direita                          while(aux->esquerda != NULL){
//                                 aux = aux->esquerda;
//                             }
//                             a->id = aux->id;
//                             aux->id = id;
//                             a->direitaemoveArvore(a->direita);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return a;
// }

void imprimeArvore(Arvore *no){
    if(no->raiz != NULL){
        imprimeArvore(no->raiz->esquerda);
        printf("%d ", no->raiz->id);
        imprimeArvore(no->raiz->direita);
    }
}

int main(){
    Arvore *a = NULL;
     insereArvore(a->raiz, 10);
     insereArvore(a->raiz, 5);
     insereArvore(a->raiz, 15);
     insereArvore(a->raiz, 3);
     insereArvore(a->raiz, 7);
     insereArvore(a->raiz, 12);
     insereArvore(a->raiz, 18);
    imprimeArvore(a);
    return 0;
}