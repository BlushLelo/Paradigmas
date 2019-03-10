//
// Created by joaooctf on 22/02/19.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "aluno.h"
#include "menu.h"
#include <stdio_ext.h>


void createList(AlunoList **pList) {
    *pList = (AlunoList *) malloc(sizeof(AlunoList));
}

void insertElement(AlunoList *list, Aluno aluno) {
    AlunoList *head;
    if (list->next == NULL) {
        list->next = (AlunoList *) malloc(sizeof(AlunoList));
        head = list->next;
        head->aluno = aluno;
    } else {
        insertElement(list->next, aluno);
    }
}

Aluno populateAluno(char *nome, int ra) {
    Aluno aluno;
    strcpy(aluno.nome, nome);
    aluno.ra = ra;
    return aluno;
}

void printAluno(AlunoList *list) {
    if (list == NULL) {
        return;
    }
    printf("Nome: %s\n", list->aluno.nome);
    printf("Ra: %d\n", list->aluno.ra);
    printAluno(list->next);
}

Aluno *buscaAluno(AlunoList *list, int ra) {
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));;
    if (list == NULL) {
        aluno->ra = 0;
        return aluno;
    }
    if (list->aluno.ra == ra) {
        aluno->ra = list->aluno.ra;
        strcpy(aluno->nome, list->aluno.nome);
        return aluno;
    }
    buscaAluno(list->next, ra);
}

void printaAluno(AlunoList *list, int ra) {
    if (list == NULL) {
        return;
    }
    if (list->aluno.ra == ra) {
        printf("%d", list->aluno.ra);
        printf("%s", list->aluno.nome);
    }
    printaAluno(list->next, ra);
}

void cadastrarAluno(AlunoList *list) {
    system("clear");
    menuAluno();

    char aluno[100];
    int ra;

    printf("Informe o nome do aluno: ");
    __fpurge(stdin);
    scanf("%s", aluno);
    printf("Informe o ra do aluno: ");
    scanf("%d", &ra);

    Aluno a = populateAluno(aluno, ra);
    insertElement(list, a);
    printaAluno(list, ra);
    printf("Aluno cadastrado com sucesso");
}