typedef struct conta Conta;

struct conta {
	char numeroAgencia[6];
	char numeroConta[10];
	char operacao[4];
	char senha[7];
	char cpf[12];
};


// função moduloContas
// Essa função chama a função menuContas e todas as demais funções relacionadas ao módulo contas,
// de acordo com a opção escolhida pelo usuário
void moduloContas(void);


// função menuContas
// Essa função é chamada pela função moduloContas e retorna a opção escolhida pelo usuário 
// à função chamadora
char menuContas(void);


// função telaCadastrarConta
// Essa função permite ao usuário cadastrar uma conta
Conta* telaCadastrarConta(void);


// função telaPesquisarConta
// Essa função permite ao usuário pesquisar uma conta que esteja cadastrada
void telaPesquisarConta(void);


// função telaAtualizarConta
// Essa função permite ao usuário atualizar uma conta, se esta estiver cadastrada
char telaAtualizarConta(void);


// função telaExcluirConta
// Essa função permite ao usuário excluir uma conta, se esta estiver cadastrada
void telaExcluirConta(void);


void cadastrarConta(void);