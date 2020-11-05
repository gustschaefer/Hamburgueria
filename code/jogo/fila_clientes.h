typedef struct cliente
{
	int mesa;
	int pedido;
	struct cliente* proximo;
} Cliente;

typedef struct fila
{
	Cliente* inicio;
	Cliente* fim;
	int tamanho;
} Fila;

Fila* inicializa_Fila();


void novoCliente(int mesa, int pedido, Fila* f); // adiciona um novo cliente na fila a partir da sua mesa e seu pedido


int retiraCliente(Fila* f);


int imprime_Fila(Fila* f);


int generate_recipe(); // gera o pedido do cliente de maneira aleatoria


void generate_client(Fila* f, int mesa); // coloca novos clientes na fila e gera o pedido
