#include <stdio.h>

int main()
{
 char url[]="matriz.txt",
      ch1, ch2, ch3;
 FILE *arq;

 arq = fopen("matriz.txt", "r");

 if(arq == NULL)
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
  while( (fscanf(arq,"%c %c %c\n", &ch1, &ch2, &ch3))!=EOF )
   printf("%c %c %c\n", ch1, ch2, ch3);

 fclose(arq);

 return 0;
}
