#include <stdio.h>
#include <stdlib.h>

void moduloCliente(void);
char menuCliente(void);
void telaCadastrarCliente(void);
void telaPesquisarCliente(void);
char telaAtualizarCliente(void);
void telaExcluirCliente(void);


// função moduloCliente
// a função chama a função menuCliente e todas as demais funções relacionadas ao módulo cliente,
// de acordo com a opção escolhida pelo usuário
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


// função telaPesquisarCliente
// Essa função permite ao usuário pesquisar um cliente que esteja cadastrado
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


// função telaAtualizarCliente
// Essa função permite ao usuário atualizar um cliente, se este estiver cadastrado
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


// função telaExcluirCliente
// Essa função permite ao usuário excluir um cliente, se este estiver cadastrado
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