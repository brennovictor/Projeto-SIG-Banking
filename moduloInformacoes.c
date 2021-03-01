#include <stdio.h>
#include <stdlib.h>

void moduloInformacoes(void);
void telaSobre(void);


// função moduloInformacoes
// Essa função chama a função telaSobre() e todas as funções relacionadas ao módulo moduloInformacoes
// (em desenvolvimento)
void moduloInformacoes(void) {
	telaSobre();
}


// Essa função imprime na tela as informções sobre o projeto
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