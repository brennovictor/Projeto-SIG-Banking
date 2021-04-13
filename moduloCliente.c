#include <stdio.h>
#include <stdlib.h>
#include "funcoesValidacao.h"
#include "moduloCliente.h"


typedef struct cliente Cliente;


// função moduloCliente
// a função chama a função menuCliente e todas as demais funções relacionadas ao módulo cliente,
// de acordo com a opção escolhida pelo usuário
void moduloCliente(void) {
	char opcao;
	do{                   
		opcao = menuCliente();
		switch (opcao){
			case '1':	cadastrarCliente();
						break;
			case '2':	telaPesquisarCliente();
						break;
			case '3':	telaAtualizarCliente();
						break;
			case '4':	telaExcluirCliente();
						break;
					}
		} while(opcao != '0');
}

void cadastrarCliente(void) {
  Cliente* client;
	
  // ler os dados do cliente com a função telaCadastrarCliente()
  client = telaCadastrarCliente();

  // liberar o espaço de memória da estrutura 
  free(client);
}





// função menuCliente
// Essa função é chamada pela função moduloCliente e retorna a opção escolhida pelo usuário 
// à função chamadora
char menuCliente(void) {
	char op;
	system("clear");
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            MENU CLIENTE:                                                           ///\n"
	"///                                                                                    ///\n"
	"///            1 - Cadastrar cliente                                                   ///\n"
	"///            2 - Pesquisar cliente                                                   ///\n"
	"///            3 - Atualizar cliente                                                   ///\n"
	"///            4 - Excluir   cliente                                                   ///\n"
	"///            0 - Voltar ao menu anterior                                             ///\n");
	printf("\n"
	"               Informe a sua opção: ");
	scanf("%c", &op);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	return op;
}


// função telaCadastrarCliente
// Essa função permite ao usuário cadastrar um cliente
Cliente* telaCadastrarCliente(void) {
	Cliente *client;
	int cpfValido;
	int dataValida;
	client = (Cliente*) malloc(sizeof(Cliente));
	
	system("clear");
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            CADASTRAR CLIENTE:                                                      ///\n"
	"///                                                                                    ///\n");
	printf("\n"
	"               Nome completo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", client->nome);
	getchar();
    printf("\n"
	"               CPF (apenas números): ");
	scanf("%[^\n]", client->cpf);
	getchar();
	cpfValido = validaCPF(client->cpf);
	while (cpfValido == 0) {
		printf("\n"
		"               O cpf informado é inválido. Por favor, tente novamente...\n");
		printf("\n"
		"               CPF (apenas números): ");
		scanf("%[^\n]", client->cpf);
		getchar();
		cpfValido = validaCPF(client->cpf);
	}
	printf("\n"
	"               cpf cadastrado com sucesso!\n");
	printf("\n"
	"               Data de nascimento:\n");
	printf("\n"
	"               Informe o dia: ");
	scanf("%[^\n]", client->dia);
	getchar();
	printf("\n"
	"               Informe o mês: ");
	scanf("%[^\n]", client->mes);
	getchar();
	printf("\n"
	"               Informe o ano: ");
	scanf("%[^\n]", client->ano);
	getchar();
	dataValida = validaData(client->dia, client->mes, client->ano);
	while (dataValida == 0) {
		printf("\n"
		"               A data informada é inválida. Por favor, tente novamente...\n");
		printf("\n"
		"               Data de nascimento:\n");
		printf("\n"
		"               Informe o dia: ");
		scanf("%[^\n]", client->dia);
		getchar();
		printf("\n"
		"               Informe o mês: ");
		scanf("%[^\n]", client->mes);
		getchar();
		printf("\n"
		"               Informe o ano: ");
		scanf("%[^\n]", client->ano);
		getchar();
		dataValida = validaData(client->dia, client->mes, client->ano);		
	}
	printf("\n"
	"               Data cadastrada com sucesso!\n");
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("\n"
	"               Cliente cadastrado com sucesso!\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return client;
}


