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
void telaCadastrarCliente(void);


// função telaPesquisarCliente
// Essa função permite ao usuário pesquisar um cliente que esteja cadastrado
void telaPesquisarCliente(void);


// função telaAtualizarCliente
// Essa função permite ao usuário atualizar um cliente, se este estiver cadastrado
char telaAtualizarCliente(void);


// função telaExcluirCliente
// Essa função permite ao usuário excluir um cliente, se este estiver cadastrado
void telaExcluirCliente(void);