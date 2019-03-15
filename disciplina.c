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
    disciplina.turma[0].professor.ra = 0;
    disciplina.turma[0].listaAlunoDisciplina = lista;
    disciplina.turma[1].numeroDaTurma = 2;
    disciplina.turma[1].professor.ra = 0;
    disciplina.turma[1].listaAlunoDisciplina = lista2;
    return disciplina;
}

void criarListaAlunoDisciplina(ListaAlunoDisciplina **aList) {
    *aList = (ListaAlunoDisciplina *) malloc(sizeof(ListaAlunoDisciplina));
}

void printarAlunosDeUmaDisciplinaTurma(ListaAlunoDisciplina *list) {
    if (list == NULL) {
        return;
    }
    if (list->aluno.ra != 0) {
        printf("Nome: %s\n", list->aluno.nome);
    }
    printarAlunosDeUmaDisciplinaTurma(list->next);
}

void printarDisciplinas(DisciplinaList *list) {
    if (list == NULL) {
        return;
    }
    printf("Nome: %s\n", list->disciplina.nome);
    if (list->disciplina.turma[0].professor.ra != 0 && list->disciplina.turma[0].professor.vinculado != 0) {
        printf("Professor turma 1: %s\n", list->disciplina.turma[0].professor.nome);
    }
    if (list->disciplina.turma[1].professor.ra != 0 && list->disciplina.turma[1].professor.vinculado != 0) {
        printf("Professor turma 2: %s\n", list->disciplina.turma[1].professor.nome);
    }
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

Disciplina *buscarDisciplina(DisciplinaList *list, char *disciplina) {
    Disciplina *d = (Disciplina *) malloc(sizeof(Disciplina));
    if (list == NULL) {
        strcpy(d->nome, "");
        return d;
    }
    if (strcmp(list->disciplina.nome, disciplina) == 0) {
        return &list->disciplina;
    }
    buscarDisciplina(list->next, disciplina);
}

Turma *buscaTurma(DisciplinaList *list, char *disciplina, int turma) {
    Turma *t = (Turma *) malloc(sizeof(Turma));
    if (list == NULL) {
        t->numeroDaTurma = 0;
        return t;
    }
    if (strcmp(list->disciplina.nome, disciplina) == 0 && list->disciplina.turma[0].numeroDaTurma == turma) {
        return &list->disciplina.turma[turma - 1];
    }

    if (strcmp(list->disciplina.nome, disciplina) == 0 && list->disciplina.turma[1].numeroDaTurma == turma) {
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
    printf("Disciplina cadastrada com sucesso");
}

void printarListaDeDisciplinasDeUmAluno(DisciplinaList *list) {
    int ra;
    printf("Informe o ra do aluno: ");
    scanf("%d", &ra);
    printDisciplinas(list->next, ra);
}

void printDisciplinas(DisciplinaList *list, int ra) {
    if (list == NULL) {
        return;
    }
    if (buscaAlunoNaDisciplina(list->disciplina.turma[0].listaAlunoDisciplina, ra)) {
        printf("Disciplina: %s\n", list->disciplina.nome);
    }
    if (buscaAlunoNaDisciplina(list->disciplina.turma[1].listaAlunoDisciplina, ra)) {
        printf("Disciplina %s\n", list->disciplina.nome);
    }
    printDisciplinas(list->next, ra);
}

int buscaAlunoNaDisciplina(ListaAlunoDisciplina *list, int ra) {
    if (list == NULL) {
        return 0;
    }
    if (list->aluno.ra == ra) {
        return 1;
    }
    buscaAlunoNaDisciplina(list->next, ra);
}

void printarListaDeAlunoEmUmaDisciplinaETurma(DisciplinaList *disciplinaList) {
    int turma;
    char disciplina[100];
    printf("Disciplina: ");
    scanf("%s", disciplina);
    printf("Turma: ");
    scanf("%d", &turma);
    Disciplina *d = buscarDisciplina(disciplinaList, disciplina);
    printarAlunosDeUmaDisciplinaTurma(d->turma[turma - 1].listaAlunoDisciplina);
}

void printarListaDeAlunosEmUmaDisciplina(DisciplinaList *disciplinaList) {
    char disciplina[100];
    printf("Disciplina: ");
    scanf("%s", disciplina);
    Disciplina *d = buscarDisciplina(disciplinaList, disciplina);
    printf("Turma 1 \n");
    printarAlunosDeUmaDisciplinaTurma(d->turma[0].listaAlunoDisciplina);
    printf("Turma 2 \n");
    printarAlunosDeUmaDisciplinaTurma(d->turma[1].listaAlunoDisciplina);
}

void printarTodasAsDisciplinasMinistradasPorUmProfessor(DisciplinaList *disciplinaList) {
    int ra;
    printf("Ra professor: ");
    scanf("%d", &ra);
    printarDisciplinasDeUmProfessor(disciplinaList, ra);
}

void printarDisciplinasDeUmProfessor(DisciplinaList *disciplinaList, int ra) {
    if (disciplinaList == NULL) {
        return;
    }
    if (disciplinaList->disciplina.turma[0].professor.ra == ra &&
        disciplinaList->disciplina.turma[0].professor.vinculado == 1) {
        printf("Disciplina %s, turma: %d \n", disciplinaList->disciplina.nome,
               disciplinaList->disciplina.turma[0].numeroDaTurma);
    }
    if (disciplinaList->disciplina.turma[1].professor.ra == ra &&
        disciplinaList->disciplina.turma[1].professor.vinculado == 1) {
        printf("Disciplina %s, turma: %d \n", disciplinaList->disciplina.nome,
               disciplinaList->disciplina.turma[1].numeroDaTurma);
    }
    printarDisciplinasDeUmProfessor(disciplinaList->next, ra);
}

void printarProfessoresVinculadoADisciplinas(DisciplinaList *disciplinaList) {
    if (disciplinaList == NULL) {
        return;
    }
    if (disciplinaList->disciplina.turma[0].professor.vinculado == 1 ||
        disciplinaList->disciplina.turma[1].professor.vinculado == 1) {
        printf("Professor: %s \n", disciplinaList->disciplina.turma[0].professor.nome);
    }
    printarProfessoresVinculadoADisciplinas(disciplinaList->next);
}
