#include "listas.h"

void inicializaLista(TLista *lista){
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->total = 0;
}

int menu(){
	int opcao;
	system("CLS"); //Limpa a Tela e posiciona o 
	               //CURSOR no canto esquerdo superior da mesma
    printf("\n\n\n\t=====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Inserir.\n");
    printf("2 - Exibir Lista Completa.\n");
    printf("3 - Excluir.\n");
    printf("4 - Buscar valor.\n");
    printf("\tInforme OPCAO desejada: ");
    
    scanf("%d",&opcao);
	
	if ((opcao > 4) || (opcao < 0)){
		printf("\n\n\n");
		printf("+-------------------------------+\n");
		printf("|ERRO  	------------------------|\n");
		printf("|Op��o inv�lida	----------------|\n");
		printf("|Tente outra vez    ------------|\n");
		printf("+-------------------------------+\n\n\n");
		system("PAUSE");
	}
	return opcao;
}

void insere(TLista *lista){
	TElemento *novo = (TElemento*)malloc(sizeof(TElemento));
	int inserido = 0;
	
	printf("\n\nInsira um valor: ");
	scanf("%d" , &novo->valor);
	
	novo->prox = NULL;
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
	} else {
		TElemento *anterior = NULL;
		TElemento *atual = lista->inicio;
		
		while(atual != NULL){
			if(atual->valor > novo->valor){
				inserido = 1;
				novo->prox = atual;
				
				if(anterior == NULL){
					lista->inicio = novo;
				} else {
					anterior->prox = novo;
				}
				break;
			}
			anterior = atual;
			atual = atual->prox;
		}
		if(!inserido){
			lista->fim->prox = novo;
			lista->fim = novo;
		}
	}
	
	lista->total++;
	
}

void exibir_lista(TLista *lista){
	TElemento *atual = lista->inicio;
	int cont=0;
	while(atual != NULL){
		printf("\n(%d) - Valor: %d\n" ,++cont, atual->valor);
		atual = atual->prox;
	}
	printf("\n\n");
}

void excluirElemento(TLista *lista){
	TElemento *atual=NULL, *anterior=NULL;
	int excluido = 0;
	int argumento;
		
	printf("\n\nInsira o valor que ser� removido: ");
	scanf("%d" ,&argumento);
	
	if(lista->inicio == NULL){
		printf("\n\nNenhum elemento na lista\n\n\n");	
	}else {
		atual = lista->inicio;
		while(atual != NULL){
			if(atual->valor == argumento){
				excluido = 1;
				if(anterior == NULL){
					lista->inicio = atual->prox;
				} else {
					anterior->prox = atual->prox;
					if(atual == lista->fim){
						lista->fim = NULL;
					}
				}
				free(atual);
				lista->total--;
				break;
			}
			anterior = atual;
			atual = atual->prox;
		}
		if(!excluido){
			printf("\t\n\nElemento %d n�o encontrado!!", argumento);
			printf("\t\n\nTente novamente\n\n\n");
		}
	}
}

void buscar_valor(TLista *lista){
	TElemento *atual = lista->inicio;
	int argumento=0, encontrado=0;
	
	printf("\n\nInsira o valor que ser� pesquisado: ");
	scanf("%d" ,&argumento);
	
	while(atual != NULL){
		if(atual->valor == argumento){
			encontrado = 1;
			printf("\t\n\nElemento %d encontrado!\n\n\n");
		}
		atual = atual->prox;
	}
	
	if(!encontrado){
		printf("\t\n\nElemento %d n�o encontrado!!", argumento);
		printf("\t\n\nTente novamente\n\n\n");
	}
	
}
