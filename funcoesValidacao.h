#define True 1
#define False 0

// função validaCPF
// Retorna 1, se o cpf for válido, ou retorna 0 se o cpf for inválido
// referência: http://pog-carlos.blogspot.com/2011/11/validacao-de-cpf-em-c-usando-vetor.html
int validaCPF (char []);


// função validaData
// Recebe uma data no formato(dia, mes, ano) e verifica se é válida
// Retorna 1 se a data for válida, ou 0 se a data for inválida
// adaptado de @flaviusgorgonio: 
// https://repl.it/@flaviusgorgonio/ValidaDataComFuncoesc
// referência:
// https://pt.stackoverflow.com/questions/159141/obter-a-data-atual-diretamente-pela-m%C3%A1quina
int validaData (char [], char [], char []);


// função bissexto
// Recebe um ano e verifica se o ano é bissexto ou não
// Retorna 1 se o ano for bissexto, ou 0 se o ano não for bissexto
// código de @flaviusgorgonio:
// https://repl.it/@flaviusgorgonio/ValidaDataComFuncoesc
int bissexto(int);


// função validaNome
// Recebe um nome (vetor de char) e verifica se o nome é válido ou não
// Retorna 1 se o nome for válido, ou 0 caso contrário
int validaNome (char []);


// função validaFloat
// Recebe um valor (vetor de char) e verifica se o valor é válido ou não
// Retorna 1 se o valor for válido, ou 0 caso contrário
int validaFloat(char []);


// função converteParaFloat
// Recebe um valor (vetor de char) converte para float
// Retorna o valor float
float converteParaFloat(char []);