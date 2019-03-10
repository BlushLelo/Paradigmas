//
// Created by joaooctf on 22/02/19.
//

#ifndef PARADIGMAS_ALUNO_H
#define PARADIGMAS_ALUNO_H

//Struct de um Aluno
typedef struct {
    char nome[100];
    int ra;
} Aluno;

//Struct Lista de Aluno
typedef struct {
    Aluno aluno;
    struct AlunoList *next;
} AlunoList;

// Cria Lista de alunos
void createList(AlunoList **pList);

// Insere um aluno no final na lista de alunos
void insertElement(AlunoList *list, Aluno aluno);

// Retorna uma struct de um aluno populada
Aluno populateAluno(char *nome, int ra);

Aluno *buscaAluno(AlunoList *list, int ra);

// Printa todos os alunos da lista de alunos
void printAluno(AlunoList *list);

// Pede um aluno e o insere na lista de Alunos
void cadastrarAluno(AlunoList *list);

void printaAluno(AlunoList *list, int ra);

#endif //PARADIGMAS_ALUNO_H
