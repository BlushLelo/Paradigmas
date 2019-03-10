//
// Created by joaooctf on 22/02/19.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "professor.h"
#include "menu.h"
#include <stdio_ext.h>


void criarListaDeProfessores(ProfessorList **pList) {
    *pList = (ProfessorList *) malloc(sizeof(ProfessorList));
}

void inserirProfessor(ProfessorList *list, Professor professor) {
    ProfessorList *head;
    if (list->next == NULL) {
        list->next = (ProfessorList *) malloc(sizeof(ProfessorList));
        head = list->next;
        head->professor = professor;
    } else {
        inserirProfessor(list->next, professor);
    }
}

Professor populateProfessor(char *nome, int ra) {
    Professor professor;
    professor.nome = (char*) malloc(strlen(nome) +1);
    strcpy(professor.nome, nome);
    professor.ra = ra;
    return professor;
}

void printaProfessores(ProfessorList *list) {
    if (list == NULL) {
        return;
    }
    printf("Nome: %s\n", list->professor.nome);
    printf("Ra: %d\n", list->professor.ra);
    printaProfessores(list->next);
}

void printaProfessor(ProfessorList *list, int ra) {
    if (list == NULL) {
        return;
    }
    if (list->professor.ra == ra) {
        printf("Nome: %s\n", list->professor.nome);
        printf("Ra: %d\n", list->professor.ra);
    }
    printaProfessor(list->next, ra);
}

void cadastrarProfessor(ProfessorList *list) {
    system("clear");
    menuProfessor();

    char professor[100];
    int ra;

    printf("Informe o nome do professor: ");
    __fpurge(stdin);
    scanf("%s", professor);
    printf("Informe o ra do professor: ");
    scanf("%d", &ra);

    Professor a = populateProfessor(professor, ra);
    inserirProfessor(list, a);
    printaProfessor(list, ra);
    printf("Professor cadastrado com sucesso");
}