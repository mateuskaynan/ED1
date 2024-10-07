#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct carro Carro; 

typedef struct sistema Sistema; 

//FUNÇÃO QUE CRIA UM NOVO CARRO 
Carro * criar_carro(int codigo, const char * modelo, float preco);

//FUNÇÃO QUE INSERE UM CARRO NA LISTA DE FORMA ORDENADA A PARTIR DE UM CÓDIGO 
void inserir_carro(Sistema * sistema, Carro * carro);