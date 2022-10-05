// Luiz Henrique Parolim Domingues - 21248,
// Matheus Henrique De Oliveira Freire - 21251.

// Projeto 1 - T�picos em Orienta��o a objetos;
// Linguagem C;
// Projeto de solu��o de sistemas lineares
// A partir do m�todo de Gauss-Seidel.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
  FILE *arq;
  char Linha[100];
  int result, ordem,i ,j;
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("matriz.txt", "r");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  fscanf(arq, "%d", &ordem);

  int matriz[ordem][ordem];
printf("%d \n", ordem);

  for( i = 0; i < ordem; i++)
  {
      for( j = 1; j != ordem; j++)
      {
          fscanf(arq, "%d ", &matriz[i][j]);
          fscanf(arq, "\n");
      }
    fscanf(arq, "\n");
  }

  for( i = 0; i < ordem; i++)
  {
      for( j = 1; j < ordem; j++)
      {
          printf("%d ", matriz[i][j]);
      }
    printf("\n");
  }



  /*while (!feof(arq))  // enquanto não é fim de arquivo
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      printf(result);
  }*/
  fclose(arq);
}
