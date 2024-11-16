#include "src.h"

void analyseAnswer(int sum, int answer) {
  printf("The answer is: %i\n", answer);
  printf("Total sum = %i\n", sum);
  if (sum == answer) {
    printf("Corret!\n");
  } else {
    printf("Wrong!\n");
  }
}

void fileExist(FILE *file) {
  if (file == NULL) {
    printf("Error on open file\n");
    exit(EXIT_FAILURE);
  } else {
    printf("Open file\n");
  }
}

int getInteger(char *str) {
  int number;
  char first_num, last_num;
  char str_num[2];
  char *ptr;
  unsigned int len;
  int i;

  len = strlen(str);
  len--; // minus '\n'

  /* Gets the FIRST number */
  ptr = str;
  for (i = 0; i <= len; i++) {
    if (isdigit(*ptr)) {
      first_num = *ptr;
      break;
    }
    ptr++;
  }

  /* Gets the LAST number */
  ptr = &str[len];
  for (i = len; i >= 2; i--) {
    if (isdigit(*ptr)) {
      last_num = *ptr;
      break;
    }
    ptr--;
  }
  str_num[0] = first_num;
  str_num[1] = last_num;
  sscanf(str_num, "%d", &number);
  return number;
}
