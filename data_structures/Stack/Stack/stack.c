/*=====================================================================================================================
Tipo de estrutura: Pilha
Descrição: 
- A pilha permite empilhar e desempilhar dados;
- Todas as operações acontecem no topo da pilha;
- Cada nó conhece o primeiro nó que está abaixo dele;
- O nó da base aponta para NULL.
=====================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>			// Para usar as funções de alocação dinâmica de memória (malloc, realloc e free)

// Representa um nó da pilha
typedef struct {
	int data;				// O dado pode ser de qualquer tipo (não precisa ser necessáriamente int)
	struct Node * next;		// Endereço do nó de baixo
}Node;

// Função para empilhar novos nós na pilha
void push(Node **, int);

int main() {
	// Referência para o topo (tudo acontece nele)
	Node * top = NULL;		// Inicializa a pilha vazia

	// Empilha um novo nó
	push(&top, 3);

	// Verifica se o valor foi adicionado corretamente
	if (top) {
		printf("Topo da pilha: %d\n", top->data);
	}

	// Empilha um novo nó
	push(&top, 4);

	// Verifica se o valor foi adicionado corretamente
	if (top) {
		printf("Topo da pilha: %d\n", top->data);
	}

	return 0;
}

// Recebe o topo antigo, cria um novo nó, faz ele apontar pro topo antigo e
void push(Node ** oldTop, int value) {
	Node * newNode = (void *)malloc(sizeof(Node));	// Aloca dinamicamente um registro Node e guarda o seu endereço
	// Verifica se não houve erro na alocação (se conseguiu criar o nó)
	if (newNode) {
		newNode->data = value;		// O novo nó guarda o valor
		newNode->next = *oldTop;	// O novo nó aponta pro topo antigo
		*oldTop = newNode;			// Atualiza o topo na main
	}
	else {
		printf("Erro ao alocar memória!\n");
	}
}