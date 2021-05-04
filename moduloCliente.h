typedef struct cliente Cliente;

struct cliente {
	char nome[41];
	char cpf[12];
	char dia[3], mes[3], ano[5]; // data de nascimento
	int status;
	// struct client *prox;
};


// função moduloCliente
// a função chama a função menuCliente e todas as demais funções relacionadas ao módulo cliente,
// de acordo com a opção escolhida pelo usuário
void moduloCliente(void);


// função menuCliente
// Essa função é chamada pela função moduloCliente e retorna a opção escolhida pelo usuário 
// à função chamadora
char menuCliente(void);


// função telaCadastrarCliente
// Essa função permite ao usuário cadastrar um cliente
Cliente* telaCadastrarCliente(void);


// função telaPesquisarCliente
// Essa função permite ao usuário pesquisar um cliente que esteja cadastrado
char* telaPesquisarCliente(void);


// função telaAtualizarCliente
// Essa função permite ao usuário atualizar um cliente, se este estiver cadastrado
Cliente* telaAtualizarCliente(Cliente*);


// função telaExcluirCliente
// Essa função permite ao usuário excluir um cliente, se este estiver cadastrado
char* telaExcluirCliente(void);

void cadastrarCliente (void); 

void pesquisarCliente (void);

void atualizarCliente(void);

void excluirCliente(void);

void gravarCliente(Cliente*);

Cliente* buscarCliente(char*);

void exibirCliente(Cliente*);

void regravarCliente(Cliente*);



