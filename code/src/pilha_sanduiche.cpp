#include <stdio.h>
#include <stdlib.h>
#include "pilha_sanduiche.h"

Pilha *inicializaPilha()
{
	Pilha *p;
	p = (Pilha *)malloc(sizeof(Pilha));
	p->topo = NULL;
	p->completo = 0;
	p->errado = 0;
	return p;
}

void colocaDado(int d, Pilha *p, sf::RectangleShape* lay)
{
	if (p != NULL && p->completo != 1)
	{
		if (p->topo != NULL)
		{
			Elemento *novoDado;
			novoDado = (Elemento *)malloc(sizeof(Elemento));
			novoDado->dado = d;
			novoDado->layout = lay;
			Elemento *iterador;
			iterador = p->topo;
			while (iterador != NULL)
			{
				if (novoDado->dado == iterador->dado)
				{
					p->errado = 1;
				}
				iterador = iterador->proximo;
			}
			novoDado->proximo = p->topo;
			p->topo = novoDado;
			if (novoDado->dado == -1)
			{
				p->completo = 1;
			}
		}
		else if (d == 0)
		{
			Elemento *novoDado;
			novoDado = (Elemento *)malloc(sizeof(Elemento));
			novoDado->dado = d;
			novoDado->layout = lay;
			Elemento *iterador;
			iterador = p->topo;
			while (iterador != NULL)
			{
				if (novoDado->dado == iterador->dado)
				{
					p->errado = 1;
				}
				iterador = iterador->proximo;
			}
			novoDado->proximo = p->topo;
			p->topo = novoDado;
		}
	}

}

int retiraDado(Pilha *p)
{
	if (p != NULL && p->topo != NULL)
	{
		int saida = p->topo->dado;
		Elemento *aux = p->topo;
		p->topo = p->topo->proximo;
		free(aux);
		aux = NULL;
		return saida;
	}
	return -1;
}

int compara(Pilha *p1, int s)
{
	int soma = 0;
	retiraDado(p1);
	while (p1->topo != NULL)
	{
		soma = soma + retiraDado(p1);
	}
	p1->completo = 0;
	soma = soma - s;
	if (soma == 0 && p1->errado == 0)
	{
		return 1;
	}
	else
	{
		p1->errado = 0;
		return 0;
	}
}

void exclui(Pilha *p)
{
	if (p != NULL && p->topo != NULL)
	{
		while (p->topo != NULL)
		{
			Elemento *aux = p->topo;
			p->topo = p->topo->proximo;
			free(aux);
			aux = NULL;
		}
		p->completo = 0;
		p->errado = 0;
	}
}


void imprimePilha(Pilha *p, sf::RenderWindow *window)
{
	if (p->topo !=NULL)
		imprime(p->topo, window);
}

void imprime(Elemento* e, sf::RenderWindow *window)
{
	if (e->proximo != NULL)
	{
		imprime(e->proximo, window );
	}
	window->draw(*(e->layout));
}