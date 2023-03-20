typedef struct arvore Arvore;

Arvore *criarArvore();
Arvore *inserirArvore(Arvore *a);
void imprimeArvores(Arvore *a);
void buscarArvore(Arvore *a, int id);
Arvore *atualizarProduto(Arvore *a, int id);
Arvore *removerArvore(Arvore *a, int id);