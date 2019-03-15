//
// Created by joaooctf on 23/02/19.
//

#include <string.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "matricula.h"
#include "menu.h"

void matricularAlunoNaDisciplina(DisciplinaList *listaDisciplina, char *disciplina, int turma, Aluno aluno) {
    Turma *t = buscaTurma(listaDisciplina, disciplina, turma);
    if (t->numeroDaTurma != 0) {
        insereAluno(t, aluno);
    } else {
        printf("Erro ao encontrar disciplina, a turma não existe!\n");
    }
}

void cancelarAlunoNaDisciplina(DisciplinaList *listaDisciplina, char *disciplina, int turma, Aluno aluno) {
    Turma *t = buscaTurma(listaDisciplina, disciplina, turma);
    if (t->numeroDaTurma != 0) {
        cancelaAluno(t, aluno);
    } else {
        printf("Erro ao encontrar disciplina, a turma não existe!\n");
    }
}

void vincularProfessorNaDisciplina(DisciplinaList *listaDisciplina, char *disciplina, int turma, Professor professor) {
    Turma *t = buscaTurma(listaDisciplina, disciplina, turma);
    if (t->numeroDaTurma != 0) {
        insereProfessor(t, professor);
    } else {
        printf("Turma inexistente!\n");
    }
}

void removerProfessorDaDisciplina(DisciplinaList *listaDisciplina, char *disciplina, int turma, Professor professor) {
    Turma *t = buscaTurma(listaDisciplina, disciplina, turma);
    if (t->numeroDaTurma != 0) {
        removeProfessor(t, professor);
    } else {
        printf("Turma inexistente!\n");
    }
}

void insereAluno(Turma *turma, Aluno aluno) {
    insertAlunoDisciplina(turma->listaAlunoDisciplina, aluno);
}

void cancelaAluno(Turma *turma, Aluno aluno) {
    removerAlunoDisciplina(turma->listaAlunoDisciplina, aluno);
}

void matricularAlunos(DisciplinaList *lista, AlunoList *listaAluno) {
    menuMatricula();

    int ra;
    char disciplina[100];
    LoteMatricula loteMatricula[15];
    int opcao = 0;
    int opcao2 = 0;
    int turma;
    int indexAlunos = 0;
    int indexDisciplinas = 0;

    do {
        printf("Informe o ra do aluno: ");
        scanf("%d", &ra);
        Aluno *aluno = buscaAluno(listaAluno, ra);
        loteMatricula[indexAlunos].aluno = *aluno;
        printf("Opções\n");
        printf("1- novo aluno\n");
        printf("2- Sair\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            indexAlunos++;
        }
    } while (opcao == 1);

    do {
        printf("Informe a lista de disciplinas: ");
        __fpurge(stdin);
        scanf("%s", disciplina);

        for (int i = 0; i <= indexAlunos; i++) {
            strcpy(loteMatricula[i].disciplinas[indexDisciplinas], disciplina);
        }

        printf("Opção\n");
        printf("1- Outra disciplina\n");
        printf("2- Sair");
        scanf("%d", &opcao2);
        if (opcao2 == 1) {
            indexDisciplinas++;
        }
    } while (opcao2 == 1);

    printf("Informe a turma: ");
    scanf("%d", &turma);

    for (int i = 0; i <= indexAlunos; i++) {
        for (int j = 0; j <= indexDisciplinas; j++) {
            matricularAlunoNaDisciplina(lista,
                                        loteMatricula[i].disciplinas[j], turma, loteMatricula[i].aluno);
        }
    }
}

