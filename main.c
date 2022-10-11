#include "listas.h"

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "portuguese");
	int op;
	inicializaLista(&lista);

	do {
		op = menu();
		
		switch(op){
			case 1: insere(&lista); break;
			case 2: exibir_lista(&lista); break;
			case 3:	excluirElemento(&lista); break;
			case 4: buscar_valor(&lista); break;
		}

		system("pause");
		
	}while(op != 0);
	
	return 0;
}
