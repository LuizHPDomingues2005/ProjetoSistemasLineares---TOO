#include <stdio.h>
#include <string.h>

int i,j,k,ordem;
float matriz[20][20],c,x[10],soma=0.0;
    
    int ehAplicavel() // testar se e possivel resolver o sistema dividindo a linha por                     outra linha
    {
         float divisaoLinhas[ordem];
         float resultadoDivisao[ordem];
         memset(divisaoLinhas, 0, sizeof(divisaoLinhas));
         memset(resultadoDivisao, 0, sizeof(resultadoDivisao));
         for (int linha = 1; linha <= ordem; linha++) 
         {
            for (int coluna = 1; coluna <= ordem+1; coluna++) 
            {
                divisaoLinhas[coluna] = matriz[linha][coluna];
            }
            
              for (int coluna = 1; coluna <= ordem; coluna++) 
            {
                if( divisaoLinhas[coluna] > matriz[linha+1][coluna])
                    resultadoDivisao[coluna] = divisaoLinhas[coluna] / matriz[linha+1][coluna];
                    
                if( divisaoLinhas[coluna] < matriz[linha+1][coluna])
                     resultadoDivisao[coluna] = matriz[linha+1][coluna] /  divisaoLinhas[coluna];
                     
               if( divisaoLinhas[coluna] == matriz[linha+1][coluna])
                     resultadoDivisao[coluna] = divisaoLinhas[coluna] / matriz[linha+1][coluna];
                     
            }
        
        int elementoVetor;
        int primeiroAcesso = 1;
        int elementosIgual = 1;
      
       for (i = 1; i <= ordem; i++) 
       {
           if(primeiroAcesso == 1)
           {
               elementoVetor = resultadoDivisao[i];
               primeiroAcesso = 0;
           }
           else
           {
               if( elementoVetor ==  resultadoDivisao[i])
               {
                     elementosIgual++;
                     printf("a");
               }
                else
                    return 1;
           }
        }
        if(elementosIgual == ordem)
            return 0; // se a quantidade de elementos do vetor são iguais ao tamanho da            linha todos são iguais
        }
    }
    
     void trocarLinhas(int contLinhas) // trocar linhas da matriz
    {
       int aux;
       for(j = 0; j <= ordem+1; j++)
       {
           aux = matriz[contLinhas][j];
           matriz[contLinhas][j]= matriz[contLinhas+1][j];
           matriz[contLinhas+1][j]= aux;
       }
       
    }
int main() {
  
    printf("\nEscreva a ordem da matriz: ");
    scanf("%d", &ordem);
    fflush(stdin);
    printf("\nEscreva os elementos da matriz aumentada:\n\n");
    for(i=1;i<=ordem;i++)
    {
        for(j=1;j<=(ordem+1);j++)
        {
            printf("matriz[%d][%d] : ", i,j);
            scanf("%f",&matriz[i][j]);
            fflush(stdin);
        }
    }
    
    if(ehAplicavel() == 0)
    {
        printf("Não é possivel resolver o sistema!");
        return 0;
    }
    
    if(matriz[1][1] == 0)
    {
        int contLinhas = 1; //contador de linhas para trocar as linhas de lugares para tirar o zero da diagonal
        while(contLinhas < ordem && matriz[1][1]==0)
        {
             trocarLinhas(contLinhas);
             contLinhas++;
        }
        if(matriz[1][1]== 0) // teste
        {
             printf("Não é possivel resolver o sistema!");
            return 0;
        }
    }

    for(j=1;j<=(ordem+1);j++)
    {
        for(i=1;i<=ordem;i++)
        {
            if(i>j)
            {
                c=-(matriz[i][j]/matriz[j][j]);
                for(k=1;k<=ordem+1;k++)
                {
                    matriz[i][k]=c*matriz[j][k]+matriz[i][k];
                }
            }
        }
    }
    
    
    for(i=1;i<=ordem;i++)
    {
        for(j=1;j<=ordem+1;j++)
        {
            if(j!=ordem+1)
            {
            printf("%0.2f   ", matriz[i][j]);
            }
            else
            {
                printf("%0.2f \n", matriz[i][j]);

            }
        }
    }


    x[ordem]=matriz[ordem][ordem+1]/matriz[ordem][ordem];

    for(i=ordem-1; i>=1; i--)
    {
        soma=0;
        for(j=i+1; j<=ordem;j++)
        {
            soma=soma+matriz[i][j]*x[j];
        }
        x[i]=(matriz[i][ordem+1]-soma)/matriz[i][i];
    }
    printf("\nA solucao eh: \n");
    for(i=1; i<=ordem;i++)
    {
        printf("\nx%d=%f\t",i,x[i]);
    }

    return (0);
}
