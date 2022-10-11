#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct tipoElemento{
	int valor;
	struct tipoElemento *prox;
}TElemento;

typedef struct TipoLista{
	TElemento *inicio;
	TElemento *fim;
	int total;
}TLista;

TLista lista;

void inicializaLista(TLista *lista);
int menu();
void insere(TLista *lista);
void exibir_lista(TLista *lista);
void excluirElemento(TLista *lista);
void buscar_valor(TLista *lista);


