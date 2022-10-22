
// Luiz Henrique Parolim Domingues - 21248,
// Matheus Henrique De Oliveira Freire - 21251.

// Projeto 1 - T�picos em Orienta��o a objetos;
// Linguagem C;
// Projeto de solu��o de sistemas lineares
// A partir do m�todo de Gauss-Seidel.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    false,
    true
} boolean;

boolean trocarLinhasDeLugar(int ordem, double matriz[ordem][ordem], double resultados[ordem])
{
    int i, j;

    for (i = 0; i != ordem; i++)
    {
        if (matriz[i][i] == 0)
        {
            int contLinhas = 0; // contador quantas vezes as linhas foram trocadas

            int aux, aux2;

            if (i != ordem - 1)
            {
                for (j = 0; contLinhas < ordem; j++) // ao trocar as linhas da matriz, troca junto as dos resultados
                {
                    aux = matriz[i][j];
                    aux2 = resultados[i];

                    matriz[i][j] = matriz[i + 1][j];
                    resultados[i] = resultados[i + 1];

                    matriz[i + 1][j] = aux;
                    resultados[i + 1] = aux2;

                    contLinhas++;
                }
            }

            else
            {
                for (j = 0; contLinhas < ordem; j++)
                {
                    aux = matriz[i][j];
                    aux2 = resultados[i];

                    matriz[i][j] = matriz[i - 1][j];
                    resultados[i] = resultados[i - 1];

                    matriz[i - 1][j] = aux;
                    resultados[i - 1] = aux2;

                    contLinhas++;
                }
            }
        }
        if (matriz[i][i] == 0)
        {
            return false;
        }
    }
    return true;
}

boolean trocarLinhasEspecificasDeLugar(int ordem, double matriz[ordem][ordem], double resultados[ordem], int linha)
{
    int i, j;

    for (i = 0; i != ordem; i++)
    {
        if (matriz[i][i] == 0 && i != linha)
        {
            int contLinhas = 0; // contador quantas vezes as linhas foram trocadas

            int aux, aux2;

            if (i != ordem - 1)
            {
                for (j = 0; contLinhas < ordem; j++) // ao trocar as linhas da matriz, troca junto as dos resultados
                {
                    aux = matriz[i][j];
                    aux2 = resultados[i];

                    matriz[i][j] = matriz[i + 1][j];
                    resultados[i] = resultados[i + 1];

                    matriz[i + 1][j] = aux;
                    resultados[i + 1] = aux2;

                    contLinhas++;
                }
            }

            else
            {
                for (j = 0; contLinhas < ordem; j++)
                {
                    aux = matriz[i][j];
                    aux2 = resultados[i];

                    matriz[i][j] = matriz[i - 1][j];
                    resultados[i] = resultados[i - 1];

                    matriz[i - 1][j] = aux;
                    resultados[i - 1] = aux2;

                    contLinhas++;
                }
            }
        }
        if (matriz[i][i] == 0)
        {
            return false;
        }
    }
    return true;
}

