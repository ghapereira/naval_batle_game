/*
        Implementacao em C do jogo Batalha Naval
        ArtPhil © 2017
*/
#include "source.h"
#include "game.h"
#include "messages.h"

#define __DEBUG_MODE__

#ifdef __DEBUG_MODE__
#include "tests.h"
#endif // __DEBUG_MODE__


// Identifica qual sistema esta sendo usado (Linux/Windows/OSX)
void sistema();

// Executa o loop principal do menu
void loop_menu_jogo();

void seleciona_linguagem();

void executa_jogo();

int trata_opcao(int opcao);

int main ()
{
        srand(time(NULL));

        set_language ("pt-br");
        sistema();
	
#ifdef __DEBUG_MODE__
	Parametros_Teste p;
	testa_jogo(parametros_teste);	
#else
	loop_menu_jogo();
#endif // __DEBUG_MODE__

        free_textos ();

        return 0;
}

void loop_menu_jogo()
{
        int     continuar = 0,
                opcao;

        while (continuar == 0)
        {
                print_banner(10);
                // 1. Jogar / 2. lingua / 3. Sair
                printf("\n %s\n\n %s\n\n %s\n\n", \
                txt_default.txt[12], txt_default.txt[13], txt_default.txt[14]);
                while ((opcao = read_char('1','3')) < 0)
                {
                        printf("%s\n%s\n", txt_falhas.txt[1], txt_falhas.txt[0]);
                }

		trata_opcao(opcao);
	}
}

int trata_opcao(int opcao)
{
	const int continuar = 1,
		  nao_continuar = 0;

	switch (opcao) {
		case 0:
			executa_jogo();
			return nao_continuar;
		case 1:
			seleciona_linguagem();
			return nao_continuar;
		case 2:
			return continuar;
			break;
		default:
			// panic
			exit(1);
	}
}

void executa_jogo()
{
	int continuar = 0;

	game();

	// Deseja jogar novamente?
	printf("%s\n %s\n %s\n", \
	txt_perguntas.txt[0], txt_default.txt[6], txt_default.txt[7]);

	while ((continuar = read_char('1','2')) < 0)
	{
		printf("%s\n%s\n", txt_falhas.txt[1], txt_falhas.txt[0]);
	}
}

void seleciona_linguagem()
{
	int opcao;

	// 1. Portugues / 2. English
	printf("\n %s\n %s\n", txt_default.txt[15], txt_default.txt[16]);
	while ((opcao = read_char('1','2')) < 0)
	{
		printf("%s\n%s\n", txt_falhas.txt[1], txt_falhas.txt[0]);
	}

	if (opcao == 0) set_language ("pt-br");
	if (opcao == 1) set_language ("en");
}

void sistema()
{
        // código para windows
        #if defined(WINDOWS)
        limpa_tela = "cls";
        // código para linux
        #elif defined(LINUX)
        limpa_tela = "clear";
        // código para OS X.
        #elif defined(OSX)
        limpa_tela = "clear";
        #endif
}

void limpa_stdin()
{
        setbuf(stdin, 0);
}
