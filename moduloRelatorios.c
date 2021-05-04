#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloRelatorios.h"
#include "funcoesValidacao.h"
#include "moduloCliente.h"
#include "moduloContas.h"

void moduloRelatorios(void);
char menuRelatorios (void);
void relatorioClientes (void);
void relatorioContas (void);
void relatorioSaldos (void);
void relatorioSaques (void);
void relatorioDepositos (void);
void relatorioTransferências (void);


void moduloRelatorios(void) {
	char opcao;
	do{                   
		opcao = menuRelatorios();
		switch (opcao){
			case '1':	relatClientesCadastrados();
						break;
			case '2':	relatContasCadastradas();
						break;
			case '3':	contasPorCliente();
						break;
			// case '4':	relatorioSaques();
			// 			break;
			// case '5':	relatorioDepositos();
			// 			break;
			// case '6':	relatorioTransferências();
			// 			break;
					}
		} while(opcao != '0');
}


char menuRelatorios(void) {
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
	"///            MENU RELATÓRIOS:                                                        ///\n"
	"///                                                                                    ///\n"
	"///            1 - Relatório de clientes cadastrados                                   ///\n"
	"///            2 - Relatório de contas cadastradas                                     ///\n"
	"///            3 - Relatório de contas por cliente                                     ///\n"
	// "///            4 - Relatório de saques                                                 ///\n"
	// "///            5 - Relatório de depositos                                              ///\n"
	// "///            6 - Relatório de transferências                                         ///\n"
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



void contasPorCliente(void) {
    char* cpf;
	Cliente* client;

	cpf = telaContasPorCliente();
	client = buscarCliente(cpf);
	if (client == NULL) {
		printf("\n\nCliente não encontrado!\n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	} else {
		relatContasPorCliente(client);
	}
	free(client);
	free(cpf);
}
 

char* telaContasPorCliente(void) {
	char* cpf;
	int cpfValido;

    cpf = (char*) malloc(12*sizeof(char));

    system("clear");
	printf("\n"
	"////////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = =   CONTAS POR CLIENTE   = = = = = =              ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o cpf do cliente: ");
	do {
		printf("\n"
		"              CPF (apenas números): ");
		scanf("%[^\n]", cpf);
		getchar();
		cpfValido = validaCPF(cpf);
		if (!cpfValido) {
			printf("\n"
			"              O cpf informado é inválido! Por favor, tente novamente...\n");
		}
	} while (!cpfValido);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    return cpf;
}


void relatContasPorCliente(Cliente* client) {
    int ok;
	system("clear");
	printf("\n"
	"////////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = =      CLIENTES     = = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
    printf("///       ==============================================================  ///\n");
	printf("///       ||         Nome                            ||       CPF     ||  ///\n");
    printf("///       ==============================================================  ///\n");
    ok = listaContasPorCliente(client);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

int listaContasPorCliente(Cliente* client) {
	FILE* fp;
    Conta* acc;
	int achou;
	int imprime;
    char nomeTrunc1[41];
	char nomeTrunc2[14];
    int tam1, tam2;

    acc = (Conta*) malloc(sizeof(Conta));
    fp = fopen("contas.dat", "rb");
	if (fp == NULL) {
		printf("\n\nEste cliente não possui contas cadastradas\n\n");
		free(acc);
		return 0;
	} else {
		while (fread(acc, sizeof(Conta), 1, fp)) {
				if (acc->status == True) {
					if (strcmp(acc->cpf,client->cpf) == 0) {
						achou = 1;
						tam1 = strlen(client->nome);
						tam2 = strlen(acc->numConta);
						strncpy(nomeTrunc1, client->nome, tam1);
						strncpy(nomeTrunc2, acc->numConta, tam2);
						for (int i = tam1; i < 40; i++) {
							nomeTrunc1[i] = ' ';
						}
						nomeTrunc1[40] = '\0';

						for (int i = tam2; i < 13; i++) {
							nomeTrunc2[i] = ' ';
						}
						nomeTrunc2[13] = '\0';
						printf("///       ||%-41s|| %-14s||  ///\n", nomeTrunc1, nomeTrunc2);
					}
				}
			}
		}
    fclose(fp);
    free(acc);
	if (achou == 0) {
		printf("\nO cliente não possui contas cadastradas\n");
	}
	return 0;
}


void relatClientesCadastrados(void) {
    int ok;
	system("clear");
	printf("\n"
	"////////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = =   CONTAS POR CLIENTES   = = = = = = =   ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
    printf("///       ==============================================================  ///\n");
	printf("///       ||         Nome                            |   Nº da conta  ||  ///\n");
    printf("///       ==============================================================  ///\n");
    ok = listaClientesCadastrados();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}


int listaClientesCadastrados(void) {
    FILE* fp;
    Cliente* client;
    char nomeTrunc1[41];
	char nomeTrunc2[14];
    int tam1, tam2;

    client = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
	if (fp == NULL) {
		printf("\n\nNão há clientes cadastrados\n\n");
		free(client);
		return 0;
	} else {
		while (fread(client, sizeof(Cliente), 1, fp)) {
				if (client->status == True) {
					tam1 = strlen(client->nome);
					tam2 = strlen(client->cpf);
					strncpy(nomeTrunc1, client->nome, tam1);
					strncpy(nomeTrunc2, client->cpf, tam2);
					for (int i = tam1; i < 40; i++) {
						nomeTrunc1[i] = ' ';
					}
					nomeTrunc1[40] = '\0';

					for (int i = tam2; i < 13; i++) {
						nomeTrunc2[i] = ' ';
					}
					nomeTrunc2[13] = '\0';
					printf("///       ||%-41s|| %-14s||  ///\n\n\n", nomeTrunc1, nomeTrunc2);
				}
			}
		}
    fclose(fp);
    free(client);
	return 0;
}




void relatContasCadastradas(void) {
    int ok;
	system("clear");
	printf("\n"
	"////////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = =      CONTAS     = = = = = = = =               ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
    printf("///       ==============================================================  ///\n");
	printf("///       ||         Nº da conta       ||       saldo                 ||  ///\n");
    printf("///       ==============================================================  ///\n");
    ok = listaContasCadastradas();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}


int listaContasCadastradas(void) {
    FILE* fp;
    Conta* acc;
    char nomeTrunc[26];
    int tam;

    acc = (Conta*) malloc(sizeof(Conta));
    fp = fopen("contas.dat", "rb");
	if (fp == NULL) {
		printf("\n\nNão há contas cadastradas\n\n");
		free(acc);
		return 0;
	} else {
		while (fread(acc, sizeof(Conta), 1, fp)) {
				if (acc->status == True) {
					tam = strlen(acc->numConta);
					strncpy(nomeTrunc, acc->numConta, tam);
					for (int i = tam; i < 25; i++) {
						nomeTrunc[i] = ' ';
					}
					nomeTrunc[25] = '\0';

					printf("///       || %-26s|| R$ %.2f                   ||  ///\n", nomeTrunc, acc->saldo);
				}
			}
		}
    fclose(fp);
    free(acc);
	return 0;
}

void relatorioSaldos (void) {
	system("clear");
	char numConta[10] = "123456789";
	char saldo[8] = "1200.00";
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            SALDOS:                                                                 ///\n"
	"///                                                                                    ///\n"
	"///            INFORMAÇÕES DOS SALDOS DAS CONTAS:               						///\n");
	for (int i = 1; i <= 10; i++) {
		printf("\n"
		"				Nº conta: %s\n",numConta);
		printf("\n"
		"				Saldo: R$ %s\n",saldo);
		printf("\n\n");
	}
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}



void relatorioSaques (void) {
	system("clear");
	char numConta[10] = "123456789";
	char saque[7] = "500.00";
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            SAQUES EFETUADOS:                                                       ///\n"
	"///                                                                                    ///\n"
	"///            INFORMAÇÕES DOS SAQUES REALIZADOS:               						///\n"
	"///                                                              						///\n");
	for (int i = 1; i <= 10; i++) {
		printf("\n"
		"				Nº conta: %s\n",numConta);
		printf("\n"
		"				Saque realizado: R$ %s\n",saque);
		printf("\n\n");
	}
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}



void relatorioDepositos (void) {
	system("clear");
	char numConta[10] = "123456789";
	char deposito[7] = "2300.00";
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            DEPÓSITOS EFETUADOS:                                                    ///\n"
	"///                                                                                    ///\n"
	"///            INFORMAÇÕES DOS DEPÓSITOS REALIZADOS:            						///\n");
	for (int i = 1; i <= 10; i++) {
		printf("\n"
		"				Nº conta: %s\n",numConta);
		printf("\n"
		"				Depósito realizado: R$ %s\n",deposito);
		printf("\n\n");
	}
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}



void relatorioTransferências (void) {
	system("clear");
	char numConta1[10] = "123456789";
	char numconta2[10] = "98754321";
	char valorTransf[7] = "300.00";
	char tipoTransf[4] = "DOC";
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            TRANSFERÊNCIAS EFETUADAS:                                               ///\n"
	"///                                                                                    ///\n"
	"///            INFORMAÇÕES DAS TRANSFERÊNCIAS REALIZADAS:       						///\n");
	for (int i = 1; i <= 10; i++) {
		printf("\n"
		"				Valor transferido de Nº conta: %s\n",numConta1);
		printf("\n"
		"				Para Nº conta: %s\n",numConta1);
		printf("\n"
		"				Valor transferido: R$ %s\n",valorTransf);
		printf("\n"
		"				Tipo de transferência: %s\n",tipoTransf);
		printf("\n\n");
	}
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
