typedef struct movimentacao Movimentacao;

struct movimentacao {
	char numConta[10];
	char dia[3], mes[3], ano[5]; // data
	char tipo;
	char valor[15];
};

// função moduloMovimentos
// Essa função chama a função menuMovimentos e todas as demais funções relacionadas ao módulo
// movimentos, de acordo com a opção escolhida pelo usuário
void moduloMovimentos(void);


// função menuMovimentos
// Essa função é chamada pela função moduloMovimentos e retorna a opção escolhida pelo usuário 
// à função chamadora
char menuMovimentos(void);


// função telaRealizarSaque
// Essa função permite ao usuário realizar um saque, se a conta informada estiver cadastrada
Movimentacao* telaRealizarSaque(void);


// função telaRealizarDeposito
// Essa função permite ao usuário realizar um depósito, se a conta informada estiver cadastrada
Movimentacao* telaRealizarDeposito(void);


// função telaConstultarSaldo
// Essa função permite ao usuário consultar o saldo, se a conta informada estiver cadastrada
Movimentacao* telaConsultarSaldo(void);

void realizarSaque(void);

void realizarDeposito(void);

void consultarSaldo(void);

void gravarMovimentacao(Movimentacao*);
