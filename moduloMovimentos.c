#include <stdio.h>
#include <stdlib.h>

void moduloMovimentos(void);
char menuMovimentos(void);
void telaRealizarSaque(void);
void telaRealizarDeposito(void);
void telaConstultarSaldo(void);



// função moduloMovimentos
// Essa função chama a função menuMovimentos e todas as demais funções relacionadas ao módulo
// movimentos, de acordo com a opção escolhida pelo usuário
void moduloMovimentos(void) {
	char opçao;
	do{                   
		opçao = menuMovimentos();
		switch (opçao){
			case '1':	telaRealizarSaque();
						break;
			case '2':	telaRealizarDeposito();
						break;
			case '3':	telaConstultarSaldo();
						break;
					}
		} while(opçao != '0');
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
void telaRealizarSaque(void) {
	char numeroAgencia[6];
	char numeroConta[10];
	char senha[7];

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
	"               Nº da agência (incluir digito verificador): ");
	scanf("%[0-9]", numeroAgencia);
	getchar();
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", numeroConta);
	getchar();
	printf("\n"
	"               Senha (6 digitos): ");
	scanf("%[0-9]", senha);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
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
void telaRealizarDeposito(void) {
	char numeroAgencia[6];
	char numeroConta[10];
	char senha[7];

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
	"               Nº da agência (incluir digito verificador): ");
	scanf("%[0-9]", numeroAgencia);
	getchar();
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", numeroConta);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
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
void telaConstultarSaldo(void) {
	char numeroAgencia[6];
	char numeroConta[10];
	char senha[7];
	
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
	"               Nº da agência (incluir digito verificador): ");
	scanf("%[0-9]", numeroAgencia);
	getchar();
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", numeroConta);
	getchar();
	printf("\n"
	"               Senha (6 digitos): ");
	scanf("%[0-9]", senha);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
	// if conta existe:
	// "///====================================================================================///\n"
	// "///                                                                                    ///\n"
	// "///            Saldo atual:                                                            ///\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"