void printeAMatriz(int ordem, double matriz[ordem][ordem], double resultados[ordem])
{
    for (int i = 0; i != ordem; i++)
    {
        for (int j = 0; j <= ordem; j++)
        {
            if (j == ordem)
            {
                printf("= ");
                printf("%0.2lf", resultados[i]);
            }
            else
                printf("%0.2lf ", matriz[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}

boolean verificarPossibilidadeDeSolucao(int ordem, double matriz[ordem][ordem])
{
    int i, j;

    double linha[ordem];
    double resultadoDivisao[ordem], resultAnt[ordem];
    // vetor para armazenar resultados
    boolean ehAplicavel = true, valoresIguals[ordem];

    memset(valoresIguals, false, sizeof(valoresIguals)); // vetor que armazena quantos valores iguais
    memset(resultadoDivisao, 0, sizeof(resultadoDivisao));
    memset(resultAnt, 0, sizeof(resultAnt));
    memset(linha, 0, sizeof(linha));

    for (i = 0; i < ordem - 1; i++) // repeticao para fazer pares de linhas com execao da ultima
    {
        for (j = 0; j != ordem; j++)
        {
            linha[j] = matriz[i][j]; // vetor está recebendo o valor da linha que está percorrendo
        }

        for (int linhaSeguinte = i + 1; linhaSeguinte != ordem; linhaSeguinte++) // repeticao para dividir os pares de linhas
        {
            for (j = 0; j != ordem; j++)
            {

                resultadoDivisao[j] = linha[j] / matriz[linhaSeguinte][j];
                // resultadoDivisao recebe a divisão de linha pela linha debaixo
            }

            if (linhaSeguinte != i + 1) // se e diferente do comeco do contador linhaSeguinte
            {
                for (int h = 0; h != ordem; h++)
                {
                    if (resultadoDivisao[h] == resultAnt[h])
                        valoresIguals[h] = true;
                }

                int qtsIguais = 0;
                for (int h = 0; h != ordem; h++)
                {
                    if (valoresIguals[h] == true)
                        qtsIguais++;

                    if (qtsIguais == ordem)
                        ehAplicavel = false; // se todas as posicoes do vetor forem verdadeiras, significa que a matriz nao e aplicavel
                }
            }
            for (int k = 0; k != ordem; k++)
            {
                resultAnt[k] = resultadoDivisao[k];
            }

            if (ehAplicavel == false)
                return false;
        }
    }
    return true;
}

void main()
{
    FILE *arq;
    char Linha[100];
    int result, ordem, i, j;

    for (;;)
    {

        do
        {
            char nomeArq[50];
            memset(nomeArq, '0', sizeof(nomeArq));

            printf("\n\nDigite o nome do arquivo a ser lido. Ex: matriz.txt\n");
            printf("Para sair digite 0\n\n");

            scanf("%s", nomeArq);
            printf("\n");

            if (nomeArq[0] == '0')
                return 0;

            fflush(stdin);

            // Abre um arquivo TEXTO para LEITURA
            arq = fopen(nomeArq, "r");
            if (arq == NULL) // Se houve erro na abertura
            {
                printf("Problemas na abertura do arquivo\n");
            }
        } while (arq == NULL);

        fscanf(arq, "%d", &ordem);

        double matriz[ordem][ordem];
        double resultados[ordem];

        for (i = 0; i != ordem; i++)
        {
            for (j = 0; j != ordem; j++)
            {
                fscanf(arq, "%lf ", &matriz[i][j]);
            }

            fscanf(arq, "%lf ", &resultados[i]);
        }

        fclose(arq);

        printeAMatriz(ordem, matriz, resultados);
        // verificar pares
        // verificamos linha com linha
        // primeiro a linha 1 com as demais linhas: 2, 3, 4...
        // após isso a linha 2 com as demais linhas: 3, 4...

        ///////////////////////////////////////////////////////////
        if (!verificarPossibilidadeDeSolucao(ordem, matriz))
            printf("Nao e possivel resolver.");
        else
        {

            ////////////////////////////////////////////////////////////
            if (trocarLinhasDeLugar(ordem, matriz, resultados))
            {

                // declração das variáveis que serão usadas para resolver o sistema
                boolean ehPossivel = true;
                double linhaMatriz[ordem];
                memset(linhaMatriz, 0, sizeof(linhaMatriz));
                double resultadoAnt;
                j = 0;
                i = 0;
                int colunaAtual = 0;

                // solução da matriz
                while (i != ordem && ehPossivel == true)
                {
                    double valorDiagonal;

                    for (j = 0; j != ordem; j++)
                    {
                        if (i == j && matriz[i][j] != 1)
                        {
                            if (matriz[i][j] == 0)
                            {
                                if (trocarLinhasEspecificasDeLugar(ordem, matriz, resultados, i) == false)
                                {
                                    ehPossivel = false;
                                    break;
                                }
                            }

                            valorDiagonal = matriz[i][j];

                            for (j = 0; j <= ordem; j++) // percorre as colunas da matriz
                            {
                                if (j == ordem)
                                {
                                    resultados[i] = resultados[i] / valorDiagonal;
                                    resultadoAnt = resultados[i];
                                }
                                else
                                {
                                    matriz[i][j] = matriz[i][j] / valorDiagonal;
                                    // divide a posição atual pelo valor da diagonal

                                    linhaMatriz[j] = matriz[i][j];
                                }
                            }
                            break;
                        }
                    }

                    for (int seqLinha = 0; seqLinha != ordem; seqLinha++)
                    {
                        double valor;

                        if (seqLinha != colunaAtual && matriz[seqLinha][colunaAtual] != 0)
                        {
                            valor = (-matriz[seqLinha][colunaAtual]);
                            for (int coluna = 0; coluna <= ordem; coluna++) // percorre as colunas da matriz
                            {
                                if (coluna == ordem)
                                {
                                    resultados[seqLinha] = (resultadoAnt * valor) + resultados[seqLinha];
                                }
                                else
                                {
                                    matriz[seqLinha][coluna] = (linhaMatriz[coluna] * valor) + matriz[seqLinha][coluna];
                                }
                            }
                        }
                    }
                    colunaAtual++;
                    i++; // incrementador de linha da
                }

                for (i = 0; i != ordem; i++)
                    for (i = 0; i != ordem; i++)
                        for (j = 0; j != ordem; j++)
                            if (i != j)
                                if (matriz[i][j] != 0)
                                    ehPossivel = false;

                if (ehPossivel != false)
                {
                    boolean ehSpi = false;
                    for (i = 0; i != ordem; i++)
                        if (matriz[i][i] == 0)
                            ehSpi = true;

                    if (ehSpi == false)
                    {
                        printeAMatriz(ordem, matriz, resultados);

                        int contX = 1;
                        for (i = 0; i != ordem; i++) // print dos resultados
                        {
                            printf("\nx%d = %0.2lf\t", contX, resultados[i]);
                            contX++;
                        }
                    }
                    else
                    {
                        printf("Sistema possivel inderteminado. Ha varias possiveis respostas.");
                    }
                }
                else
                    printf("Nao e possivel resolver o sistema!");
            }
        }
    }
}
