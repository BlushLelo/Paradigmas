//
// Created by joaooctf on 22/02/19.
//

#include <stdio.h>
#include "menu.h"

void menuInicial() {
    printf("\n************************Matricula*************************\n");
    printf("Opções:\n");
    printf("1- Cadastrar Alunos\n");
    printf("2- Cadastrar Disciplinas\n");
    printf("3- Cadastrar Professores\n");
    printf("4- Matricular alunos em disciplinas\n");
    printf("5- Desmatricular alunos de disciplinas\n");
    printf("6- Vincular professores em disciplinas\n");
    printf("7- Remover professores de disciplinas\n");
    printf("8- Printar todos os alunos\n");
    printf("9- Printar todas as disciplinas\n");
    printf("10- Printar todos os professores\n");
    printf("11- Printar todas as disciplinas de um aluno\n");
    printf("12- Printar lista de alunos em uma disciplina e turma\n");
    printf("13- Printar lista de alunos em uma disciplina independente de turma\n");
    printf("14- Printar lista de disciplinas ministradas por um professor\n");
    printf("15- Printar lista de todos os professores vinculados a uma disciplina\n");
    printf("16- Sair\n");
    printf("Informe a opção desejada: ");
}

void menuAluno() {
    printf("*****************Cadastro de Aluno*****************\n");
}

void menuProfessor() {
    printf("*****************Cadastro de Professor*****************\n");
}

void menuDisciplina() {
    printf("*****************Cadastro de Disciplina*****************\n");
}


void menuMatricula() {
    printf("*****************Matricula de Alunos*****************\n");
}


void menuCancelarMatricula() {
    printf("*****************Cancelar Matricula de Alunos*****************\n");
}

void menuVincularProfessor() {
    printf("*****************Vincular Professores a Disciplinas*****************\n");
}

void menuRemoverProfessorDeDisciplina() {
    printf("*****************Remover Professores de Disciplinas*****************\n");
}


void menuPrintarTodosOsAlunos() {
    printf("*****************Lista de Todos os Alunos*****************\n");
}


void menuPrintarTodasAsDisciplinas() {
    printf("*****************Lista de Todas as Disciplinas*****************\n");
}


void menuPrintarTodosOsProfessores() {
    printf("*****************Lista de Todos os Professores*****************\n");
}


void menuPrintarTodasAsDisciplinasDeUmAluno() {
    printf("*****************Lista de Disciplinas de um Aluno*****************\n");
}
