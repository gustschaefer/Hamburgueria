# Hamburgueria

Este é um jogo criado por Vinicius Negrelli e Gustavo Schaefer para a disciplina "Estrutura de Dados e Algoritmos". O jogo tem como objetivo aplicar de maneira prática os conteúdos aprendidos na disciplina, além utilizar a biblioteca gráfica **SFML em C/C++** afim de criar interface pra o usuário. 

## Demo

<div align="center">
<img src="./screenshots/demo.gif" >
<p>Perfectly balanced</p>
</div>

<p align="center">
  ![](./screenshots/demo.gif)
</p>

## Sumário

- [Introdução](#introdução)
	- [Sinopse do jogo](#sinopse)
- [Descrição do problema](#descrição-do-problema)
	- [Estratégia de resolução](#estratégia-de-resolução)
	- [Cardápio](#cardápio)
	- [Soluções já existentes](#soluções-já-existentes)
- [Relação dos conceitos com a matéria](#relação-dos-conceitos-com-a-matéria)
    - [Pilha](#pilha)
    - [Fila](#fila)
    - [Recursão](#recursão)
- [Fluxograma](#fluxograma)
- [Descrição do fluxograma](#descrição-do-fluxograma)


## Introdução 

O projeto constitui em um jogo que simula o ambiente de uma hamburgueria, focando principalmente no fluxo de pedidos, feitos de maneira arbitraria pelos clientes (computador), e na montagem dos hamburguers. As principais motivações para a construção do projeto foram a demonstração de como estruturas de dados estão implicitamente presentes no cotidiano, e de como a otimização do pipeline de tarefas complexas pode ocorrer com a estrutura de dados apropriada, dependendo da situação e aplicabilidade dos dados. 

Como o ambiente de um restaurante é dinâmico, torna-se necessário utilizar estratégias para lidar com a quantidade de pedidos e clientes de forma rápida, mantendo a organização e respeitando a ordem correta das solicitações. Além disso, é imprescindível garantir que cada cliente receba seu hamburguer da mesma maneira que o pediu. Por este motivo, estruturas de dados são tão aplicáveis no projeto "Hamburgueria", já que com o auxílio delas há um ganho de velocidade e organização de tarefas trabalhosas.

Abaixo encontra-se uma sinopse do jogo, mais voltada para o jogador.

### Sinopse

Você já passou por uma situação em que pede o seu sanduiche sem picles e parece que o atendende ouviu que você queria o DOBRO de picles? Ou a fila de clientes era tão imensa que o pedido demorou uma eternidade pra chegar? Eis a solução! Esse jogo foi criado para preparar e capacitar os atendentes para que o seu sanduiche seja preparado rapidamente e montado de maneira impecável!

Seu objetivo é montar o sanduiche escolhido pelo cliente exatamente como foi pedido, e evitar que a fila de clientes chegue ao limite de pessoas. Tente entregar o maximo de pedidos que conseguir, antes que a aglomeração tome conta do seu restaurante. Sabendo disso, pegue seu avental, coloque suas luvas e prepare-se pra enfrentar o caos e o desespero.

É sempre bom lembrar que pedir um "hambúrger" deixa implícito que você quer carne no meio do pão, isto é, 
pedir um hambúrger com bacon e tomate implica em um hambúrger, bacon e tomate entre dois pães.


## Descrição do problema

Para criação do projeto, foram utilizadas duas estruturas de dados diferentes, sendo elas **Pilha** e **Fila**, além de **Recursão**. 

Durante o jogo, os clientes são gerados de maneira constante dentro de um intervalo de tempo, e este processo só acaba quando um número limite de clientes na fila de espera for atingido, ou seja, o restaurante está cheio e não há mais espaço para novos clientes. Portanto, o problema geral do projeto é lidar de maneira dinâmica com a entrada e saida de elementos (clientes) em uma fila, e trabalhar com a manipulação de dados em uma pilha (ingredientes do hamburguer).

Vale lembrar que todos os clientes gerados possuem um pedido, representado inicialmente por um número entre 1 e 20 (total de opções de hamburguer do restaurante) e que esses pedidos são feitos de maneira aleatória pelo programa.

### Estratégia de resolução

A estratégia de resolução do problema segue os seguintes passos:

1.	O cliente possui uma estrutura, contendo informações sobre seu pedido e a sua mesa. A medida em que o tempo passa, novos clientes são gerados.

2.	Quando um novo cliente for gerado, ele é posicionado em uma das mesas disponíveis, faz seu pedido, e entra na fila de espera até que seu hamburguer seja entregue.

3.	Para realizar o pedido, o cliente tem 20 opções diferentes de hamburguer. O programa utiliza a biblioteca ```time.h``` para gerar um número aleatório entre 1 e 20, e a partir desse número, o pedido é mapeado dentro do cardápio.

4.	O pedido do primeiro cliente da fila chega ao jogador, e ele o monta com os mesmos ingredientes solicitados, mas **não necessáriamente na mesma ordem**. O único pré requisito é que exista um pão na base e outro no topo do hambúrguer, pois só assim o jogo vai entender que o pedido foi feito e está disponível para entrega.

5.	Feita a montagem, o pedido é entregue na mesa do respectivo cliente. Se o hamburguer feito pelo jogador é igual ao solicitado, o cliente sai da fila de espera e o próximo freguês é atendido. 

6.	Como os clientes são gerados continuamente, o processo descrito acima é repetido até que o jogador perca o jogo, e então é mostrado a ele qual foi o número total de mesas antendidas corretamente.

### Cardápio

Como já dito, existem 20 opções disponiveis no cardápio. Cada opção foi criada **manualmente** por nós, e é composta pelos pães, hambúrguer e adicionais como queijo, tomate, picles, etc. Existem três tipos de sabor de carne para o pedido:

- Carne
- Peixe
- Frango

A lista de ingredientes aparece para o jogador na tela principal do jogo:

<p align="center">
  <img src="./screenshots/ingredientes.png">
</p>

Cada um desses ingredientes é representado por um número inteiro 2^n (1, 2, 4, 8, ..., 256).

* Queijo cheddar (Ch) = 1
* Queijo suiço (S) = 2
* Tomate (T) = 4 
* Picles (Pi) = 8
* Alface (A) = 16
* Hambúrguer de **carne** (Cr) = 32
* Hambúrguer de **frango** (F) = 64
* Hambúrguer de **peixe** (Px) = 128
* Bacon (B) = 256

Já o **pão** possue valor 0.

Portanto, o valor do pedido completo é a soma dos ingredientes que o compoem. Por exemplo, um hambúrguer de carne com alface, tomate, picles, cheddar e bacon é a soma:

0 (Pães) + 32 (hambúrguer de carne) + 16 (alface) + 4 (tomate) + 8 (picles) + 1 (cheddar) + 256 (bacon) = 
Valor do pedido: **317**

Logo, cada uma das 20 opções é representada por um número inteiro (soma dos ingredientes escolhidos por nós) que foi feita de maneira que nenhuma opção fosse igual. Utilizando a funcão ```srand(time(NULL))``` é possível gerar um número aleatório entre 1 e 20 (```int r = (rand() % 20) + 1```). Após isso, o número é mapeado com um dos pedidos possíveis do cardápio.

* 1 	===>	62 **(Cr + S + T + A + P)**
* 2 	===>	54 **(Cr + S + T + A)**
* 3 	===> 	37 **(Cr + Ch + T)**
* 4 	===>	58 **(Cr + S + Pi + A)**
* 5 	===>	89 **(F + Ch + A + Pi)**
* 6 	===>	86 **(F + S + A + T)**
* 7 	===>	93 **(F + C + A + T + Pi)**
* 8 	===>	74 **(F + S + Pi)**
* 9 	===>	30 **(A + T + P + S)**
* 10 	===>	109 **(F + Cr + T + Pi + C)**
* 11 	===>	142 **(Px + S + Pi + T)**
* 12	===>	153 **(Px + A + Pi + Ch)**
* 13	===>	404 **(Px + B + T + A)**
* 14	===>	297 **(Cr + B + Ch + Pi)**
* 15	===>	338 **(F + B + S + A)**
* 16 	===>	509 **(Px + Cr + F + B + Pi + Ch + A + T)**
* 17	===>	119 **(Cr + F + S + Ch + A +T)**
* 18	===>	480 **(F + Cr + Px + B)**
* 19	===>	150 **(Px + A + T + S)**
* 20	===>	171 **(Px + Pi + Cr + S + Ch)**

### Soluções já existentes

Não encontramos nenhum jogo similar ao nosso, e portanto nenhuma solução pré existente para o problema. Apenas nos baseamos nos conteúdos aprendidos em sala de aula e tentamos aplicar tudo de uma maneira criativa e eficiente.


## Relação dos conceitos com a matéria

Como dito acima, dois tipos diferentes de estrutura de dados foram usados, cada uma desempenhando um papel específico no fluxo de funcionamento do programa. Abaixo é descrito detalhadamente o motivo da utilização de cada uma.

### Pilha 

O principal motivo para a utilização da pilha foi a **montagem do hamburguer**.

Como pilhas são caracterizadas por uma estrutura de dados em que o último dado inserido é o topo, decidimos utilizá-las como responsáveis na montagem dos hamburguers, pois os ingredientes são empilhados de maneira coerente, sempre um pão na base, ingredientes no meio, e outro pão no topo. Dessa maneira não há como modificar o pedido em suas partes intermediarias, e sempre que um pão for o topo da pilha, ou a montagem do pedido foi iniciada ou o pedido foi finalizado.

Outro fator importante é como cada 

### Fila

O principal motivo para a utilização da fila foi **ordenação dos clientes**.

Filas são essenciais, pois como os pedidos devem ser feitos e entregues para o primeiro cliente que pediu (início da fila), há um gerenciamento de como está o andamento do restaurante, pois podemos saber o tamanho da fila e qual cliente da vez. Ao escolher sua mesa e realizar o pedido, o cliente fica na fila aguardando, já que muito provavelmente outros clientes já haviam chegando antes dele, e possuem prioridade de entrega por estarem em posições mais avançadas na espera. Na medida em que os hamburguers são entregues, o próximo da fila deve ser o próximo cliente atendido, e assim até não haver mais clientes aguardando nas mesas, ou seja, nenhum cliente está na fila.

### Recursão




## Fluxograma



## Descrição do fluxograma
