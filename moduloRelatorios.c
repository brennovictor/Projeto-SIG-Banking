#include <stdio.h>
#include <stdlib.h>

void moduloRelatorios(void);
char menuRelatorios (void);
void relatorioClientes (void);
void relatorioContas (void);
void relatorioSaldos (void);
void relatorioSaques (void);
void relatorioDepositos (void);
void relatorioTransferências (void);


void moduloRelatorios(void) {
	char opçao;
	do{                   
		opçao = menuRelatorios();
		switch (opçao){
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
		} while(opçao != '0');
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
	"///                                                                                    ///\n"
	"///            INFORMAÇÕES DOS CLIENTES CADASTRADOS EM DETERMINADO PERÍODO:            ///\n"
	"///            Em desenvolvimento...                                                   ///\n");
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
	"///                                                                                    ///\n"
	"///            INFORMAÇÕES DAS CONTAS CADASTRADAS EM DETERMINADO PERÍODO:              ///\n"
	"///            Em desenvolvimento...                                                   ///\n");
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
	"///            INFORMAÇÕES DOS SALDOS DAS CONTAS EM DETERMINADO PERÍODO:               ///\n"
	"///            Em desenvolvimento...                                                   ///\n");
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
	"///            INFORMAÇÕES DOS SAQUES REALIZADOS EM DETERMINADO PERÍODO:               ///\n"
	"///            Em desenvolvimento...                                                   ///\n");
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
	"///            INFORMAÇÕES DOS DEPÓSITOS REALIZADOS EM DETERMINADO PERÍODO:            ///\n"
	"///            Em desenvolvimento...                                                   ///\n");
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
	printf("\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///            ===========================================================             ///\n"
	"///            = = = = = Sistema de Controle de Contas Bancárias = = = = =             ///\n"
	"///            ===========================================================             ///\n" 
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"///                                                                                    ///\n"
	"///            TRANSFERÊNCIAS EFETUADOS:                                               ///\n"
	"///                                                                                    ///\n"
	"///            INFORMAÇÕES DAS TRANSFERÊNCIAS REALIZADAS EM DETERMINADO PERÍODO:       ///\n"
	"///            Em desenvolvimento...                                                   ///\n");
	printf("\n"
	"///                                                                                    ///\n"
	"//////////////////////////////////////////////////////////////////////////////////////////\n"
	"\n");
	printf("Em desenvolvimento...\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}