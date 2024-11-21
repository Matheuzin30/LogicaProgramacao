#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
  char nome[60];
  int tentativas;
} jogador;

void instrucoes()
{
  printf("\n-- Instrucoes do jogo --\n");
  printf("1. O computador escolhe um numero aleatorio de 1 a 100\n");
  printf("2 . O jogador deve tentar acertar o numero\n");
  printf("3. A cada tentativa, o computador informara se o numero eh maior ou menor.\n");
  printf("4. O jogo termina quando o jogador adivinha o numero ou decide sair.\n");
  printf("5. O jogador pode sair a qualquer momento escolhendo a opcao 'Sair' no menu.\n\n");
}

void exibirmenu(jogador jogador)
{
  int opcao;

  while (1)
  {
    printf("\n-- Menu do Jogo--\n");
    printf("1. Iniciar jogo\n");
    printf("2. Ver instrucoes\n");
    printf("3. Sair do jogo\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      iniciarjogo(jogador);
      break;
    case 2:
      instrucoes();
      break;
    case 3:
      printf("Saindo do jogo...");
      return;
    default:
      printf("Opcao invalida! Digite novamente");
    }
  }
}

void iniciarjogo(jogador jogador)
{
  int numerosorteado, palpite = 0;
  numerosorteado = rand() % 100 + 1;
  jogador.tentativas = 0;

  printf("\nAdvinhe um numero de 1 a 100");

  while (1)
  {
    printf("\nDigite um numero:");
    scanf("%d", &palpite);
    jogador.tentativas++;

    if (palpite == numerosorteado)
    {
      printf("Parabens %s, voce acertou em %d tentativas!", jogador.nome, jogador.tentativas);
      break;
    }
    else if (palpite < numerosorteado)
    {
      printf("Digite um numero maior\n");
    }
    else
    {
      printf("Digite um numero menor\n");
    }
  }
}

int main()
{
  srand(time(NULL));
  jogador jogador;

  printf("Digite seu nome para comecarmos:");
  fgets(jogador.nome, sizeof(jogador.nome), stdin);

  exibirmenu(jogador);
}