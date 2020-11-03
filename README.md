# Hamburgueria

Este é um jogo criado por Vinicius Negrelli e Gustavo Schaefer para a disciplina "Estrutura de Dados e Algoritmos". O jogo tem como objetivo aplicar de maneira prática os conteúdos aprendidos na disciplina, além utilizar a biblioteca gráfica **SFML em C/C++** afim de criar interface pra o usuário. 

## Demo

![](./screenshots/demo.gif)

## Sumário

- [Introdução](#introdução)
	- [Sinopse do jogo](#sinopse)
- [Descrição do problema](#descrição-do-problema)
- [Relação dos conceitos com a matéria](#relação-dos-conceitos-com-a-matéria)
    - [Pilha](#pilha)
    - [Fila](#fila)
    - [Recursão](#recursão)
- [Fluxograma](#fluxograma)
- [Descrição do fluxograma](#descrição-do-fluxograma)


## Introdução 

O projeto constitui em um jogo que simula o ambiente de uma hamburgueria, focando principalmente no fluxo de pedidos, feitos de maneira arbitraria pelos clientes (computador), e na montagem dos hamburguers. As principais motivações para a construção do projeto foram a demonstração de como estruturas de dados estão implicitamente presentes no cotidiano, e de como a otimização do pipeline de tarefas complexas pode ocorrer com a estrutura de dados apropriada, dependendo da situação e aplicabilidade dos dados. 

Como o ambiente de um restaurante é dinâmico, torna-se necessário utilizar estratégias para lidar com a quantidade de pedidos e clientes de forma rápida, mantendo a organização e respeitando a ordem correta das solicitações. Além disso, é imprescindível garantir que cada cliente receba seu hamburguer da mesma maneira que o pediu. Por este motivo, estruturas de dados são tão aplicáveis projeto "Hamburgueria", já que com o auxílio delas há um ganho de velocidade e organização de tarefas trabalhosas.

Abaixo encontra-se uma sinopse do jogo, mais voltada para o jogador.

### Sinopse

Você já passou por uma situação em que pede o seu sanduiche sem picles e parece que o atendende ouviu que você queria o DOBRO de picles? Ou a fila de clientes era tão imensa que o pedido demorou uma eternidade pra chegar? Eis a solução! Esse jogo foi criado para preparar e capacitar os atendentes para que o seu sanduiche seja preparado rapidamente e montado de maneira impecável!

Seu objetivo é montar o sanduiche escolhido pelo cliente exatamente como foi pedido, e evitar que a fila de clientes chegue ao limite de pessoas. Tente entregar o maximo de pedidos que conseguir, antes que a aglomeração tome conta do seu restaurante. Sabendo disso, pegue seu avental, coloque suas luvas e prepare-se pra enfrentar o caos e o desespero.

É sempre bom lembrar que pedir um "hambúrger" deixa implícito que você quer carne no meio do pão, isto é, 
pedir um hambúrger com bacon e tomate implica em um hambúrger, bacon e tomate entre dois pães.


## Descrição do problema

Para criação do projeto, foram utilizadas duas estruturas de dados diferentes, sendo elas **Pilha** e **Fila**, além de **Recursão**. 

Durante o jogo, os clientes são gerados de maneira constante dentro de um intervalo de tempo, e este processo só acaba quando um número limite de clientes na fila de espera for atingido, ou seja, o restaurante está cheio e não há mais espaço para novos clientes. Portanto, o problema geral do projeto é lidar de maneira dinâmica com a entrada e saida de elementos (clientes) em uma fila, e trabalhar com a manipulação de dados em uma pilha (ingredientes do hamburguer).

Vale lembrar que todos os clientes gerados possuem um pedido, representado inicialmente por um número de 1 a 20 (total de opções de hamburguer do restaurante) e que esses pedidos são feitos de maneira aleatória pelo programa.

A estratégia de resolução segue os seguintes passos:

1. O cliente possui uma estrutura, contendo informações sobre seu pedido e a sua mesa. A medida em que o tempo passa, novos clientes são gerados.

2. Quando um novo cliente for gerado, ele é posicionado em uma das mesas disponíveis, faz seu pedido, e entra na fila de espera até que seu hamburguer seja entregue.

3. Para realizar o pedido, o cliente tem 20 opções diferentes de hamburguer. O programa utiliza a biblioteca ```time.h``` para gerar um número aleatório entre 1 e 20 e a partir desse número, o pedido é mapeado dentro do cardápio.

4. O pedido do primeiro cliente da fila chega ao jogador, e ele o monta com os mesmos ingredientes solicitados, mas **não necessáriamente na mesma ordem**. O único pré requisito é que exista um pão na base e outro no topo do hamburguer, pois só assim o jogo vai entender que o pedido foi feito e está disponível para entrega.

5. Feita a montagem, o pedido é entregue na mesa do respectivo cliente. Se o hamburguer feito pelo jogador é igual ao solicitado, o cliente sai da fila de espera e o próximo freguês é atendido. 

6. Como os clientes são gerados continuamente, o processo descrito acima é repetido até que o jogador perca o jogo, e então é mostrado a ele qual foi o número total de mesas antendidas corretamente.


## Relação dos conceitos com a matéria

Como dito acima, três tipos diferentes de estrutura de dados foram usados, cada uma desempenhando um papel específico no fluxo de funcionamento do programa. Abaixo é descrito detalhadamente o motivo da utilização de cada uma.

### Pilha 

Montagem do hamburguer

Como pilhas são caracterizadas por uma estrutura de dados em que o último dado inserido é o topo, decidimos utilizá-las como responsáveis na montagem dos hamburguers, pois os ingredientes são empilhados de maneira coerente, sempre um pão na base, ingredientes no meio, e outro pão no topo. Dessa maneira não há como modificar o pedido em suas partes intermediarias, e sempre que um pão for o topo da pilha, ou a montagem do pedido foi iniciada ou o pedido foi finalizado.

### Fila

Ordem dos clientes

Filas são essenciais, pois como os pedidos devem ser feitos e entregues para o primeiro cliente que pediu (início da fila), há um gerenciamento de como está o andamento do restaurante, pois podemos saber o tamanho da fila e qual cliente da vez. Ao escolher sua mesa e realizar o pedido, o cliente fica na fila aguardando, já que muito provavelmente outros clientes já haviam chegando antes dele, e possuem prioridade de entrega por estarem em posições mais avançadas na espera. Na medida em que os hamburguers são entregues, o próximo da fila deve ser o próximo cliente atendido, e assim até não haver mais clientes aguardando nas mesas, ou seja, nenhum cliente está na fila.

### Recursão




## Fluxograma



## Descrição do fluxograma
