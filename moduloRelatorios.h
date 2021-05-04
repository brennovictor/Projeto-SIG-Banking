// Em desenvolvimento...
typedef struct cliente Cliente;
void moduloRelatorios(void);
char menuRelatorios (void);
void relatorioClientes (void);
void relatorioContas (void);
void relatorioSaldos (void);
void relatorioSaques (void);
void relatorioDepositos (void);
void relatorioTransferências (void);
void relatClientesCadastrados(void);
int listaClientesCadastrados(void);
void relatContasCadastradas(void);
int listaContasCadastradas(void);
void contasPorCliente(void);
char* telaContasPorCliente(void);
void relatContasPorCliente(Cliente*);
int listaContasPorCliente(Cliente*);