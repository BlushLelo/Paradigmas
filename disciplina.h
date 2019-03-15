//
// Created by joaooctf on 22/02/19.
//

#ifndef PARADIGMAS_DISCIPLINA_H
#define PARADIGMAS_DISCIPLINA_H

#include "aluno.h"
#include "professor.h"


// Lista de alunos matriculados em uma disciplina
typedef struct {
    Aluno aluno;
    struct ListaAlunoDisciplina *next;
} ListaAlunoDisciplina;

// Struct de uma turma
typedef struct {
    int numeroDaTurma;
    ListaAlunoDisciplina *listaAlunoDisciplina;
    Professor professor;
} Turma;

//Struct de uma Disciplina
typedef struct {
    char nome[100];
    Turma turma[2];
} Disciplina;

//Struct Lista de Disciplinas
typedef struct {
    Disciplina disciplina;
    struct DisciplinaList *next;
} DisciplinaList;

// Cria Lista de alunos
void criarListaDeDisciplinas(DisciplinaList **pList);

// InsertLista
void insertAlunoDisciplina(ListaAlunoDisciplina *list, Aluno aluno);

// RemoveLista
void removerAlunoDisciplina(ListaAlunoDisciplina *list, Aluno aluno);

// Insere um aluno no final na lista de alunos
void inserirDisciplina(DisciplinaList *list, Disciplina disciplina);

// Criar Lista de alunos dentro da Disciplina
void criarListaAlunoDisciplina(ListaAlunoDisciplina **aList);

void printarAlunosDeUmaDisciplinaTurma(ListaAlunoDisciplina *list);

void printarListaDeDisciplinasDeUmAluno(DisciplinaList *list);

void printDisciplinas(DisciplinaList *list, int ra);

void printarListaDeAlunoEmUmaDisciplinaETurma(DisciplinaList *disciplinas);

void printarListaDeAlunosEmUmaDisciplina(DisciplinaList *disciplinaList);

void printarDisciplinasDeUmProfessor(DisciplinaList *disciplinaList, int ra);

void printarTodasAsDisciplinasMinistradasPorUmProfessor(DisciplinaList *disciplinaList);

void printarProfessoresVinculadoADisciplinas(DisciplinaList *disciplinaList);

// Retorna uma struct de uma disciplina populada
Disciplina popularDisciplina(char *nome);

// Printa todos os alunos da lista de alunos
void printarDisciplinas(DisciplinaList *list);

// Busca disciplinaPorTurma
Turma *buscaTurma(DisciplinaList *list, char *disciplina, int turma);

// Printa disciplina especifica
void printarDisciplina(DisciplinaList *list, char *disciplina);

Disciplina *buscarDisciplina(DisciplinaList *list, char *disciplina);

int buscaAlunoNaDisciplina(ListaAlunoDisciplina *list, int ra);

// Pede um aluno e o insere na lista de Alunos
void cadastrarDisciplina(DisciplinaList *list);

#endif //PARADIGMAS_DISCIPLINA_H

