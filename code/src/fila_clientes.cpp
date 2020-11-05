#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila_clientes.h"


Fila* inicializa_Fila()
{
	Fila* f;
	f = (Fila*)malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	f->tamanho = 0;
	return f;
}

void novoCliente(int mesa, int pedido, Fila* f) // adiciona um novo cliente na fila a partir da sua mesa e seu pedido
{
	Cliente* novoCliente;
	novoCliente = (Cliente*)malloc(sizeof(Cliente));
	novoCliente->mesa = mesa;
	novoCliente->pedido = pedido;
	novoCliente->proximo = NULL;
	if (f->inicio == NULL)
	{
		f->fim = f->inicio = novoCliente;
	}
	else
	{
		f->fim->proximo = novoCliente;
		f->fim = novoCliente;
	}
	f->tamanho++;
}

int retiraCliente(Fila* f)
{
	int saida = f->inicio->mesa;
	Cliente* retirado;
	retirado = (Cliente*)malloc(sizeof(Cliente));
	retirado = f->inicio;
	if (f->fim != f->inicio)
	{
		f->inicio = f->inicio->proximo;
	}
	else
	{
		f->fim = f->inicio = NULL;
	}
	free(retirado);
	f->tamanho--;
	return saida;
}

int imprime_Fila(Fila* f)
{
	int length = 0;
	Cliente* iterador;
	iterador = (Cliente*)malloc(sizeof(Cliente));
	iterador = f->inicio;
	while (iterador != NULL)
	{
		printf("%i ", iterador->mesa);
		iterador = iterador->proximo;
		length += 1;
	}
	printf("\n");
	printf("numero de clintes na fila: %d\n", length);
	return length;
}

int generate_recipe() // gera o pedido do cliente de maneira aleatoria
{
	srand(time(NULL));
	int nuumero_receitas = 21;
	int r = (rand() % nuumero_receitas) + 1; // gera um numero aleatorio entre 1 e 16

	switch (r)
	{
		case 1:
			r = 62;
			break;
		case 2:
			r = 54;
			break;
		case 3:
			r = 37;
			break;
		case 4:
			r = 58;
			break;
		case 5:
			r = 89;
			break;
		case 6:
			r = 86;
			break;
		case 7:
			r = 93;
			break;
		case 8:
			r = 74;
			break;
		case 9:
			r = 30;
			break;
		case 10:
			r = 109;
			break;
		case 11:
			r = 142;
			break;
		case 12:
			r = 153;
			break;
		case 13:
			r = 404;
			break;
		case 14:
			r = 297;
			break;
		case 15:
			r = 338;
			break;
		case 16:
			r = 509;
			break;
		case 17:
			r = 119;
			break;
		case 18:
			r = 480;
			break;
		case 19:
			r = 150;
			break;
		case 20:
			r = 171;
			break;
		case 21:
			r = 947;
		default:
			break;
	}

	return r;
}



void generate_client(Fila* f, int mesa) // coloca novos clientes na fila e gera o pedido
{
	printf("Novo cliente na mesa: %d\n", mesa);

	int pedido = generate_recipe();
	printf("Pedido do cliente: %d\n", pedido);

	novoCliente(mesa, pedido, f);
	//sleep(generation_time); // tirei o sleep//muito obrigado :>
}