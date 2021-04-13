#include <stdio.h>
#include <stdlib.h>
#include "funcoesValidacao.h"

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
			case '1':	relatorioClientes();
						break;
			case '2':	relatorioContas();
						break;
			case '3':	relatorioSaldos();
						break;
			case '4':	relatorioSaques();
						break;
			case '5':	relatorioDepositos();
						break;
			case '6':	relatorioTransferências();
						break;
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
	"///            2 - Relatório de contas                                                 ///\n"
	"///            3 - Relatório de saldos                                                 ///\n"
	"///            4 - Relatório de saques                                                 ///\n"
	"///            5 - Relatório de depositos                                              ///\n"
	"///            6 - Relatório de transferências                                         ///\n"
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



void relatorioClientes (void) {
	system("clear");
	char nomeCliente[15] = "Fulano Di Tal";
	char cpf[15] = "705.163.782.12";
	char nasc[12] = "21/05/1995";
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            CLIENTES CADASTRADOS:                                                   ///\n"
	"///                                                                                    ///\n");
	for (int i = 1; i <= 10; i++) {
		printf("\n"
		"				Nome: %s\n",nomeCliente);
		printf("\n"
		"				CPF: %s\n",cpf);
		printf("\n"
		"				Data de nascimento: %s\n",nasc);
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



void relatorioContas (void) {
	system("clear");
	char numAgencia[6] = "12345";
	char numConta[10] = "123456789";
	char numOperacao[4] = "013";
	char senha[7] = "123456";
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            CONTAS CADASTRADAS:                                                     ///\n"
	"///                                                                                    ///\n");
	for (int i = 1; i <= 10; i++) {
		printf("\n"
		"				Nº agência: %s\n",numAgencia);
		printf("\n"
		"				Nº operação: %s\n",numOperacao);
		printf("\n"
		"				Nº conta: %s\n",numConta);
		printf("\n"
		"				Senha: %s\n",senha);
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
