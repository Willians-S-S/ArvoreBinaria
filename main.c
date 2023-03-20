#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "produto.h"

int main(){
    int op = -1, id;
    Arvore *a = criarArvore();
    while(op != 0){
        printf("1 - Inserir produto\n2 - Buscar produto\n3 - Atualizar produto\n4 - Remover produto\n5 - Mostrar todos os produtos\n0 - Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                a = inserirArvore(a);
                break;
            case 2:
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                buscarArvore(a, id);
                break;
            case 3:
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                a = atualizarProduto(a, id);
                break;
            case 4:
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                a = removerArvore(a, id);
                break;
             case 5:
                imprimeArvores(a);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
    return 0;
}