#include <ctype.h>
#include <stdio.h>
#include <string.h>

void toInt(char *str, int *num) { sscanf(str, "%d", num); }

void appendChar(char *str, char ch) {
  int len = strlen(str);

  str[len] = ch;

  str[len + 1] = '\0';
}

int getNum(char string[]) {
  int num[100];
  int tmp = 0;
  char str_num[64] = "";

  /*printf("%i\n", *pn);*/
  for (char *ch = &string[0]; *ch != '\0'; ch++) {
    if (isdigit(*ch)) {
      toInt(ch, &tmp);
      printf("&tmp = %i\n", tmp);
    }
  }
  printf("num = %i\n", *num);

  return 0;
  /*toInt(str_num, num);*/
  /*return num;*/
}

int main(void) {
  long int sum = 0;
  char text[1024];
  FILE *pfile = fopen("t-input.txt", "r");
  while (fgets(text, 1024, pfile)) {
    sum = getNum(text);
  }
  // Expect: 84
  printf("sum = %li\n", sum);
  fclose(pfile);
  return 0;
}
