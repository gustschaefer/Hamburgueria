#include "stdafx.h"
#include "pilha_sanduiche.h"
#include "fila_clientes.h"

int main()
{
	Pilha* p;
	p = inicializaPilha();
	Fila* f;
	f = inicializa_Fila();
	bool menu = true;
	int estado = 0;
	bool pedido_ativo = false;
	// 0= nao tem ingrediente selecionado
	// 1= clicou / arrastando
	int d = 0;
	int y = 430;
	int h = 0;
	int iniciado = 0;
	int alting = 50;
	bool fundopadrao = true;
	int tempo = 9;
	int aux = 0;
	int auxespera = 0;
	int pedidos = 0;
	int duplo = 0;
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1280, 720), "hamburg", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape fundo1(sf::Vector2f(1280.0f, 720.0f));
	sf::Texture fundo;
	fundo.loadFromFile("fundo2.png");
	sf::RectangleShape espera(sf::Vector2f(186.0f, 73.0f));
	espera.setPosition(sf::Vector2f(1050, 220));
	sf::Texture alerta;
	alerta.loadFromFile("alerta0.png");
	espera.setTexture(&alerta);
	sf::RectangleShape fundo2(sf::Vector2f(1280.0f, 720.0f));
	sf::Texture fundo3;
	fundo3.loadFromFile("fundo3.png");
	fundo2.setTexture(&fundo3);
	sf::Texture textura1;
	textura1.loadFromFile("cheddar.png");
	sf::Texture textura2;
	textura2.loadFromFile("queijo.png");
	sf::Texture textura3;
	textura3.loadFromFile("tomate.png");
	sf::Texture textura4;
	textura4.loadFromFile("picles.png");
	sf::Texture textura5;
	textura5.loadFromFile("alface.png");
	sf::Texture textura6;
	textura6.loadFromFile("hamburger.png");
	sf::Texture textura7;
	textura7.loadFromFile("frango.png");
	sf::Texture textura8;
	textura8.loadFromFile("pao.png");
	sf::Texture textura0;
	textura0.loadFromFile("pao2.png");
	sf::Texture textura9;
	textura9.loadFromFile("peixe.png");
	sf::Texture textura10;
	textura10.loadFromFile("bacon.png");
	sf::Texture textura11;
	textura11.loadFromFile("transparente.png");
	sf::Texture textura12;
	textura12.loadFromFile("pedido62.png");
	sf::Texture textura13;
	textura13.loadFromFile("pedido54.png");
	sf::Texture textura14;
	textura14.loadFromFile("pedido37.png");
	sf::Texture textura15;
	textura15.loadFromFile("pedido58.png");
	sf::Texture textura16;
	textura16.loadFromFile("pedido89.png");
	sf::Texture textura17;
	textura17.loadFromFile("pedido86.png");
	sf::Texture textura18;
	textura18.loadFromFile("pedido93.png");
	sf::Texture textura19;
	textura19.loadFromFile("pedido74.png");
	sf::Texture textura20;
	textura20.loadFromFile("pedido30.png");
	sf::Texture textura21;
	textura21.loadFromFile("pedido109.png");
	sf::Texture textura22;
	textura22.loadFromFile("pedido142.png");
	sf::Texture textura23;
	textura23.loadFromFile("pedido153.png");
	sf::Texture textura24;
	textura24.loadFromFile("pedido404.png");
	sf::Texture textura25;
	textura25.loadFromFile("pedido297.png");
	sf::Texture textura26;
	textura26.loadFromFile("pedido338.png");
	sf::Texture textura27;
	textura27.loadFromFile("pedido509.png");
	sf::Texture textura28;
	textura28.loadFromFile("pedido119.png");
	sf::Texture textura29;
	textura29.loadFromFile("pedido480.png");
	sf::Texture textura30;
	textura30.loadFromFile("pedido150.png");
	sf::Texture textura31;
	textura31.loadFromFile("pedido171.png");
	sf::Texture textura32;
	textura32.loadFromFile("pedido947.png");
	sf::Texture texturamenu;
	texturamenu.loadFromFile("Menu1.png");
	fundo1.setTexture(&texturamenu);





	sf::Clock clock;
	sf::Time time;
	int segundos;


	while (1)
	{


		sf::RectangleShape* selecionado = NULL;
		sf::RectangleShape* pedido = new sf::RectangleShape(sf::Vector2f(240, 141));
		pedido->setPosition(sf::Vector2f(1000, 25));
		



		//pedido->setTexture(&textura12);
		while (window->isOpen())
		{
			sf::Vector2i mousepos = sf::Mouse::getPosition(*window);
			while (menu)
			{
				sf::Vector2i mousepos = sf::Mouse::getPosition(*window);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& mousepos.x >= 295 && mousepos.x <= 1025 && mousepos.y >= 225 && mousepos.y <= 525 && aux ==0)
				{
					texturamenu.loadFromFile("Menu3.png");
					fundo1.setTexture(&texturamenu);
					aux = 1;
				}
				else if(aux == 1 && !(mousepos.x >= 295 && mousepos.x <= 1025 && mousepos.y >= 225 && mousepos.y <= 525)){
					texturamenu.loadFromFile("Menu1.png");
					fundo1.setTexture(&texturamenu);
					aux = 0;
				}

				if (aux == 1 && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
				{
					texturamenu.loadFromFile("Menu4.png");
					fundo1.setTexture(&texturamenu);
					menu = false;
					window->clear();
					window->draw(fundo1);
					window->display();
					fundo1.setTexture(&fundo);
					Sleep(1000);
					generate_client(f, 1);
					aux = 0;
					clock.restart();
					break;
				}
				sf::Event evnt;
				while (window->pollEvent(evnt))
				{
					if (evnt.type == evnt.Closed)
					{
						window->close();
						break;
					}
				}
			window->clear();
			window->draw(fundo1);
			window->display();
				
			}

			time += clock.restart();
			segundos = static_cast<unsigned int>(time.asSeconds());
			

			if (segundos % 10 == tempo)
			{
				printf("tempo! %d", segundos);
				generate_client(f, 1);
				time = clock.restart();
				if (aux == 5)
				{
					tempo--;
					aux = 0;
				}
				else aux++;
			}
			if (pedido_ativo == false && f->inicio != NULL)
			{
				switch (f->inicio->pedido)
				{
				case 62:
					pedido->setTexture(&textura12);
					break;
				case 54:
					pedido->setTexture(&textura13);
					break;
				case 37:
					pedido->setTexture(&textura14);
					break;
				case 58:
					pedido->setTexture(&textura15);
					break;
				case 89:
					pedido->setTexture(&textura16);
					break;
				case 86:
					pedido->setTexture(&textura17);
					break;
				case 93:
					pedido->setTexture(&textura18);
					break;
				case 74:
					pedido->setTexture(&textura19);
					break;
				case 30:
					pedido->setTexture(&textura20);
					break;
				case 109:
					pedido->setTexture(&textura21);
					break;
				case 142:
					pedido->setTexture(&textura22);
					break;
				case 153:
					pedido->setTexture(&textura23);
					break;
				case 404:
					pedido->setTexture(&textura24);
					break;
				case 297:
					pedido->setTexture(&textura25);
					break;
				case 338:
					pedido->setTexture(&textura26);
					break;
				case 509:
					pedido->setTexture(&textura27);
					break;
				case 119:
					pedido->setTexture(&textura28);
					break;
				case 480:
					pedido->setTexture(&textura29);
					break;
				case 150:
					pedido->setTexture(&textura30);
					break;
				case 171:
					pedido->setTexture(&textura31);
					break;
				case 947:
					pedido->setTexture(&textura32);
				default:
					break;
				}
				pedido_ativo = true;
			}

			if (fundopadrao == false)
			{
				fundo.loadFromFile("fundo2.png");
				fundopadrao = true;
			}

			sf::Event evnt;
			while (window->pollEvent(evnt))
			{
				if (evnt.type == evnt.Closed)
				{
					window->close();
				}
			}

			if (f->tamanho != auxespera)
			{
				switch (f->tamanho)
				{
				case 1:
					alerta.loadFromFile("alerta0.png");
					auxespera = 1;
					break;
				case 2:
					alerta.loadFromFile("alerta1.png");
					auxespera = 2;
					break;
				case 3:
					alerta.loadFromFile("alerta2.png");
					auxespera = 3;
					break;
				case 4:
					alerta.loadFromFile("alerta3.png");
					auxespera = 4;
					break;
				case 5:
					alerta.loadFromFile("alerta4.png");
					auxespera = 5;
					break;
				case 6:
					alerta.loadFromFile("alerta5.png");
					auxespera = 6;
					break;
				case 7:
					printf("\n\nFim do jogo!!\n\nPedidos entregues : %d", pedidos);
					window->close();
				default:
					break;
				}
				espera.setTexture(&alerta);
			}


			if (estado == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				estado = 1;
				//if (selecionado == NULL)
				selecionado = new sf::RectangleShape(sf::Vector2f(500, 200));
				selecionado->setPosition(sf::Vector2f(1280, 720));
				if (p->topo == NULL)
				{
					iniciado = 0;
				}
				if (mousepos.x >= 10 && mousepos.x <= 160)
				{
					if (mousepos.y >= 10 && mousepos.y <= 85)
					{
						selecionado->setTexture(&textura1);
						d = 1;
						alting = 50;
						h = 10;
					}
					else if (mousepos.y >= 95 && mousepos.y <= 170)
					{
						selecionado->setTexture(&textura3);
						d = 4;
						h = 0;
						alting = 15;
					}
					else if (mousepos.y >= 180 && mousepos.y <= 255)
					{
						selecionado->setTexture(&textura5);
						d = 16;
						alting = 20;
						h = 5;
					}
					else if (mousepos.y >= 265 && mousepos.y <= 340)
					{
						selecionado->setTexture(&textura7);
						d = 64;
						alting = 40;
						h = -10;
					}
					else if (mousepos.y >= 350 && mousepos.y <= 425)
					{
						selecionado->setTexture(&textura9);
						d = 128;
						alting = 20;
						h = -10;
					}
					else
					{
						estado = 0;
						//selecionado = NULL;
					}
				}
				else if (mousepos.x >= 170 && mousepos.x <= 320)
				{
					if (mousepos.y >= 10 && mousepos.y <= 85)
					{
						selecionado->setTexture(&textura2);
						d = 2;
						h = 10;
						alting = 50;
					}
					else if (mousepos.y >= 95 && mousepos.y <= 170)
					{
						selecionado->setTexture(&textura4);
						d = 8;
						h = 5;
						alting = 15;
					}
					else if (mousepos.y >= 180 && mousepos.y <= 255)
					{
						h = -8;
						alting = 35;
						selecionado->setTexture(&textura6);
						if (duplo == 0)
						{
							d = 32;
						}
						else
						{
							d = 512;
						}
					}
					else if (mousepos.y >= 265 && mousepos.y <= 340)
					{
						if (iniciado == 0)
						{
							selecionado->setTexture(&textura8);
							d = 0;
							alting = 50;
						}
						else
						{
							selecionado->setTexture(&textura0);
							d = -1;
							h = -30;
						}
					}
					else if (mousepos.y >= 350 && mousepos.y <= 425)
					{
						selecionado->setTexture(&textura10);
						d = 256;
						h = 0;
						alting = 15;
					}
					else
					{
						estado = 0;
						//selecionado = NULL;
					}
				}
				else if (mousepos.x >= 970 && mousepos.x <= 1050 && mousepos.y >= 600 && mousepos.y <= 680)
				{
					printf("aqui");
					exclui(p);
					y = 430;
					h = 0;
					d = 0;
					iniciado = 0;
					alting = 50;
					selecionado->setTexture(&textura11);
				}
				else if (mousepos.x >= 1080 && mousepos.x <= 1230 && mousepos.y >= 500 && mousepos.y <= 570 && p->completo == 1)
				{
					selecionado->setTexture(&textura11);
					if (compara(p, f->inicio->pedido)) {
						printf("mandou benzao!");
						fundo.loadFromFile("fundocerto.png");
						retiraCliente(f);
						pedido_ativo = false;
						pedidos++;
						exclui(p);
						duplo = 0;
					}
					else
					{
						printf("errooou!");
						fundo.loadFromFile("fundoerrado.png");
						exclui(p);
						duplo = 0;
					}
					fundopadrao = false;
				}

				else
				{
					estado = 0;
					//selecionado = NULL;
				}
			}

			else if (estado == 1)
			{
				sf::Vector2i mousepos = sf::Mouse::getPosition(*window);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (selecionado != NULL)
						selecionado->setPosition((float)mousepos.x - 250, (float)mousepos.y - 100);
					//window.clear();
					//window.draw(*selecionado);
					//window.display();

				}
				else
				{
					if (mousepos.x >= 390 && mousepos.x <= 890 && mousepos.y <= 600)
					{
						y = y + h;
						if (d == 0)
						{
							y = 430;
						}
						selecionado->setPosition(390, y);
						colocaDado(d, p, selecionado);
						y = y - alting;
						printf("adicionado %d\n", d);
						if (d == 0)
						{
							iniciado = 1;
						}
						if (d == -1)
						{
							iniciado = 0;
						}
						if (d == 32 && iniciado == 1)
						{
							duplo = 1;
						}
						if (d == 512)
						{
							duplo = 0;
						}
					}
					else
					{
						delete selecionado;
					}
					estado = 0;
					selecionado = NULL;
				}

			}
			window->clear();

			if (p->completo == 0)
			{
				window->draw(fundo1);
			}
			else
			{
				window->draw(fundo2);
			}

			window->draw(espera);

			imprimePilha(p, window);

			if (selecionado != NULL && estado == 1)
				window->draw(*selecionado);

			if (f->inicio != NULL)
				window->draw(*pedido);

			window->display();
		}
		break;
	}
	getchar();
	return 0;
}
