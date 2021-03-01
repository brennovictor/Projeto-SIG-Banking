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
#include "moduloCliente.h"
#include "moduloContas.h"
#include "moduloInformacoes.h"
#include "moduloMovimentos.h"


char menuPrincipal(void);


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
			case '4':	moduloInformacoes();
						break;
					}
		} while(opçao != '0');
		system("clear");
		printf("Programa encerrado! Volte sempre ao SIG-Banking!\n\n");
    	return 0;
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
