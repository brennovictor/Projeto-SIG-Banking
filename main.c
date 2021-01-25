///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///                Developed by  @flgorgonio - Jan, 2021                    ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

void TelaInicial(void);
;

int main(void) {
    TelaInicial();
		return 0;

}


void TelaInicial(void) {
printf("//////////////////////////////////////////////////////////////////////////////////////////\n"
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
"//////////////////////////////////////////////////////////////////////////////////////////\n\n");
char nomecliente[61];

printf("Saudações, caro cliente! Por favor, informe seu nome: ");
scanf("%s",nomecliente);     

printf("\nBem-vindo ao SIG-Banking, %s!\n",nomecliente);  
}

