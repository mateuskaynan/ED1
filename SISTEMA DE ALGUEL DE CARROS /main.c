#include "sistema.c"

int main(){

    Sistema sistema; 
    /*INICIALIZA A LISTA DE CARRO COM 0 CARROS(NULL)*/
    sistema.carro = NULL; 

    //CRIANDO A LISTA DE CARROS
    /*CARRO 1*/
    Carro * carro001 = criar_carro(001, "CLASSIC", 80.00);
    inserir_carro(&sistema, carro001); 
    /*CARRO 2*/
    Carro * carro002 = criar_carro(002, "UNO", 100.00);
    inserir_carro(&sistema, carro002);
    /*CARRO 3*/
    Carro * carro003 = criar_carro(003, "GOL", 150.00);
    inserir_carro(&sistema, carro003);
    /*CARRO 4*/
    Carro * carro004 = criar_carro(004, "TOYOTA", 180.00);
    inserir_carro(&sistema, carro004);
    /*CARRO 5*/
    Carro * carro005 = criar_carro(005, "PRISMA", 200.00);
    inserir_carro(&sistema, carro005);  
    /*CARRO 6*/
    Carro * carro006 = criar_carro(006, "DOBLO", 300.00);
    inserir_carro(&sistema, carro006);
    /*CARRO 7*/
    Carro * carro007 = criar_carro(006, "VAN", 350.00);
    inserir_carro(&sistema, carro007); 

    return 0; 
}