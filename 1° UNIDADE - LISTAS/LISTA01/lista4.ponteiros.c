#include <stdio.h>
#include <math.h> 

/*FUNÇÃO RESPONSÁVEL PELO CÁLCULO DO PERÍMETRO E DA ÁREA*/
void calcula_hexagono(float l, float *area, float *perimetro){
    *perimetro = 6 * l; /*CALCULO DO PERÍMETRO*/ 
    
    *area = (3 * pow(l, 2) * sqrt(3)) / 2; /*CALCULO DA ÁREA*/ 
}

int main(){
    float area, perimetro, l;

    printf("INFORME O VALOR DO LADO: ");
    scanf("%f", &l);
    
    calcula_hexagono(l, &area, &perimetro); /*CHAMADA DA FUNÇÃO QUE REALIZA O CALCULO DO PERÍMETRO E DA ÁREA*/

    printf("AREA DO EXAGONO: %.2f", area);
    printf("\nPERIMETRO DO EXAGONO: %.2f", perimetro);

    return 0; 
}