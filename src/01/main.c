#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileExist(FILE *file) {
  if (file == NULL) {
    printf("Error on open file\n");
    exit(EXIT_FAILURE);
  } else {
    printf("Open file\n\n");
  }
}

int getInteger(char *str) {
  int number;
  char first_num;
  char last_num;
  char str_num[2];
  char *ptr;
  unsigned int len;
  int i;

  len = strlen(str);
  len -= 2; // minus '\n' and '\0'

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

int main(void) {
  char *file_name;
  FILE *input;
  char line[64];
  int sum = 0;
  file_name = "./input.txt";
  input = fopen(file_name, "r");
  fileExist(input);

  while (fgets(line, sizeof(line), input)) {
    sum += getInteger(line);
  }
  printf("Total sum = %i\n", sum);
  return 0;
}
