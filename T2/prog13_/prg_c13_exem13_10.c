#include <stdio.h>
int main(void) {
  char nome[31];
  int seq;
  double n1, n2, media;
  FILE *arq = fopen("alunos.txt", "r");
  nome[30] = '\0';
  while (fscanf(arq, "%d %30c%lf%lf\n", &seq, nome, &n1, &n2) != EOF)
  {
    media = (n1 + n2) / 2.0;
    if (media >= 7.0) {
      printf("%2d %30s %5.2f %5.2f %5.2f\n", seq, nome, n1, n2, media);
    }
  }
  fclose(arq);
  return 0;
}
