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
    printf("5- Vincular professores em disciplinas\n");
    printf("5- Sair\n");
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
