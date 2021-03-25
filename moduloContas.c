#include <stdio.h>
#include <stdlib.h>

void moduloContas(void);
char menuContas(void);
void telaCadastrarConta(void);
void telaPesquisarConta(void);
char telaAtualizarConta(void);
void telaExcluirConta(void);



// função moduloContas
// Essa função chama a função menuContas e todas as demais funções relacionadas ao módulo contas,
// de acordo com a opção escolhida pelo usuário
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
void telaCadastrarConta(void) {
	char numeroAgencia[6];
	char numeroConta[10];
	char operacao[4];
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
	"               Nº da agência: ");
	scanf("%[0-9]", numeroAgencia);
	getchar();
	printf("\n"
	"               Nº da conta (incluir digito verificador): ");
	scanf("%[0-9]", numeroConta);
	printf("\n"
	"               Nº de operação (tipo da conta): ");
	scanf("%[0-9]", operacao);
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



// função telaPesquisarConta
// Essa função permite ao usuário pesquisar uma conta que esteja cadastrada
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



// função telaAtualizarConta
// Essa função permite ao usuário atualizar uma conta, se esta estiver cadastrada
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



// função telaExcluirConta
// Essa função permite ao usuário excluir uma conta, se esta estiver cadastrada
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