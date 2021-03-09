#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>

// função validaCPF
// Retorna 1 se o cpf for válido, ou retorna 0 se o cpf for inválido
// referência: http://pog-carlos.blogspot.com/2011/11/validacao-de-cpf-em-c-usando-vetor.html

int validaCPF (char cpf[12]) {
	int i1, i2;
	int intcpf[12];
	int soma1=0, soma2=0, digito1, digito2, resultado1, resultado2;
	
	for (int i = 0; cpf[i] != '\0'; i++) {
		if (!isdigit(cpf[i])) {
			return 0;
		}
	}
	
	if (strlen(cpf) != 11) {
		return 0;
	}
	
	if (
	(strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || 
	(strcmp(cpf,"22222222222") == 0) || (strcmp(cpf,"33333333333") == 0) || 
	(strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
    (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || 
	(strcmp(cpf,"88888888888") == 0) || (strcmp(cpf,"99999999999") == 0) ) {
		return 0;
		// Se o cpf tiver todos os algarismos iguais, ele é inválido
	}
	
	// convertendo char em int:
	for (int i = 0; i < 11; i ++) {
		intcpf[i] = cpf[i] - 48;
	}

	// Verificando o primeiro digito: 
	for (i1 = 0, i2 = 10; i1 < 9 || i2 > 2; i1 ++, i2 --)  {  
		soma1 += intcpf[i1] * (i2);  
		resultado1 = soma1 % 11;
		resultado1 = 11 - resultado1;
	}  

	if (resultado1 > 9) {
		digito1 = 0; 
	} 
	else {
		digito1 = resultado1;
	}
	
	if (digito1 != intcpf[9]) {
		return 0;
	}
	
	// Verificando o segundo digito:
	for (i1 = 0, i2 = 11; i1 < 10 || i2 > 2; i1 ++, i2 --) {  
		soma2 += intcpf[i1] * (i2);  
		resultado2 = soma2 % 11;
		resultado2 = 11 - resultado2;
	}  

	if (resultado2 > 9) {
		digito2 = 0; 
	} 
	else {
		digito2 = resultado2;
	}
	if (digito2 != intcpf[10]) {
		return 0;
	}
	return 1;
}



// função validaData
// Recebe uma data no formato(dia, mes, ano) e verifica se é válida
// Retorna 1 se a data for válida, ou 0 se a data for inválida
// adaptado de @flaviusgorgonio: 
// https://repl.it/@flaviusgorgonio/ValidaDataComFuncoesc
// referência:
// https://pt.stackoverflow.com/questions/159141/obter-a-data-atual-diretamente-pela-m%C3%A1quina

int validaData(int dia, int mes, int ano) {
	int bissexto (int);
	int maiorDia, diaAtual, mesAtual, anoAtual;
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
	
	diaAtual = tm.tm_mday;
	mesAtual = tm.tm_mon + 1;
	anoAtual = tm.tm_year + 1900;

	if (ano < 0 || mes < 1 || mes > 12 || dia < 1) {
		return 0;
	}
	if (ano > anoAtual) {
		return 0;
	}
	if (ano == anoAtual) {
		if (mes > mesAtual) {
			return 0;
		}
		else if (mes == mesAtual) {
			if (dia > diaAtual) {
				return 0;
			}
		}
	}
	if (mes == 2) {
		if (bissexto(ano)) {
		maiorDia = 29;
		} 
		else {
		maiorDia = 28;
		}
	} 
	else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		maiorDia = 30;
	} 
	else {
		maiorDia = 31;
	}
	if (dia > maiorDia) {
		return 0;
	}
	return 1;
}



// função bissexto
// Recebe um ano e verifica se o ano é bissexto ou não
// Retorna 1 se o ano for bissexto, ou 0 se o ano não for bissexto
// código de @flaviusgorgonio:
// https://repl.it/@flaviusgorgonio/ValidaDataComFuncoesc
int bissexto(int ano) {
	if ((ano % 4 == 0) && (ano % 100 != 0)) {
		return 1;
	} 
	else if (ano % 400 == 0) {
		return 1;
	} 
	else {
		return 0;
	}
}