// função telaPesquisarCliente
// Essa função permite ao usuário pesquisar um cliente que esteja cadastrado
void telaPesquisarCliente(void) {
	char cpf[12];
	int cpfValido;
	system("clear");
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            PESQUISAR CLIENTE:                                                      ///\n"
	"///                                                                                    ///\n"
	"///                                                                                    ///\n");
	printf("\n"
	"               CPF (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();
	cpfValido = validaCPF(cpf);
	while (cpfValido == 0) {
		printf("\n"
		"               O cpf informado é inválido. Por favor, tente novamente...\n");
		printf("\n"
		"               CPF (apenas números): ");
		scanf("%[0-9]", cpf);
		getchar();
		cpfValido = validaCPF(cpf);
	}                                                         
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
	// "///====================================================================================///\n"
	// "///            INFORMAÇÕES DO CLIENTE:  (caso esteja cadastrado)                       ///\n"
	// "///                                                                                    ///\n"
	// "///            Nome:                                                                   ///\n"
	// "///            CPF:                                                                    ///\n"
	// "///            Data de nascimento:                                                     ///\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"


// função telaAtualizarCliente
// Essa função permite ao usuário atualizar um cliente, se este estiver cadastrado
void telaAtualizarCliente(void) {
	char cpf[12];
	int cpfValido;
	char op;
	system("clear");
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            ATUALIZAR CLIENTE:                                                      ///\n"
	"///                                                                                    ///\n"
	"///                                                                                    ///\n");
	printf("\n"
	"               CPF (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();
	cpfValido = validaCPF(cpf);
	while (cpfValido == 0) {
		printf("\n"
		"               O cpf informado é inválido. Por favor, tente novamente...\n");
		printf("\n"
		"               CPF (apenas números): ");
		scanf("%[0-9]", cpf);
		getchar();
		cpfValido = validaCPF(cpf);
	}
	printf("\n"
	"///====================================================================================///\n"
	"///            INFORMAÇÕES DO CLIENTE:  (caso esteja cadastrado)                       ///\n"
	"///                                                                                    ///\n"
	"///            Nome:                                                                   ///\n"
	"///            CPF:                                                                    ///\n"
	"///            Data de nascimento:                                                     ///\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            1 - Atualizar nome                                                      ///\n"
	"///            2 - Atualizar cpf                                                       ///\n"
	"///            3 - Atualizar data de nascimento                                        ///\n"
	"///            0 - Voltar ao menu anterior                                             ///\n");
	printf("\n"
	"               Informe a sua opção: ");
	scanf("%c", &op);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf(";Em densevolvimento....\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}


// função telaExcluirCliente
// Essa função permite ao usuário excluir um cliente, se este estiver cadastrado
void telaExcluirCliente(void) {
	char cpf[12];
	int cpfValido;
	system("clear");
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            EXCLUIR CLIENTE:                                                        ///\n"
	"///                                                                                    ///\n");
	printf("\n"
	"               CPF (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();
	cpfValido = validaCPF(cpf);
	while (cpfValido == 0) {
		printf("\n"
		"               O cpf informado é inválido. Por favor, tente novamente...\n");
		printf("\n"
		"               CPF (apenas números): ");
		scanf("%[0-9]", cpf);
		getchar();
		cpfValido = validaCPF(cpf);
	}                                                                                  
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
	// "///====================================================================================///\n"
	// "///            INFORMAÇÕES DO CLIENTE:  (caso esteja cadastrado)                       ///\n"
	// "///                                                                                    ///\n"
	// "///            Nome:                                                                   ///\n"
	// "///            CPF:                                                                    ///\n"
	// "///            Data de nascimento:                                                     ///\n"
	// "///                                                                                    ///\n"
	// "///            Confirmar exclusão? (S/N): S                                            ///\n"
	// "///                                                                                    ///\n"
	// "///            Cliente excluído com sucesso                                            ///\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"
	///ELSE CONTINUE