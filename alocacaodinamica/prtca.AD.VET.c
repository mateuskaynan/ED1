#include<stdio.h>

int main(void){
    int N, cont, cont1;
    //QUANTIDADE DE MULHERES QUE GOSTARAM DO PRODUTO
    int m = 0;
    int porcentagemFem = 0;
    float porcentagemtotalFem = 0;

    // PORCENTAGEM DE QUANTIDADE DE SATISTAÇÃO DE HOMENS COM O PRODUTO
    int h = 0;
    int porcentagemMasc = 0;
    float porcentagemtotalMasc = 0;

    printf ("NÚMERO DE PESSOAS ENREVISTADAS: ");
    scanf("%d", &N);

    // MATRIZES QUE ARMAZENARÃO AS RESPOSTAS
    char sexo[N];
    char op[N];

    for(cont = 0; cont < N; cont++){
        printf("DIGITE O SEXO (%d) MASCULINO-FEMININO: ", cont);
        scanf(" %c", &sexo[cont]);
        printf("VOCÊ FICOU SATISFTEITO COM O PRODUTO? (%d)SIM-NÃO ", cont);
        scanf(" %c", &op[cont]);
    }
    //RESPONSÁVEL PARA ATRIBUIÇÃO DAS RESPOSTAS
    for(cont1 = 0; cont1 < N; cont1++){
        // CONTADOR REFERENTE A QUANTIDADE DE MULHERES QUE GOSTARAM
        if (sexo[cont1] == 'f'){
            m++;
            if (op[cont1] == 's'){
                porcentagemFem++;
            }
        
        }
        // contador para a quantidade e porcentagem de homens que não gostaram
        if (sexo[cont1] == 'm'){
            h++;
            if (op[cont1] == 'n'){
                porcentagemMasc++;
            }
        }
    }
    // calculando a porcentagem feminina
    if (m != 0){
        porcentagemtotalFem = (porcentagemFem * 100)/m;
    }
    //calculando a porcentagem masculina
    if (h != 0){
        porcentagemtotalMasc = (porcentagemMasc * 100)/h;
    }
    //imprime as informações
    printf("==================== RESULTADOS ====================\n");
    printf("> %d PESSOAS ENTREVISTADAS\n ", N);
    printf("%d POR CENTO DE MULHERES \n%d POR CENTO DE HOMENS\n", m, h);
    printf("%.2f POR CENTO DE MULHERES GOSTARAM DO PRODUTO\n ", porcentagemtotalFem);
    printf("%.2f POR CENTO DE HOMENS NÃO GOSTARAM DO PRODUTO\n ", porcentagemtotalMasc);
    printf("======================================================="); 
    return 0;
}