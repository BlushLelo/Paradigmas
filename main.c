#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"
#include "matricula.h"
#include "menu.h"

void selector(int opcao, ProfessorList *listaDeAlunos, DisciplinaList *listaDeDisciplinas,
              ProfessorList *listaDeProfessores);

int main() {
    /* Bloco para declarar nós para listas de entidades*/
    AlunoList *alunoList;
    DisciplinaList *disciplinaList;
    ProfessorList *professorList;
    /*---------------------------------*/

    /*Bloco para inicializar listas de entidades */
    createList(&alunoList);
    criarListaDeDisciplinas(&disciplinaList);
    criarListaDeProfessores(&professorList);
    /*---------------------------------*/
    int opcao;
    do {
        menuInicial();
        scanf("%d", &opcao);
        selector(opcao, alunoList, disciplinaList, professorList);
    } while (opcao != 7);
    return 0;
}

void selector(int opcao, ProfessorList *listaDeAlunos, DisciplinaList *listaDeDisciplinas,
              ProfessorList *listaDeProfessores) {
    switch (opcao) {
        case 1: {
            cadastrarAluno(listaDeAlunos);
            break;
        }
        case 2: {
            cadastrarDisciplina(listaDeDisciplinas);
            break;
        }
        case 3: {
            cadastrarProfessor(listaDeProfessores);
            break;
        }
        case 4 : {
            matricularAlunos(listaDeDisciplinas, listaDeAlunos);
            break;
        }
        case 5 : {
            cancelarMatricula(listaDeDisciplinas, listaDeAlunos);
        }
        default: {
            printf("Opção inválida\n Seleciona uma válida!.");
        }
    }
}