typedef struct produto Produto;

Produto *criaNo(int id);
Produto *insereNo(Produto *no, int id);
void imprimeArvore(Produto *no);
void imprimeNo(Produto *no);
Produto *buscarNo(Produto *no, int id);
Produto *atualizarNo(Produto *aux);
Produto *removerNo(Produto *no, int id);