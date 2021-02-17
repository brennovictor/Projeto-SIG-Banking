///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///                Developed by  @brennovictor - Jan, 2021                  ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

char menuPrincipal(void);
void moduloInformaçoes(void);
void telaSobre(void);

void moduloCliente(void);
char menuCliente(void);
void telaCadastrarCliente(void);
void telaPesquisarCliente(void);
char telaAtualizarCliente(void);
void telaExcluirCliente(void);

void moduloContas(void);
char menuContas(void);
void telaCadastrarConta(void);
void telaPesquisarConta(void);
char telaAtualizarConta(void);
void telaExcluirConta(void);

void moduloMovimentos(void);
char menuMovimentos(void);
void telaRealizarSaque(void);
void telaRealizarDeposito(void);
void telaConstultarSaldo(void);

int main(void) {
	char opçao;
	do{                   
		opçao = menuPrincipal();
		switch (opçao){
			case '1':	moduloCliente();
						break;
			case '2':	moduloContas();
						break;
			case '3':	moduloMovimentos();
						break;
			case '4':	moduloInformaçoes();
						break;
					}
		} while(opçao != '0');
		printf("Programa encerrado! Volte sempre ao SIG-Banking!\n\n");
    	return 0;
}



void moduloInformaçoes(void) {
	telaSobre();
}


void telaSobre(void) {
	char op;
	system("clear");
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///             Universidade Federal do Rio Grande do Norte                            ///\n"
	"///                Centro de Ensino Superior do Seridó                                 ///\n"
	"///               Departamento de Computação e Tecnologia                              ///\n"
	"///                  Disciplina DCT1106 -- Programação                                 ///\n"
	"///                  Projeto Sistema de Gestão Escolar                                 ///\n"
	"///                Developed by  @brennovictor - Jan, 2021                             ///\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///                                                                                    ///\n"
	"///  Programa utilizado como parte da avaliação da disciplina DCT1106 - Programação.   ///\n"
	"///  O presente projeto tem como objetivo desenvolver um programa de computador que    ///\n"
	"///  realize o registro e o acompanhamento de operações financeiras de várias contas   ///\n"
	"///  bancárias, simulando as atividades que possam ocorrem em um banco real.           ///\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}


char menuPrincipal(void) {
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
	"///            MENU PRINCIPAL:                                                         ///\n"
	"///                                                                                    ///\n"
	"///            1 - Módulo cliente                                                      ///\n"
	"///            2 - Módulo Contas                                                       ///\n"
	"///            3 - Módulo movimento (Depósitos e Saques)                               ///\n"
	"///            4 - Sobre o sistema                                                     ///\n"
	"///            0 - Encerrar o programa                                                 ///\n");
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

void moduloCliente(void) {
	char opçao;
	do{                   
		opçao = menuCliente();
		switch (opçao){
			case '1':	telaCadastrarCliente();
						break;
			case '2':	telaPesquisarCliente();
						break;
			case '3':	telaAtualizarCliente();
						break;
			case '4':	telaExcluirCliente();
						break;
					}
		} while(opçao != '0');
}


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

void telaCadastrarCliente(void) {
	char nome[51];
	char cpf[12];
	char nasc[11];
	
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
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
	getchar();
    printf("\n"
	"               CPF (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();
	printf("\n"
	"               Data de Nascimento (dd/mm/aaaa):  ");
	scanf("%[0-9/]", nasc);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}


void telaPesquisarCliente(void) {
	char cpf[12];
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



char telaAtualizarCliente(void) {
	char op;
	char cpf[12];
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
	printf("Em densevolvimento....\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return op;
}


void telaExcluirCliente(void) {
	char cpf[12];
	char confirma;
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

void moduloContas(void) {
	char opçao;
	do{                   
		opçao = menuContas();
		switch (opçao){
			case '1':	telaCadastrarConta();
						break;
			case '2':	telaPesquisarConta();
						break;
			case '3':	telaAtualizarConta();
						break;
			case '4':	telaExcluirConta();
						break;
					}
		} while(opçao != '0');
}


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


void telaCadastrarConta(void) {
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
	"///            CADASTRAR CONTA:                                                        ///\n"
	"///                                                                                    ///\n");
	printf("\n"
	"               Nº da agência (incluir digito verificador): ");
	scanf("%[0-9]", numeroAgencia);
	getchar();
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", numeroConta);
	getchar();
	printf("\n");
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



void telaPesquisarConta(void) {
	char numeroConta[10];
	
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
	scanf("%[0-9]", numeroConta);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
	// "///====================================================================================///\n"
	// "///            INFORMAÇÕES DA CONTA:  (caso esteja cadastrada)                         ///\n"
	// "///                                                                                    ///\n"
	// "///            Nº da agência:                                                          ///\n"
	// "///            Nº da conta:                                                            ///\n"
	// "///            Senha:                                                                  ///\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"



char telaAtualizarConta(void) {
	char op;
	char numeroConta[10];
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
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", numeroConta);
	getchar();
	printf("\n"
	"///====================================================================================///\n"
	"///            INFORMAÇÕES DA CONTA:  (caso esteja cadastrada)                         ///\n"
	"///                                                                                    ///\n"
	"///            Nº da agência:                                                          ///\n"
	"///            Nº da conta:                                                            ///\n"
	"///            Senha:                                                                  ///\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            ATUALIZAR CONTA:                                                        ///\n"
	"///                                                                                    ///\n"
	"///            1 - Atualizar nº da agência                                             ///\n"
	"///            2 - Atualizar nº da conta                                               ///\n"
	"///            3 - Atualizar senha                                                     ///\n"
	"///            0 - Encerrar o programa                                                 ///\n");
	printf("\n"
	"               Informe a sua opção: ");
	scanf("%c", &op);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return op;
}

void telaExcluirConta(void) {
	char numeroConta[10];
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
	scanf("%[0-9]", numeroConta);
	getchar();
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
	// "///====================================================================================///\n"
	// "///            INFORMAÇÕES DA CONTA:  (caso esteja cadastrada)                         ///\n"
	// "///                                                                                    ///\n"
	// "///            CPF:                                                                    ///\n"
	// "///            Nº da conta:                                                            ///\n"
	// "///            Nº da agência:                                                          ///\n"
	// "///            Nome do cliente:                                                        ///\n"
	// "///                                                                                    ///\n"
	// "///            Confirmar exclusão? (S/N): S                                            ///\n"
	// "///                                                                                    ///\n"
	// "///            Conta excluída com sucesso                                              ///\n"
	// "///                                                                                    ///\n"
	// "//////////////////////////////////////////////////////////////////////////////////////////\n"
	///ELSE CONTINUE


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




