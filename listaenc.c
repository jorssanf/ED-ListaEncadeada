#include <stdio.h>
#include <stdlib.h>
#include "listaenc.h"

void criar(lista *l){
    *l = NULL;
}

int vazia(lista l){
    return (l == NULL);
}

int tamanho(lista l){
    lista aux = l;
    int contador;

    while(aux != NULL){
        aux=aux->prox;
        contador++;
    }
    return contador;
}

int elemento(lista l, int posicao, int *valor){
    lista aux = l;
    int contador = 1;

    if (vazia(l) || posicao < 1)
        return 0;

    while((aux != NULL) && (contador < posicao)){
        aux = aux->prox;
    contador++;
    }
    if (aux != NULL){
        *valor = aux->dado;
        return 1;
    } else return 0;
}

int busca(lista l, int dado){
    if (!vazia(l)){
        lista aux = l;
        int contador = 1;
        while (aux->dado != NULL){
            if (aux->dado == dado)
                return contador;
            aux = aux->prox;
            contador++;
        }
    }
    return 0;
}

int inserir(lista *l, int posicao, int dado){
    tnolista *novo;
    lista aux;
    int contador;

    ///lista vazia
    if (vazia(*l)){
        if(posicao != 1)
            return 0;
        novo = (tnolista*) malloc(sizeof(tnolista));
        if (novo == NULL) return 0;

        novo->dado = dado;
        novo->prox = NULL;
        *l = novo;
        return 1;
    }
    ///posicao 1 de lista vazia
    if ( posicao == 1) {
        if ( (novo = (tnolista*) malloc(sizeof(tnolista))) == NULL )
            return 0;
        novo->dado = dado;
        novo->prox = *l;
        *l = novo;
        return 1;
    }
    ///apos posicao 1 de lista nao vazia
    aux = *l;
    contador = 1;
        while ( (contador < posicao-1) && (aux != NULL)) {
            aux = aux->prox;
            contador++;
        }

        if ( aux == NULL )
            return 0;

        if ((novo = (tnolista*) malloc(sizeof(tnolista))) == NULL)
            return 0;

        novo->dado = dado;
        novo->prox = aux->prox;
        aux->prox = novo;
        return 1;
}

int remover(lista *l, int posicao, int *dado){
    lista aux;
    tnolista* anterior;
    int contador;

    if( vazia(*l) || posicao < 1)
        return 0;

    aux = *l;
    contador = 1;

    while( (contador <= posicao-1) && (aux != NULL) ) {
        anterior = aux;
        aux = aux->prox;
        contador++;
    }
    if ( aux == NULL )
        return 0;

    *dado = aux->dado;

    if ( posicao == 1 )
        *l = aux->prox;

    else
        anterior->prox = aux->prox;

    free(aux);

}

void imprime(lista l){
    printf("\n [ ");
    while(!vazia(l)){
        printf("%d ", l->dado);
        l = l->prox;
    }
    printf("] \n");
}

