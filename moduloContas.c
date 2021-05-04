#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloContas.h"
#include "moduloCliente.h"
#include "funcoesValidacao.h"


typedef struct conta Conta;
typedef struct cliente Cliente;


// função moduloContas
// Essa função chama a função menuContas e todas as demais funções relacionadas ao módulo contas,
// de acordo com a opção escolhida pelo usuário
void moduloContas(void) {
	char opcao;
	do{                   
		opcao = menuContas();
		switch (opcao){
			case '1':	cadastrarConta();
						break;
			case '2':	pesquisarConta();
						break;
			case '3': 	atualizarConta();
						break;
			case '4':	excluirConta();
						break;
					}
		} while(opcao != '0');
}


void cadastrarConta(void) {
	Conta* acc;
		
	acc = telaCadastrarConta();
  	gravarConta(acc);
	free(acc);
}


void pesquisarConta (void) {
	Conta* acc;
	char* numConta;

	numConta = telaPesquisarConta();
	acc = buscarConta(numConta);
	if (acc == NULL) {
		printf("\n\nConta não encontrada!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	} else {
		exibirConta(acc);
		free(acc);
	} 
	free(numConta);
}


void atualizarConta(void) {
	Conta* acc;
	char* numConta;

	// numConta = telaAtualizarConta();
	printf("\n"
	"///            ATUALIZAR CONTA:                                                      ///\n");
	numConta = telaPesquisarConta();
	acc = buscarConta(numConta);
	if (acc == NULL) {
		printf("\n\nConta não encontrada!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	} else {
		// acc = telaCadastrarConta();
		acc = telaAtualizarConta(acc);
		// strcpy(acc->numConta, numConta);
		regravarConta(acc);
		free(acc);
	}
	free(numConta);
}


void excluirConta(void) {
	Conta* acc;
	char* numConta;

	numConta = telaExcluirConta();
	acc = (Conta*) malloc(sizeof(Conta));
	acc = buscarConta(numConta);
	if (acc == NULL) {
    	printf("\n\nConta não encontrada!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
  	} else {
			acc->status = False;
			regravarConta(acc);
			free(acc);
			printf("\nConta excluída com sucesso!\n");
			printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
			getchar();
	}
	free(numConta);
}


// função menuContas
// Essa função é chamada pela função moduloContas e retorna a opção escolhida pelo usuário 
// à função chamadora
char menuContas(void) {
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
	"///            MENU CONTAS:                                                            ///\n"
	"///                                                                                    ///\n"
	"///            1 - Cadastrar conta                                                     ///\n"
	"///            2 - Pesquisar conta                                                     ///\n"
	"///            3 - Atualizar conta                                                     ///\n"
	"///            4 - Excluir   conta                                                     ///\n"
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



// função telaCadastrarConta
// Essa função permite ao usuário cadastrar uma conta
Conta* telaCadastrarConta(void) {
	Conta* acc;
	Conta* aux;
	int cpfValido;
	int accValida;
	int opValida;
	char op;
	acc = (Conta*) malloc(sizeof(Conta));

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
	"///            CADASTRAR CONTA:                                                        ///\n"
	"///                                                                                    ///\n");
	printf("\n"
	"               Nº da agência: ");
	scanf("%[0-9]", acc->numAgencia);
	getchar();
	do {
		printf("\n"
		"               Nº da conta (incluir digito verificador): ");
		scanf("%[0-9]", acc->numConta);
		getchar();
		aux = buscarConta(acc->numConta);
		if (aux != NULL) {
			printf("\n"
			"               O nº da conta informado já está cadastrado! Tente novamente...\n");
			accValida = 0;
		} else {
			accValida = 1;
		}
	} while(!accValida);
	printf("\n"
	"               Nº de operação (tipo da conta): ");
	scanf("%[0-9]", acc->operacao);
	getchar();
	printf("\n");
	printf("\n"
	"               Senha (6 digitos): ");
	scanf("%[0-9]", acc->senha);
	getchar();
	int ok = 0;
	do {
	do {
		system("clear");
		printf("\n"
		"               Já possui cadastro de cliente?");
		printf("\n"
		"               1 - Sim\n"
		"               2 - Não\n");
		printf("\n"
		"               Informe a sua opção: ");
		scanf("%c", &op);
		getchar();
		if (op != '1' && op != '2') {
			system("clear");
			printf("\nPor favor, informe uma opção válida!\n");
			opValida = 0;
		} else{
			opValida = 1;
		}
	} while(!opValida);
	if (op == '2') {
		Cliente* client;
		
		client = telaCadastrarCliente();
		strcpy(acc->cpf,client->cpf);
		gravarCliente(client);
		free(client);
		ok = 1;
	} else if (op == '1') {
		Cliente* client;
		char* cpf;
		int achou;
		do {
			cpf = telaPesquisarCliente();
			client = buscarCliente(cpf);
			if (client == NULL) {
				achou = 0;
				printf("\n\nCliente não encontrado!\n\n");
				printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
				getchar();
				do {
					printf("\n"
					"               Deseja continuar?");
					printf("\n"
					"               1 - Sim\n"
					"               2 - Não\n");
					printf("\n"
					"               Informe a sua opção: ");
					scanf("%c", &op);
					getchar();
					if (op != '1' && op != '2') {
						system("clear");
						printf("\nPor favor, informe uma opção válida!\n");
						opValida = 0;
					} else{
						opValida = 1;
					}
				} while(!opValida);
				if (op == '1'){
					continue;
				} else if(op == '2') {
					break;
				}
			} else {
				ok = 1;
				achou = 1;
				strcpy(acc->cpf,client->cpf);
				free(client);
			} 
			free(cpf);
		} while(!achou);

	}
	} while(!ok);
	acc->status = True;
	acc->saldo = 100.00;
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("\n"
	"               Conta cadastrada com sucesso!\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return acc;
}



// função telaPesquisarConta
// Essa função permite ao usuário pesquisar uma conta que esteja cadastrada
char* telaPesquisarConta(void) {
	char* numConta;
	numConta = (char*) malloc(10*sizeof(char));
	
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
	"///            PESQUISAR CONTA:                                                        ///\n"
	"///                                                                                    ///\n");
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", numConta);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	return numConta;
}



// função telaAtualizarConta
// Essa função permite ao usuário atualizar uma conta, se esta estiver cadastrada
Conta* telaAtualizarConta(Conta* acc) {
	// char* numConta;
	char op;
	int opValida = 0;

	system("clear");
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n");
	do {
		printf("\n"
		"///                                                                                    ///\n"
		"///            ATUALIZAR CONTA:                                                        ///\n"
		"///                                                                                    ///\n"
		"///            1 - Atualizar nº da agência                                             ///\n"
		"///            2 - Atualizar nº de operação                                            ///\n"
		"///            3 - Atualizar senha                                                     ///\n"
		"///            4 - Atualizar todos os campos                                           ///\n"
		"///            0 - Voltar ao menu anterior                                             ///\n");
		printf("\n"
		"               Informe a sua opção: ");
		scanf("%c", &op);
		getchar();
		if (op != '1' && op != '2' && op != '3' && op != '4' && op != '0') {
			system("clear");
			printf("\n"
			"               A opção informada é inválida! Por favor tente novamente...\n");
		} else {
			opValida = 1;
		}
	} while (!opValida);
	if (op == '1') {
		printf("\n"
		"               Nº da agência: ");
		scanf("%[0-9]", acc->numAgencia);
		getchar();
		printf("\n"
		"               Conta atualizada com sucesso!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	}
	else if (op == '2') {
		printf("\n"
		"               Nº de operação (tipo da conta): ");
		scanf("%[0-9]", acc->operacao);
		getchar();
		printf("\n"
		"               Conta atualizada com sucesso!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	}
	else if (op == '3') {
		printf("\n"
		"               Senha (6 digitos): ");
		scanf("%[0-9]", acc->senha);
		getchar();
		printf("\n"
		"               Conta atualizada com sucesso!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	}
	else if (op == '4') {
		printf("\n"
		"               Nº da agência: ");
		scanf("%[0-9]", acc->numAgencia);
		getchar();
		printf("\n"
		"               Nº de operação (tipo da conta): ");
		scanf("%[0-9]", acc->operacao);
		getchar();
		printf("\n");
		printf("\n"
		"               Senha (6 digitos): ");
		scanf("%[0-9]", acc->senha);
		getchar();
		printf("\n"
		"               Conta atualizada com sucesso!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	}
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	return acc;
}



// função telaExcluirConta
// Essa função permite ao usuário excluir uma conta, se esta estiver cadastrada
char* telaExcluirConta(void) {
	char* numConta;
	numConta = (char*) malloc(10*sizeof(char));

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
	"///            EXCLUIR CONTA:                                                          ///\n"
	"///                                                                                    ///\n");
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", numConta);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	return numConta;
}



void gravarConta(Conta* acc) {
  FILE* fp;

  fp = fopen("contas.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Infelzmente, não é possível continuar este programa...\n");
	printf("Programa encerrado!\n");
    exit(1);
  }
  fwrite(acc, sizeof(Conta), 1, fp);
  fclose(fp);
}



Conta* buscarConta(char* numConta) {
	FILE* fp;
	Conta* acc;

	acc = (Conta*) malloc(sizeof(Conta));
	fp = fopen("contas.dat", "rb");
	if (fp == NULL) {
		// printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		// printf("Não é possível continuar este programa...\n");
		// printf("Programa encerrado!\n");
		// exit(1);
		return NULL;
	}
	// while(!feof(fp)) {
	while(fread(acc, sizeof(Conta), 1, fp)) {
		if (strcmp(acc->numConta, numConta) == 0 && (acc->status == True)) {
			fclose(fp);
			return acc;
		}
	}
	fclose(fp);
	return NULL;
}



void exibirConta(Conta* acc) {

  if (acc == NULL) {
    printf("\n= = = Conta Inexistente = = =\n");
  } else {
    printf("\n= = = Conta Cadastrada = = =\n");
    printf("Nº da conta: %s\n", acc->numConta);
    printf("Nº da agência: %s\n", acc->numAgencia);
    printf("Operação: %s\n", acc->operacao);
    printf("Senha: %s\n", acc->senha);
    printf("CPF: %s\n", acc->cpf);
	printf("Status: %d\n", acc->status);
	printf("Saldo: R$ %.2f\n", acc->saldo);
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
}



void regravarConta(Conta* acc) {
	int achou;
	FILE* fp;
	Conta* accLida;

	accLida = (Conta*) malloc(sizeof(Conta));
	fp = fopen("contas.dat", "r+b");
	if (fp == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar este programa...\n");
		printf("Programa encerrado!\n");
		exit(1);
	}
	// while(!feof(fp)) {
	achou = False;
	while(fread(accLida, sizeof(Conta), 1, fp) && !achou) {
		// fread(clientLido, sizeof(Cliente), 1, fp);
		if (strcmp(accLida->numConta, acc->numConta) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Conta), SEEK_CUR);
		fwrite(acc, sizeof(Conta), 1, fp);
			// break;
		}
	}
	fclose(fp);
	free(accLida);
}