#include <stdio.h>

int main(void)
{
 char url[]="matriz.txt",
      ch1, ch2, ch3;
 FILE *arq;
 printf("%", url[]);

 arq = fopen(url, "r");

 if(arq == NULL)
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
  while( (fscanf(arq,"%c %c %c\n", &ch1, &ch2, &ch3))!=EOF )
   printf("%c %c %c\n", ch1, ch2, ch3);

 fclose(arq);

 return 0;
}
