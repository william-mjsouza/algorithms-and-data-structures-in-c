/*=====================================================================================================================
Tipo de estrutura: Pilha
Descri��o: 
- A pilha permite empilhar e desempilhar dados;
- Todas as opera��es acontecem no topo da pilha;
- Cada n� conhece o primeiro n� que est� abaixo dele;
- O n� da base aponta para NULL.
=====================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>			// Para usar as fun��es de aloca��o din�mica de mem�ria (malloc, realloc e free)

// Representa um n� da pilha
typedef struct {
	int data;				// O dado pode ser de qualquer tipo (n�o precisa ser necess�riamente int)
	struct Node * next;		// Endere�o do n� de baixo
}Node;

// Fun��o para empilhar novos n�s na pilha
void push(Node **, int);

int main() {
	// Refer�ncia para o topo (tudo acontece nele)
	Node * top = NULL;		// Inicializa a pilha vazia

	// Empilha um novo n�
	push(&top, 3);

	// Verifica se o valor foi adicionado corretamente
	if (top) {
		printf("Topo da pilha: %d\n", top->data);
	}

	// Empilha um novo n�
	push(&top, 4);

	// Verifica se o valor foi adicionado corretamente
	if (top) {
		printf("Topo da pilha: %d\n", top->data);
	}

	return 0;
}

// Recebe o topo antigo, cria um novo n�, faz ele apontar pro topo antigo e
void push(Node ** oldTop, int value) {
	Node * newNode = (void *)malloc(sizeof(Node));	// Aloca dinamicamente um registro Node e guarda o seu endere�o
	// Verifica se n�o houve erro na aloca��o (se conseguiu criar o n�)
	if (newNode) {
		newNode->data = value;		// O novo n� guarda o valor
		newNode->next = *oldTop;	// O novo n� aponta pro topo antigo
		*oldTop = newNode;			// Atualiza o topo na main
	}
	else {
		printf("Erro ao alocar mem�ria!\n");
	}
}