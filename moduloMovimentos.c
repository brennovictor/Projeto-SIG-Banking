#include <stdio.h>
#include <stdlib.h>
#include "moduloMovimentos.h"
#include <time.h>


typedef struct movimentacao Movimentacao;


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
					}
		} while(opcao != '0');
}

void realizarSaque(void) {
  Movimentacao* movim;
	
  // ler os dados da moviemtação com a função telaRealizarSaque()
  movim = telaRealizarSaque();

  // liberar o espaço de memória da estrutura 
  free(movim);
}



void realizarDeposito(void) {
  Movimentacao* movim;
	
  // ler os dados do cliente com a função telaCadastrarCliente()
  movim = telaRealizarDeposito();

  // liberar o espaço de memória da estrutura 
  free(movim);
}



void consultarSaldo(void) {
  Movimentacao* movim;
	
  // ler os dados do cliente com a função telaCadastrarCliente()
  movim = telaConsultarSaldo();

  // liberar o espaço de memória da estrutura 
  free(movim);
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
	"///            MENU MOVIMENTOS:                                                        ///\n"
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
Movimentacao* telaRealizarSaque(void) {
	Movimentacao *movim;
	movim = (Movimentacao*) malloc(sizeof(Movimentacao));
	movim->tipo = '1';
	
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
	movim->dia = tm.tm_mday;
	movim->mes = tm.tm_mon + 1;
	movim->ano = tm.tm_year + 1900;

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
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", movim->numeroConta);
	getchar();
	printf("\n"
	"               Senha (6 digitos): ");
	scanf("%[0-9]", movim->senha);
	getchar();
	printf("\n"
	"               Valor a ser sacado: ");
	scanf("%f", &movim->valor);
	getchar();
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
	// if conta existe:
	// "///====================================================================================///\n"
	// "///            Valor a ser sacado:                                                     ///\n"
	// "///                                                                                    ///\n"
	// "///            Saque de R$ X,00 Realizado com sucesso                                  ///\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"
	// if valor > saldo: Saldo insuficiente



// função telaRealizarDeposito
// Essa função permite ao usuário realizar um depósito, se a conta informada estiver cadastrada
Movimentacao* telaRealizarDeposito(void) {
	Movimentacao *movim;
	movim = (Movimentacao*) malloc(sizeof(Movimentacao));
	movim->tipo = '2';

	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
	movim->dia = tm.tm_mday;
	movim->mes = tm.tm_mon + 1;
	movim->ano = tm.tm_year + 1900;

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
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", movim->numeroConta);
	getchar();
	printf("\n"
	"               Valor a ser depositado: ");
	scanf("%f", &movim->valor);
	getchar();
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

  // if conta existe:
  // "///====================================================================================///\n"
	// "///            Valor a ser depositado:                                                 ///\n"
	// "///                                                                                    ///\n"
	// "///            Depósito de R$ X,00 Realizado com sucesso                               ///\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"



// função telaConstultarSaldo
// Essa função permite ao usuário consultar o saldo, se a conta informada estiver cadastrada
Movimentacao* telaConsultarSaldo(void) {
	Movimentacao *movim;
	movim = (Movimentacao*) malloc(sizeof(Movimentacao));
	movim->tipo = '3'; 
	
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
	movim->dia = tm.tm_mday;
	movim->mes = tm.tm_mon + 1;
	movim->ano = tm.tm_year + 1900;
	
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
	"///            CONSULTAR SALDO:                                                        ///\n"
	"///                                                                                    ///\n");
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", movim->numeroConta);
	getchar();
	printf("\n"
	"               Senha (6 digitos): ");
	scanf("%[0-9]", movim->senha);
	getchar();
	printf("\n"
	"               SALDO DA CONTA: (em desenvolvimento)");
	printf("\n\n");
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return movim;
}
	// if conta existe:
	// "///====================================================================================///\n"
	// "///                                                                                    ///\n"
	// "///            Saldo atual:                                                            ///\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"



