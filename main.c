#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"
#include "matricula.h"
#include "menu.h"

#define OPCAO_SAIR 16

void selector(int opcao, AlunoList *listaDeAlunos, DisciplinaList *listaDeDisciplinas,
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
    } while (opcao != OPCAO_SAIR);
    return 0;
}

void selector(int opcao, AlunoList *listaDeAlunos, DisciplinaList *listaDeDisciplinas,
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
            break;
        }
        case 6: {
            vincularProfessores(listaDeDisciplinas, listaDeProfessores);
            break;
        }
        case 7: {
            cancelarVinculoProfessores(listaDeDisciplinas, listaDeProfessores);
            break;
        }
        case 8: {
            menuPrintarTodosOsAlunos();
            printarAlunos(listaDeAlunos->next);
            break;
        }
        case 9: {
            menuPrintarTodasAsDisciplinas();
            printarDisciplinas(listaDeDisciplinas->next);
            break;
        }
        case 10: {
            menuPrintarTodosOsProfessores();
            printarProfessores(listaDeProfessores->next);
            break;
        }
        case 11: {
            menuPrintarTodasAsDisciplinasDeUmAluno();
            printarListaDeDisciplinasDeUmAluno(listaDeDisciplinas);
            break;
        }

        case 12: {
            printarListaDeAlunoEmUmaDisciplinaETurma(listaDeDisciplinas);
            break;
        }

        case 13: {
            printarListaDeAlunosEmUmaDisciplina(listaDeDisciplinas);
            break;
        }

        case 14: {
            printarTodasAsDisciplinasMinistradasPorUmProfessor(listaDeDisciplinas);
            break;
        }

        case 15: {
            printarProfessoresVinculadoADisciplinas(listaDeDisciplinas);
            break;
        }

        default: {
            if (opcao != OPCAO_SAIR) {
                printf("Opção inválida\n");
            }
        }
    }
}