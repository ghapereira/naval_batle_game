/*
        Implementacao em C do jogo Batalha Naval
        ArtPhil © 2017
*/
#ifndef _JOGO_
#define _JOGO_

#include "source.h"
#include "player.h"
#include "target.h"
#include "board.h"
#include "messages.h"

#ifdef __DEBUG_MODE__
typedef struct Parametros_Teste {
	int numero_jogadores;
	int dificuldade;
	int numero_turnos;
} Parametros_Teste;
#endif // __DEBUG_MODE__

/* Funcoes exportadas */

// Faz tosas as tarefas referentes a batalha
void game();

void limpa_stdin();

// Le uma sequencia de caracteres da tela
char* read_string (int tam);

// Le um caractere da tela em forma de char
int read_char (char inicio, char fim);

// Le um caractere da tela em forma de int
int read_int (int inicio, int fim);



#endif
