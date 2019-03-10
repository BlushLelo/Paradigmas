//
// Created by joaooctf on 22/02/19.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "disciplina.h"
#include "menu.h"


void criarListaDeDisciplinas(DisciplinaList **pList) {
    *pList = (DisciplinaList *) malloc(sizeof(DisciplinaList));
}

void inserirDisciplina(DisciplinaList *list, Disciplina disciplina) {
    DisciplinaList *head;
    if (list->next == NULL) {
        list->next = (DisciplinaList *) malloc(sizeof(DisciplinaList));
        head = list->next;
        head->disciplina = disciplina;
    } else {
        inserirDisciplina(list->next, disciplina);
    }
}

Disciplina popularDisciplina(char *nome) {
    Disciplina disciplina;
    ListaAlunoDisciplina *lista;
    ListaAlunoDisciplina *lista2;
    criarListaAlunoDisciplina(&lista);
    criarListaAlunoDisciplina(&lista2);
    strcpy(disciplina.nome, nome);
    disciplina.turma[0].numeroDaTurma = 1;
    disciplina.turma[0].listaAlunoDisciplina = lista;
    disciplina.turma[1].numeroDaTurma = 2;
    disciplina.turma[1].listaAlunoDisciplina = lista2;
    return disciplina;
}

void criarListaAlunoDisciplina(ListaAlunoDisciplina **aList) {
    *aList = (ListaAlunoDisciplina *) malloc(sizeof(ListaAlunoDisciplina));
}

void printarDisciplinas(DisciplinaList *list) {
    if (list == NULL) {
        return;
    }
    printf("Nome: %s\n", list->disciplina.nome);
    printf("Turma 1: %d\n", list->disciplina.turma[0].numeroDaTurma);
    printf("Turma 2: %d\n", list->disciplina.turma[1].numeroDaTurma);
    printarDisciplinas(list->next);
}

void printarDisciplina(DisciplinaList *list, char *disciplina) {
    if (list == NULL) {
        return;
    }
    if (strcmp(list->disciplina.nome, disciplina) == 0) {
        printf("Nome: %s\n", list->disciplina.nome);
        printf("Turma: %d\n", list->disciplina.turma->numeroDaTurma);
    }
    printarDisciplina(list->next, disciplina);
}

Turma *buscaTurma(DisciplinaList *list, char *disciplina, int turma) {
    Turma *t = (Turma *) malloc(sizeof(Turma));
    if (list == NULL) {
        t->numeroDaTurma = 0;
        return t;
    }
    if (strcmp(list->disciplina.nome, disciplina) == 0 && list->disciplina.turma->numeroDaTurma == turma) {
        return &list->disciplina.turma[turma - 1];
    }
    buscaTurma(list->next, disciplina, turma);
}


void insertAlunoDisciplina(ListaAlunoDisciplina *list, Aluno aluno) {
    ListaAlunoDisciplina *head;
    if (list->next == NULL) {
        list->next = (ListaAlunoDisciplina *) malloc(sizeof(ListaAlunoDisciplina));
        head = list->next;
        head->aluno = aluno;
    } else {
        insertAlunoDisciplina(list->next, aluno);
    }
}


void removerAlunoDisciplina(ListaAlunoDisciplina *list, Aluno aluno) {
    ListaAlunoDisciplina *temp;
    if (list->next != NULL) {
        temp = list->next;
        if (temp->aluno.ra == aluno.ra) {
            list->next = temp->next;
            free(temp);
        }
    } else {
        removerAlunoDisciplina(list->next, aluno);
    }
}

void cadastrarDisciplina(DisciplinaList *list) {
    system("clear");
    menuDisciplina();

    char disciplina[100];

    printf("Informe o nome da disciplina: ");
    __fpurge(stdin);
    scanf("%s", disciplina);

    Disciplina d = popularDisciplina(disciplina);
    inserirDisciplina(list, d);
    printarDisciplina(list, d.nome);
    printf("Disciplina cadastrada com sucesso");
}