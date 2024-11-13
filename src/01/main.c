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
  int num;
  char str_num[64] = "";

  printf("%s\n", str_num);
  for (char *ch = &string[0]; *ch != '\0'; ch++) {
    if (isdigit(*ch)) {
      appendChar(str_num, *ch);
    }
  }
  toInt(str_num, &num);
  return num;
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
