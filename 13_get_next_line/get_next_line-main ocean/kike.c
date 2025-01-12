#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>


typedef struct ElementoLista {
	int valor;
	struct ElementoLista *prox;
} Item;

//typedef struct ElementoLista Item;

void insereFim(Item* cabeca, int valor);
void imprime(Item *cabeca);
void libera(Item* cabeca);

int main()//int argc, char argv[])
{
	//cria a cabeca da lista
	Item cabeca;
	cabeca.prox = NULL;	// vazia, nao aponta para nada

	// imprime o tamanho em bytes de um item
	printf("Tamanho do item: %d bytes\n", sizeof(Item));

	// insere ao final da lista um item alocado dinamicamente
	printf("\nInserindo itens novos na lista...\n");
	insereFim(&cabeca, 15);
	insereFim(&cabeca, 125);
	insereFim(&cabeca, 155);

	// aguarda o usuario pressionar uma tecla
	getchar();

	// uma funcao para imprimir os itens da lista
	printf("\nImprimindo itens da lista...\n");
	imprime(&cabeca);

	// aguarda o usuario pressionar uma tecla
	getchar();

	// uma funcao para liberar a memoria
	printf("\nLiberando memoria dos itens da lista...\n");
	libera(&cabeca);

	getchar();
	return 0;
}

// funcao para insercao e item
void insereFim(Item *cabeca, int valor) {

	// cria um ponteiro para novo item e aloca dinamicamente
	Item *novo = (Item*)malloc(sizeof(Item));

	// inicializa o novo item
	novo->prox = NULL;		// se torna o ultimo da lista
	novo->valor = valor;	// conteudo do Item

	printf("Item de valor %3d alocado no endereco: 0x%000000X\n", novo->valor, novo);

	// varre a lista do comeco para chegar na ultima posicao
	Item *atual = cabeca;
	while(atual->prox!=NULL) {
		atual = atual->prox;
	}

	// chagando na ultima posicao coloca o ponteiro pro novo elemento
	atual->prox = novo;

}

// funcao para imprimir os elementos
void imprime(Item* cabeca) {
	// este item aponta para o item atual sendo impresso
	// como o item do inicio eh a cabeca, a impressao comeca no proximo item
	Item *atual = cabeca->prox;

	//laco que executa até o ultimo item
	int i = 0;
	while(atual!=NULL) {
		printf("Valor do item: %3d\n", atual->valor);
		i++;
		// faz a atual mover para o proximo item
		atual = atual->prox;
	}
	printf("Total de itens da lista: %d\n", i);

}

void libera(Item* cabeca) {
	// ponteiro para o inicio da lista
	Item *atual = cabeca->prox;

	//ponteiro para o item a ser liberado
	Item *liberado;

	//parte do inicio da lista, elimando todos os itens
	while(atual!=NULL) {
		// o liberado recebe o endereco do atual a ser liberado
		liberado = atual;
		// o atual recebe o endereco do proximo a ser liberado
		atual = atual->prox;
		printf("Liberando o item de valor %3d na posicao %00000X\n", liberado->valor, liberado);
		//libera a atual
		free(liberado);
	}
}