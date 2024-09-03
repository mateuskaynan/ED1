#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"

int main(){
    //CRIAÇÃO DAS DISCIPLINAS
    Disciplina * disciplina1 = cria_discplina("ESTRUTURAS DE DADOS I", 123);
    Disciplina * disciplina2 = cria_discplina("LAB. ESTRUTURAS DE DADOS I", 321);
    Disciplina * disciplina3 = cria_discplina("CALCULO II", 456);
    Disciplina * disciplina4 = cria_discplina("GEOMETRIA ANALITICA", 654);

    //CRIAÇÃO DOS ALUNOS
    Aluno * aluno1 = cria_aluno("Mateus Elias", 2023022797);
    Aluno * aluno2 = cria_aluno("Kainan Silva", 202010007);

    //MATRICULA Aluno1 NAS DISCIPLINAS 1 E 2
    matricula_disciplina(aluno1, disciplina1);
    matricula_disciplina(aluno1, disciplina2);
    //MATRICULA Aluno2 NAS DISCIPLINAS 3 E 4 
    matricula_disciplina(aluno2, disciplina2);
    matricula_disciplina(aluno2, disciplina4);

    //EXIBE Aluno1
    printf("\n----- ALUNO 1 -----");
    exibe_aluno(aluno1);
    printf("\n-------------------");
    //EXIBE Aluno2
    printf("\n----- ALUNO 2 -----");
    exibe_aluno(aluno2);
    printf("\n-------------------");

    //CHAMADA DAS FUNCÇÕES PARA EXCLUIR DISCIPLINAS E ALUNOS
    exclui_disciplina(disciplina1);
    exclui_disciplina(disciplina2);
    exclui_disciplina(disciplina3);
    exclui_disciplina(disciplina4);
    exclui_aluno(aluno1);
    exclui_aluno(aluno2);
    
    return 0; 
}