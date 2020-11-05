#include "stdafx.h"

typedef struct elemento
{
	int dado;
	sf::RectangleShape* layout;
	struct elemento *proximo;
} Elemento;

typedef struct pilha
{
	int completo;
	int errado;
	Elemento *topo;
} Pilha;

Pilha *inicializaPilha();


void colocaDado(int d, Pilha *p, sf::RectangleShape* lay);


int retiraDado(Pilha *p);


int compara(Pilha *p1, int s);


void exclui(Pilha *p);


void imprimePilha(Pilha *p, sf::RenderWindow *window);


void imprime(Elemento* e, sf::RenderWindow *window);
