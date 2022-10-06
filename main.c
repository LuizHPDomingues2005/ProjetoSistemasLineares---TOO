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

  double matriz[ordem][ordem];
  double resultados[ordem];


  for( i = 0; i < ordem; i++)
  {

      for( j = 0; j != ordem; j++)
      {
          fscanf(arq, "%lf ", &matriz[i][j]);

      }

      fscanf(arq, "%lf ", &resultados[i]);
      /*fseek(arq, ordem, SEEK_CUR);*/

  }


      // verificar pares
      // verificamos linha com linha
      // primeiro a linha 1 com as demais linhas: 2, 3, 4...
      // após isso a linha 2 com as demais linhas: 3, 4...

  int qtsLinhasALer = ordem;
  for( i = 0; i < ordem; i++)
  {
      for( j = 0; j < (ordem+1); j++)
      {
          double numLinhaAtual = matriz[i][j];
          double numProximaLinha = matriz[(i+1)][j];

          double divisaoResultado = numLinhaAtual / numProximaLinha;

          printf("%lf ", divisaoResultado);
      }
  qtsLinhasALer = qtsLinhasALer - 1;
  }

  fclose(arq);
}
