#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloMovimentos.h"
#include "moduloContas.h"
#include <time.h>
#include "funcoesValidacao.h"


typedef struct movimentacao Movimentacao;
typedef struct conta Conta;


// função moduloMovimentos
// Essa função chama a função menuMovimentos e todas as demais funções relacionadas ao módulo
// movimentos, de acordo com a opção escolhida pelo usuário
void moduloMovimentos(void) {
	char opcao;
	do{                   
		opcao = menuMovimentos();
		switch (opcao){
			case '1':	realizarSaque();
						break;
			case '2':	realizarDeposito();
						break;
			case '3':	consultarSaldo();
						break;
			// case '4':	realizarTransferencia();
					}
		} while(opcao != '0');
}

void realizarSaque(void) {
	Movimentacao* movim;
	Conta* acc;
	char* numConta;
	char senha[7];
	
	numConta = telaPesquisarConta();
	acc = buscarConta(numConta);
	if (acc == NULL) {
		printf("\n\nConta não encontrada!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	} else {
		printf("\n\nConta encontrada!\n\n");
		if (acc->saldo == 0) {
			printf("A conta possui saldo = R$ 0,00\n");
			printf("Não é possível realizar saques...\n\n");
			printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
		} else {
			do {
				printf("\nSenha (6 digitos): ");
				scanf("%[0-9]", senha);
				getchar();
				if (strcmp(senha, acc->senha) != 0) {
					printf("\nA senha está incorreta! Por favor tente novamente...\n");
				}
			} while (strcmp(senha, acc->senha) != 0);
			exibirConta(acc);
			movim = telaRealizarSaque(acc);
			acc->saldo -= movim->valor;
			regravarConta(acc);
			strcpy(movim->numConta, numConta);
			gravarMovimentacao(movim);
			free(movim);
			free(acc);
		}
	} 
	free(numConta);
}



void realizarDeposito(void) {
	Movimentacao* movim;
	Conta* acc;
	char* numConta;
	char senha[7];
	
	numConta = telaPesquisarConta();
	acc = buscarConta(numConta);
	if (acc == NULL) {
		printf("\n\nConta não encontrada!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	} else {
		printf("\n\nConta encontrada!\n\n");
		do {
			printf("\nSenha (6 digitos): ");
			scanf("%[0-9]", senha);
			getchar();
			if (strcmp(senha, acc->senha) != 0) {
				printf("\nA senha está incorreta! Por favor tente novamente...\n");
			}
		} while (strcmp(senha, acc->senha) != 0);
		exibirConta(acc);
		movim = telaRealizarDeposito();
		acc->saldo += movim->valor;
		strcpy(movim->numConta, numConta);
		regravarConta(acc);
		gravarMovimentacao(movim);
		free(movim);
		free(acc);
	} 
	free(numConta);
}



void consultarSaldo(void) {
	// Movimentacao* movim;
	Conta* acc;
	char* numConta;
	char senha[7];
	
	numConta = telaPesquisarConta();
	acc = buscarConta(numConta);
	if (acc == NULL) {
		printf("\n\nConta não encontrada!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	} else {
		printf("\n\nConta encontrada!\n\n");
		do {
			printf("\nSenha (6 digitos): ");
			scanf("%[0-9]", senha);
			getchar();
			if (strcmp(senha, acc->senha) != 0) {
				printf("\nA senha está incorreta! Por favor tente novamente...\n");
			}
		} while (strcmp(senha, acc->senha) != 0);
		// exibirConta(acc);
		printf("\n"
		"Saldo = R$ %.2f\n\n", acc->saldo);
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
		// movim = telaConsultarSaldo();
		// strcpy(movim->numConta, acc->numConta);
		// strcpy(movim->valor, acc->saldo); <<<< IMPLEMENTAR
		// strcpy(movim->valor, "000000");
		// gravarMovimentacao(movim);
		// free(movim);
		free(acc);
	} 
	free(numConta);
}



// função menuMovimentos
// Essa função é chamada pela função moduloMovimentos e retorna a opção escolhida pelo usuário 
// à função chamadora
char menuMovimentos(void) {
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
	"///            MENU MOVIMENTAÇÕES:                                                     ///\n"
	"///                                                                                    ///\n"
	"///            1 - Realizar saque                                                      ///\n"
	"///            2 - Realizar depósitvo                                                  ///\n"
	"///            3 - Consultar saldo                                                     ///\n"
	"///            0 - Voltar ao menu anterior                                             ///\n"
	"///                                                                                    ///\n");
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



// função telaRealizarSaque
// Essa função permite ao usuário realizar um saque, se a conta informada estiver cadastrada
Movimentacao* telaRealizarSaque(Conta* acc) {
	Movimentacao *movim;
	int dataValida;
	int floatValido;
	char valor[20];
	
	movim = (Movimentacao*) malloc(sizeof(Movimentacao));
	movim->tipo = '1';
	
	// time_t mytime;
    // mytime = time(NULL);
    // struct tm tm = *localtime(&mytime);
	// movim->dia = tm.tm_mday;
	// movim->mes = tm.tm_mon + 1;
	// movim->ano = tm.tm_year + 1900;

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
	"///            REALIZAR SAQUE:                                                         ///\n"
	"///                                                                                    ///\n");
	// printf("\n"
	// "               Nº da conta (incluir digito verificador): ");
	// scanf("%[0-9]", numConta);
	// getchar();
	// printf("\n"
	// "               Senha (6 digitos): ");
	// scanf("%[0-9]", movim->senha);
	// getchar();
	do {
		printf("\n"
		"               Valor a ser sacado: ");
		scanf("%[^\n]", valor);
		getchar();
		floatValido = validaFloat(valor);
		if (!floatValido) {
			printf("\n"
			"               Por favor, informe um valor válido!\n");
		} else{
			movim->valor = converteParaFloat(valor);
			if (movim->valor > acc->saldo) {
				printf("\n"
				"               O valor informado é maior que o saldo atual da conta!\n"
				"               Tente novamente...                                   \n");
				floatValido = 0;
			} else {
				floatValido = 1;
			}
		} 
	} while(!floatValido);
	// dataValida = validaData(client->dia, client->mes, client->ano);
	do {
		printf("\n"
		"               Informe a data atual:\n");
		printf("\n"
		"               Informe o dia: ");
		scanf("%[^\n]", movim->dia);
		getchar();
		printf("\n"
		"               Informe o mês: ");
		scanf("%[^\n]", movim->mes);
		getchar();
		printf("\n"
		"               Informe o ano: ");
		scanf("%[^\n]", movim->ano);
		getchar();
		dataValida = validaData(movim->dia, movim->mes, movim->ano);
		if (dataValida == 0) {
			printf("\n"
		"               A data informada é inválida. Por favor, tente novamente...\n");
		}
	} while (!dataValida);
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("\n"
	"              Saque realizado com sucesso!\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return movim;
}



// função telaRealizarDeposito
// Essa função permite ao usuário realizar um depósito, se a conta informada estiver cadastrada
Movimentacao* telaRealizarDeposito(void) {
	int dataValida;
	int floatValido;
	char valor[20];
	Movimentacao *movim;
	movim = (Movimentacao*) malloc(sizeof(Movimentacao));
	movim->tipo = '2';

	// time_t mytime;
    // mytime = time(NULL);
    // struct tm tm = *localtime(&mytime);
	// movim->dia = tm.tm_mday;
	// movim->mes = tm.tm_mon + 1;
	// movim->ano = tm.tm_year + 1900;

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
	"///            REALIZAR DEPÓSITO:                                                      ///\n"
	"///                                                                                    ///\n");
	// printf("\n"
	// "               Nº da conta (incluir digito verificador): ");
	// scanf("%[0-9]", movim->numConta);
	// getchar();
	do {
		printf("\n"
		"               Valor a ser depositado: ");
		scanf("%[^\n]", valor);
		getchar();
		floatValido = validaFloat(valor);
		if (!floatValido) {
			printf("\n"
			"               Por favor, informe um valor válido!\n");
		} else{
			movim->valor = converteParaFloat(valor);
			floatValido = 1;
			if (movim->valor == 0) {
				printf("\n"
				"               Não é possível depositar R$ 00,00 seu merda\n");
				floatValido = 0;
			}
		}
	} while(!floatValido);
	do {
		printf("\n"
		"               Informe a data atual:\n");
		printf("\n"
		"               Informe o dia: ");
		scanf("%[^\n]", movim->dia);
		getchar();
		printf("\n"
		"               Informe o mês: ");
		scanf("%[^\n]", movim->mes);
		getchar();
		printf("\n"
		"               Informe o ano: ");
		scanf("%[^\n]", movim->ano);
		getchar();
		dataValida = validaData(movim->dia, movim->mes, movim->ano);
		if (dataValida == 0) {
			printf("\n"
		"               A data informada é inválida. Por favor, tente novamente...\n");
		}
		} while (dataValida == 0);
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("\n"
	"              Depósitvo realizado com sucesso!\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return movim;
}



// função telaConstultarSaldo
// Essa função permite ao usuário consultar o saldo, se a conta informada estiver cadastrada
// Movimentacao* telaConsultarSaldo(void) {
// 	int dataValida;
// 	Movimentacao *movim;
// 	movim = (Movimentacao*) malloc(sizeof(Movimentacao));
// 	movim->tipo = '3'; 
	
// 	// time_t mytime;
//     // mytime = time(NULL);
//     // struct tm tm = *localtime(&mytime);
// 	// movim->dia = tm.tm_mday;
// 	// movim->mes = tm.tm_mon + 1;
// 	// movim->ano = tm.tm_year + 1900;
	
// 	system("clear");
// 	printf("\n"
// 	"//////////////////////////////////////////////////////////////////////////////////////////\n"
// 	"//////////////////////////////////////////////////////////////////////////////////////////\n"
// 	"///            ===========================================================             ///\n"
// 	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
// 	"///            ===========================================================             ///\n"
// 	"///                                                                                    ///\n"
// 	"//////////////////////////////////////////////////////////////////////////////////////////\n"
// 	"///                                                                                    ///\n"
// 	"///            CONSULTAR SALDO:                                                        ///\n"
// 	"///                                                                                    ///\n");
// 	// printf("\n"
// 	// "               Nº da conta (incluir digito verificador): ");
// 	// scanf("%[0-9]", movim->numConta);
// 	// getchar();
// 	// printf("\n"
// 	// "               Senha (6 digitos): ");
// 	// scanf("%[0-9]", movim->senha);
// 	// getchar();
// 	do {
// 		printf("\n"
// 		"               Informe a data atual:\n");
// 		printf("\n"
// 		"               Informe o dia: ");
// 		scanf("%[^\n]", movim->dia);
// 		getchar();
// 		printf("\n"
// 		"               Informe o mês: ");
// 		scanf("%[^\n]", movim->mes);
// 		getchar();
// 		printf("\n"
// 		"               Informe o ano: ");
// 		scanf("%[^\n]", movim->ano);
// 		getchar();
// 		dataValida = validaData(movim->dia, movim->mes, movim->ano);
// 		if (dataValida == 0) {
// 			printf("\n"
// 		"               A data informada é inválida. Por favor, tente novamente...\n");
// 		}
// 		} while (dataValida == 0);
// 	printf("\n"
// 	"               SALDO DA CONTA: (em desenvolvimento)");
// 	printf("\n\n");
// 	printf("\n"
// 	"///                                                                                    ///\n"
// 	"//////////////////////////////////////////////////////////////////////////////////////////\n"
// 	"\n");
// 	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
// 	getchar();
// 	return movim;
// }

void gravarMovimentacao(Movimentacao* movim) {
	FILE* fp;

	fp = fopen("movimentacoes.dat", "ab");
	if (fp == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Infelzmente, não é possível continuar este programa...\n");
		printf("Programa encerrado!\n");
		exit(1);
	}
	fwrite(movim, sizeof(Movimentacao), 1, fp);
	fclose(fp);
}


