#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#define MAX_DISCIPLINAS 10

typedef struct disciplina Disciplina; 

// FUNÇÃO RESPONSÁVEL POR CRIAR UMA NOVA DISCIPLINA
Disciplina * cria_disciplina(const char * nome_disciplina, int codigo);

// FUNÇÃO RESPONSÁVEL POR EXCLUIR UMA DISCIPLINA
void exclui_disciplina(Disciplina * disciplina);

#endif