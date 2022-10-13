// Luiz Henrique Parolim Domingues - 21248,
// Matheus Henrique De Oliveira Freire - 21251.

// Projeto 1 - T�picos em Orienta��o a objetos;
// Linguagem C;
// Projeto de solu��o de sistemas lineares
// A partir do m�todo de Gauss-Seidel.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef
enum{
    false,
    true
}
boolean;


void trocarLinhasDeLugar(int ordem, double matriz[ordem][ordem], double resultados[ordem]){
    int i, j;

    for(i = 0; i != ordem; i++)
 {
    if(matriz[i][i] == 0)
    {
        int contLinhas = 0; //contador quantas vezes as linhas foram trocadas

            int aux, aux2;

                if(i != ordem -1)
                {
                    for(j = 0; contLinhas < ordem; j++)
                    {
                        aux = matriz[i][j];
                        aux2 = resultados[i];

                        matriz[i][j]= matriz[i+1][j];
                        resultados[i]= resultados[i+1];

                        matriz[i+1][j]= aux;
                        resultados[i+1] = aux2;

                        contLinhas++;
                    }

                }

                else
                {
                    for(j = 0; contLinhas < ordem; j++)
                    {
                        aux = matriz[i][j];
                        aux2 = resultados[i];

                        matriz[i][j]= matriz[i-1][j];
                        resultados[i]= resultados[i-1];

                        matriz[i-1][j]= aux;
                        resultados[i-1] = aux2;

                        contLinhas++;

                    }
                }

    }
        if(matriz[i][i] == 0)
                    {
                        printf("Não é possivel resolver o sistema!");
                        break;
                    }
    }
}

void testePrint(int ordem, double matriz[ordem][ordem])
{
    for(int i = 0; i != ordem; i++)
    {
        for(int j = 0; j != ordem; j++)
        {
            printf("%lf ", matriz[i][j]);
        }
        printf("\n");
    }

}

boolean verificarPossibilidadeDeSolucao(int ordem, double matriz[ordem][ordem]){
    int i, j;

    double linha[ordem];
  double resultadoDivisao[ordem], resultAnt[ordem];; // vetor para armazenar resultados
  boolean ehAplicavel = true, valoresIguals[ordem];


  for (i = 0; i < ordem-1; i++) // repeticao para fazer pares de linhas com execao da ultima
         {
            for ( j = 0; j != ordem; j++)
            {
                    linha[j] = matriz[i][j]; // vetor está recebendo o valor da linha que está percorrendo
            }


        for(int linhaSeguinte = i+1; linhaSeguinte != ordem; linhaSeguinte++) // repeticao para dividir os pares de linhas
        {
              for (j = 0; j != ordem; j++)
            {

                    resultadoDivisao[j] = linha[j] / matriz[linhaSeguinte][j];
                    // resultadoDivisao recebe a divisão de linha pela linha debaixo
            }



            if(linhaSeguinte != i+1)
            {
                for(int h = 0; h != ordem-1; h++)
                {
                    if(resultadoDivisao[h] == resultAnt[h])
                        valoresIguals[h] == true;
                }



            int qtsIguais = 0;
            for(int h = 0; h != ordem; h++)
            {
                if(valoresIguals[h] == true)
                    qtsIguais++;

                    if(qtsIguais == ordem)
                        ehAplicavel = false;
            }

            }
            for(int k = 0; k != ordem; k++)
            {
                resultAnt[k] = resultadoDivisao[k];
            }

            if(ehAplicavel == false)
                return false;

        }

         }
         return true;
}

void main()

{
  FILE *arq;
  char Linha[100];
  int result, ordem,i ,j;
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("matriz3.txt", "r");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  fscanf(arq, "%d", &ordem);

  double matriz[ordem][ordem];
  double resultados[ordem];


  for( i = 0; i != ordem; i++)
  {



      for( j = 0; j != ordem; j++)
      {
          fscanf(arq, "%lf ", &matriz[i][j]);

      }

      fscanf(arq, "%lf ", &resultados[i]);

  }

  fclose(arq);

  testePrint(ordem, matriz);
      // verificar pares
      // verificamos linha com linha
      // primeiro a linha 1 com as demais linhas: 2, 3, 4...
      // após isso a linha 2 com as demais linhas: 3, 4...



  ///////////////////////////////////////////////////////////
 if(verificarPossibilidadeDeSolucao(ordem, matriz))
    printf("E possivel resolver.");
 else
    printf("Não e possivel resolver.");

 ////////////////////////////////////////////////////////////

 trocarLinhasDeLugar(ordem, matriz, resultados);
}
