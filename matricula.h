//
// Created by joaooctf on 23/02/19.
//

#ifndef PARADIGMAS_MATRICULA_H
#define PARADIGMAS_MATRICULA_H

#include "aluno.h"
#include "disciplina.h"

typedef struct {
    Aluno aluno;
    char disciplinas[15][100];
    int qtd;
} LoteMatricula;

typedef struct {
    Professor professor;
    char disciplinas[15][100];
} LoteProfessores;

void matricularAlunoNaDisciplina(DisciplinaList *lista, char *disciplina, int turma, Aluno aluno);

void cancelarAlunoNaDisciplina(DisciplinaList *listaDisciplina, char *disciplina, int turma, Aluno aluno);

void vincularProfessorNaDisciplina(DisciplinaList *listaDisciplina, char *disciplina, int turma, Professor professor);

// Vincular professor em uma disciplina

void insereProfessor(Turma *t, Professor professor);

void insereAluno(Turma *turma, Aluno aluno);

void cancelaAluno(Turma *turma, Aluno aluno);

void vincularProfessores(DisciplinaList *listaDisciplina, ProfessorList *pList);

void cancelarVinculoProfessores(DisciplinaList *listaDisciplina, ProfessorList *listaProfessor);

void removeProfessor(Turma *t, Professor professor);

void matricularAlunos(DisciplinaList *lista, AlunoList *listaAluno);

void cancelarMatricula(DisciplinaList *lista, AlunoList *listaAluno);

#endif //PARADIGMAS_MATRICULA_H
