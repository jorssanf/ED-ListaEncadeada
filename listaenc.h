typedef struct tno{
    int dado;
    struct tno *prox;
}tnolista;

typedef tnolista* lista;

void criar(lista *l);
int vazia(lista l);
int tamanho(lista l);
int elemento(lista l, int posicao, int *valor);
int busca(lista l, int dado);
int inserir(lista *l, int posicao, int dado);
int remover(lista *l, int posicao, int *dado);
void imprime(lista l);


