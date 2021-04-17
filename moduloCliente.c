#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			case '2':	pesquisarCliente();
						break;
			case '3':	atualizarCliente();
						break;
			case '4':	excluirCliente();
						break;
					}
		} while(opcao != '0');
}


void cadastrarCliente(void) {
	Cliente* client;
		
	client = telaCadastrarCliente();
  	gravarCliente(client);
	free(client);
}


void pesquisarCliente (void) {
	Cliente* client;
	char* cpf;

	cpf = telaPesquisarCliente();
	client = buscarCliente(cpf);
	if (client == NULL) {
		printf("\n\nCliente não encontrado!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	} else {
		exibirCliente(client);
		free(client);
	} 
	free(cpf);
}


void atualizarCliente(void) {
	Cliente* client;
	char* cpf;

	cpf = telaAtualizarCliente();
	client = buscarCliente(cpf);
	if (client == NULL) {
		printf("\n\nCliente não encontrado!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	} else {
		client = telaCadastrarCliente();
		strcpy(client->cpf, cpf);
		regravarCliente(client);
		free(client);
	}
	free(cpf);
}


void excluirCliente(void) {
	Cliente* client;
	char* cpf;

	cpf = telaExcluirCliente();
	client = (Cliente*) malloc(sizeof(Cliente));
	client = buscarCliente(cpf);
	if (client == NULL) {
    	printf("\n\nCliente não encontrado!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
  	} else {
			client->status = False;
			regravarCliente(client);
			free(client);
			printf("\nCliente excluído com sucesso!\n");
			printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
			getchar();
	}
	free(cpf);
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
	// int cpfValido;
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
	// cpfValido = validaCPF(client->cpf);
	// while (cpfValido == 0) {
	// 	printf("\n"
	// 	"               O cpf informado é inválido. Por favor, tente novamente...\n");
	// 	printf("\n"
	// 	"               CPF (apenas números): ");
	// 	scanf("%[^\n]", client->cpf);
	// 	getchar();
	// 	cpfValido = validaCPF(client->cpf);
	// }
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
	client->status = True;
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
char* telaPesquisarCliente(void) {
	// int cpfValido;
	char* cpf;
	cpf = (char*) malloc(12*sizeof(char));

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
	// cpfValido = validaCPF(cpf);
	// while (cpfValido == 0) {
	// 	printf("\n"
	// 	"               O cpf informado é inválido. Por favor, tente novamente...\n");
	// 	printf("\n"
	// 	"               CPF (apenas números): ");
	// 	scanf("%[0-9]", cpf);
	// 	getchar();
	// 	cpfValido = validaCPF(cpf);
	// }                                                         
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	// printf("Em desenvolvimento...\n\n");
	// printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	// getchar();
	return cpf;
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
char* telaAtualizarCliente(void) {
	char* cpf;
	cpf = (char*) malloc(12*sizeof(char));
	// int cpfValido;
	// char op;
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
	// cpfValido = validaCPF(cpf);
	// while (cpfValido == 0) {
	// 	printf("\n"
	// 	"               O cpf informado é inválido. Por favor, tente novamente...\n");
	// 	printf("\n"
	// 	"               CPF (apenas números): ");
	// 	scanf("%[0-9]", cpf);
	// 	getchar();
	// 	cpfValido = validaCPF(cpf);
	// }
	// printf("\n"
	// "///====================================================================================///\n"
	// "///            INFORMAÇÕES DO CLIENTE:  (caso esteja cadastrado)                       ///\n"
	// "///                                                                                    ///\n"
	// "///            Nome:                                                                   ///\n"
	// "///            CPF:                                                                    ///\n"
	// "///            Data de nascimento:                                                     ///\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"
	// "///                                                                                    ///\n"
	// "///            1 - Atualizar nome                                                      ///\n"
	// "///            2 - Atualizar cpf                                                       ///\n"
	// "///            3 - Atualizar data de nascimento                                        ///\n"
	// "///            0 - Voltar ao menu anterior                                             ///\n");
	// printf("\n"
	// "               Informe a sua opção: ");
	// scanf("%c", &op);
	// getchar();
	// printf("\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"
	// "\n");
	// printf(";Em densevolvimento....\n\n");
	// printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	// getchar();
	return cpf;
}


// função telaExcluirCliente
// Essa função permite ao usuário excluir um cliente, se este estiver cadastrado
char* telaExcluirCliente(void) {
	char* cpf;
	// int cpfValido;
	cpf = (char*) malloc(12*sizeof(char));

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
	// cpfValido = validaCPF(cpf);
	// while (cpfValido == 0) {
	// 	printf("\n"
	// 	"               O cpf informado é inválido. Por favor, tente novamente...\n");
	// 	printf("\n"
	// 	"               CPF (apenas números): ");
	// 	scanf("%[0-9]", cpf);
	// 	getchar();
	// 	cpfValido = validaCPF(cpf);
	// }                                                                                  
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	return cpf;
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



void gravarCliente(Cliente* client) {
  FILE* fp;

  fp = fopen("clientes.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Infelzmente, não é possível continuar este programa...\n");
	printf("Programa encerrado!\n");
    exit(1);
  }
  fwrite(client, sizeof(Cliente), 1, fp);
  fclose(fp);
}



Cliente* buscarCliente(char* cpf) {
	FILE* fp;
	Cliente* client;

	client = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "rb");
	if (fp == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar este programa...\n");
		printf("Programa encerrado!\n");
		exit(1);
	}
	// while(!feof(fp)) {
	while(fread(client, sizeof(Cliente), 1, fp)) {
		if (strcmp(client->cpf, cpf) == 0 && (client->status == True)) {
			fclose(fp);
			return client;
		}
	}
	fclose(fp);
	return NULL;
}



void exibirCliente(Cliente* client) {

  if (client == NULL) {
    printf("\n= = = Cliente Inexistente = = =\n");
  } else {
    printf("\n= = = Cliente Cadastrado = = =\n");
    printf("Nome: %s\n", client->nome);
    printf("CPF: %s\n", client->cpf);
    printf("Data de nascimento: %s/", client->dia);
    printf("%s/", client->mes);
    printf("%s\n", client->ano);
	printf("Status: %d\n", client->status);
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
}



void regravarCliente(Cliente* client) {
	int achou;
	FILE* fp;
	Cliente* clientLido;

	clientLido = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "r+b");
	if (fp == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar este programa...\n");
		printf("Programa encerrado!\n");
		exit(1);
	}
	// while(!feof(fp)) {
	achou = False;
	while(fread(clientLido, sizeof(Cliente), 1, fp) && !achou) {
		// fread(clientLido, sizeof(Cliente), 1, fp);
		if (strcmp(clientLido->cpf, client->cpf) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
		fwrite(client, sizeof(Cliente), 1, fp);
			// break;
		}
	}
	fclose(fp);
	free(clientLido);
}