void cancelarMatricula(DisciplinaList *lista, AlunoList *listaAluno) {
    menuCancelarMatricula();

    int ra;
    char disciplina[100];
    LoteMatricula loteMatricula[15];
    int opcao = 0;
    int opcao2 = 0;
    int turma;
    int indexAlunos = 0;
    int indexDisciplinas = 0;

    do {
        printf("Informe o ra do aluno: ");
        scanf("%d", &ra);
        printf("Opções\n");
        printf("1- novo aluno\n");
        printf("2- Sair\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            Aluno *aluno = buscaAluno(listaAluno, ra);
            loteMatricula[indexAlunos].aluno = *aluno;
            indexAlunos++;
        }
    } while (opcao == 1);

    do {
        printf("Informe a lista de disciplinas: ");
        __fpurge(stdin);
        scanf("%s", disciplina);

        for (int i = 0; i <= indexAlunos; i++) {
            strcpy(loteMatricula[i].disciplinas[indexDisciplinas], disciplina);
        }

        printf("Opção\n");
        printf("1- Outra disciplina\n");
        printf("2- Sair");
        scanf("%d", &opcao2);
        if (opcao2 == 1) {
            indexDisciplinas++;
        }
    } while (opcao2 == 1);

    printf("Informe a turma: ");
    scanf("%d", &turma);

    for (int i = 0; i <= indexAlunos; i++) {
        for (int j = 0; j <= indexDisciplinas; j++) {
            cancelarAlunoNaDisciplina(lista,
                                      loteMatricula[i].disciplinas[j], turma, loteMatricula[i].aluno);
        }
    }

}


void insereProfessor(Turma *t, Professor professor) {
    professor.vinculado = 1;
    t->professor = professor;
}

void removeProfessor(Turma *t, Professor professor) {
    if (t->professor.ra == professor.ra) {
        t->professor.vinculado = 0;
    }
}

void vincularProfessores(DisciplinaList *listaDisciplina, ProfessorList *listaProfessor) {

    menuVincularProfessor();

    char disciplina[100];
    int opcao = 0;
    int opcao2 = 0;
    int professor;
    int turma;
    LoteProfessores loteProfessores;
    int indexDisciplinas = 0;

    do {
        printf("Informe o ra do profesor: ");
        scanf("%d", &professor);
        printf("Opções\n");
        printf("1- novo professor\n");
        printf("2- Sair\n");
        scanf("%d", &opcao);
        Professor *professorEncontrado = buscaProfessor(listaProfessor, professor);
        loteProfessores.professor = *professorEncontrado;
    } while (opcao == 1);

    do {
        printf("Informe a lista de disciplinas: ");
        __fpurge(stdin);
        scanf("%s", disciplina);

        strcpy(loteProfessores.disciplinas[indexDisciplinas], disciplina);

        printf("Opção\n");
        printf("1- Outra disciplina\n");
        printf("2- Sair");
        scanf("%d", &opcao2);
        if (opcao2 == 1) {
            indexDisciplinas++;
        }
    } while (opcao2 == 1);

    printf("Informe a turma: ");
    scanf("%d", &turma);

    for (int j = 0; j <= indexDisciplinas; j++) {
        vincularProfessorNaDisciplina(listaDisciplina,
                                      loteProfessores.disciplinas[j], turma, loteProfessores.professor);
    }
}

void cancelarVinculoProfessores(DisciplinaList *listaDisciplina, ProfessorList *listaProfessor) {

    menuRemoverProfessorDeDisciplina();

    char disciplina[100];
    int opcao = 0;
    int opcao2 = 0;
    int professor;
    int turma;
    LoteProfessores loteProfessores;
    int indexDisciplinas = 0;

    do {
        printf("Informe o ra do profesor: ");
        scanf("%d", &professor);
        printf("Opções\n");
        printf("1- novo professor\n");
        printf("2- Sair\n");
        scanf("%d", &opcao);
        Professor *professorEncontrado = buscaProfessor(listaProfessor, professor);
        loteProfessores.professor = *professorEncontrado;
    } while (opcao == 1);

    do {
        printf("Informe a lista de disciplinas: ");
        __fpurge(stdin);
        scanf("%s", disciplina);

        strcpy(loteProfessores.disciplinas[indexDisciplinas], disciplina);

        printf("Opção\n");
        printf("1- Outra disciplina\n");
        printf("2- Sair");
        scanf("%d", &opcao2);
        if (opcao2 == 1) {
            indexDisciplinas++;
        }
    } while (opcao2 == 1);

    printf("Informe a turma: ");
    scanf("%d", &turma);

    for (int j = 0; j <= indexDisciplinas; j++) {
        removerProfessorDaDisciplina(listaDisciplina,
                                     loteProfessores.disciplinas[j], turma, loteProfessores.professor);
    }
}