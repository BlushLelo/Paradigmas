cmake_minimum_required(VERSION 3.13)
project(Paradigmas C)

set(CMAKE_C_STANDARD 99)

add_executable(Paradigmas main.c aluno.h aluno.c menu.h menu.c disciplina.h disciplina.c professor.c professor.h matricula.c matricula.h constants.h)