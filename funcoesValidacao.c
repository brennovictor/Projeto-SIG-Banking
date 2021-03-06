#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// função validaCPF
// Retorna 1 se o cpf for válido, ou retorna 0 se o cpf for inválido
// referência: http://pog-carlos.blogspot.com/2011/11/validacao-de-cpf-em-c-usando-vetor.html

int validaCPF (char cpf[12]) {
	int i1, i2;
	int intcpf[12];
	int soma1=0, soma2=0, digito1, digito2, resultado1, resultado2;
	
	if (strlen(cpf) != 11) {
		return 0;
	}
	
	for (int i = 0; cpf[i] != '\0'; i++) {
		if (!isdigit(cpf[i])) {
			return 0;
		}
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

int validaData(char dia[3], char mes[3], char ano[5]) {
	int bissexto(int);
	int maiorDia, diaAtual, mesAtual, anoAtual;
	int intDia = 0, intMes = 0, intAno = 0, tamDia, tamMes, tamAno;
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

	diaAtual = tm.tm_mday;
	mesAtual = tm.tm_mon + 1;
	anoAtual = tm.tm_year + 1900;

	for (int i = 0; dia[i] != '\0'; i++) {
		if (!isdigit(dia[i])) {
			return 0;
		}
	}

	for (int i = 0; mes[i] != '\0'; i++) {
		if (!isdigit(mes[i])) {
			return 0;
		}
	}

	for (int i = 0; ano[i] != '\0'; i++) {
		if (!isdigit(ano[i])) {
			return 0;
		}	
	}

	if (strlen(dia) < 1 || strlen(mes) < 1 || strlen(ano) < 1) {
		return 0;
	}

	tamDia = strlen(dia) - 1;
	tamMes = strlen(mes) - 1;
	tamAno = strlen(ano) - 1;

	if (tamDia == 0) {
		intDia = dia[0] - 48;
	}
	else {
		for (int i = 0, i2 = tamDia; i < strlen(dia); i++, i2--) {
			intDia += (dia[i] - 48) * pow(10, i2);
		}
	}

	if (tamMes == 0) {
		intMes = mes[0] - 48;
	}
	else {
		for (int i = 0, i2 = tamMes; i < strlen(mes); i++, i2--) {
			intMes += (mes[i] - 48) * pow(10, i2);
		}
	}
	
	if (tamAno == 0) {
		intAno = ano[0] - 48;
	}
	else {
		for (int i = 0, i2 = tamAno; i < strlen(ano); i++, i2--) {
			intAno += (ano[i] - 48) * pow(10, i2);
		}
	}


	if (intAno < 0 || intMes < 1 || intMes > 12 || intDia < 1) {
		return 0;
	}
	if (intAno > anoAtual) {
		return 0;
	}
	if (intAno == anoAtual) {
		if (intMes > mesAtual) {
			return 0;
		}
		else if (intMes == mesAtual) {
			if (intDia > diaAtual) {
				return 0;
			}
		}
	}
	if (intMes == 2) {
		if (bissexto(intAno)) {
		maiorDia = 29;
		} 
		else {
		maiorDia = 28;
		}
	} 
	else if (intMes == 4 || intMes == 6 || intMes == 9 || intMes == 11) {
		maiorDia = 30;
	} 
	else {
		maiorDia = 31;
	}
	if (intDia > maiorDia) {
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


// função validaNome
// Recebe um nome (vetor de char) e verifica se o nome é válido ou não
// Retorna 1 se o nome for válido, ou 0 caso contrário
int validaNome (char nome[41]) {
	if (strlen(nome) > 40) {
		return 0;
	}
	int tam, letra; 
	tam = strlen(nome);

	for (int i = 0; i < tam; i++) {
		if (nome[i] >= 'A' && nome[i] <= 'Z') {
      		continue;
		} else if (nome[i] >= 'a' && nome[i] <= 'z') {
			continue;
		} else if (nome[i] == ' ') {
			continue;
		} else {
			return 0;
		}
  	}
	return 1;
}




int validaFloat(char valor[20]) {
	int acheiVirg = 0;
	int partDec = 0;

	if (valor[0] == ',' || valor[0] == '.' ||
		valor[strlen(valor)-1] == ',' ||
		valor[strlen(valor)-1] == '.') {
			return 0;
		}

	// Verificando caracteres válidos
	for (int i = 0; valor[i] != '\0'; i++) {
		if (!isdigit(valor[i])) {
			if (valor[i] == ',' || valor[i] == '.') {
				acheiVirg += 1;
			} else {
				return 0;
			}
		} else {
			if (acheiVirg > 0) {
				partDec += 1;
			}
		}
	}
	if (acheiVirg > 1) {
		return 0;
	}
	if (partDec > 2) {
		return 0;
	}
	return 1;
}



float converteParaFloat(char valor[20]) {
	int acheiVirg = 0;
	float num = 0;
	int tamPartInt = 0;
	char virg;

	for (int i = 0; valor[i] != '\0'; i++) {
		if (!isdigit(valor[i])) {
			acheiVirg += 1;
			virg = valor[i];
		} else if (isdigit(valor[i]) > 0 && acheiVirg == 0) {
			tamPartInt += 1;
		}
	}
	tamPartInt -= 1;
	// Convertendo em float
	if (acheiVirg == 0) {
		for (int i = 0, i2 = tamPartInt; i < strlen(valor); i++, i2--) {
			num += (valor[i] - 48) * pow(10, i2);
		}
	} else {
		for (int i = 0, i2 = tamPartInt; i < strlen(valor); i++, i2--) {
			if (valor[i] != virg) {
				num += (valor[i] - 48) * pow(10, i2);
			} else {
				i2++;
			}
		}
	}
	return num;
}