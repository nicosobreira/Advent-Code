#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN(ptr) (sizeof(ptr) / sizeof(ptr[0]))

void fileExist(FILE *file) {
  if (file == NULL) {
    printf("Error on open file\n");
    exit(1);
  } else {
    printf("Open file\n\n");
  }
}

int getInteger(char *str) {
  char first_num;
  char last_num;
  char *ptr;
  int i;

  /* Gets the FIRST number */
  ptr = str;
  for (i = 0; i <= LEN(str); i++) {
    /*printf("%c\n", *ptr);*/
    if (isdigit(*ptr)) {
      first_num = *ptr;
      break;
    }
    ptr++;
  }
  /*printf("%c\n", first_num);*/

  /* Gets the LAST number */
  ptr = &str[LEN(str)];
  printf("%lo\n", sizeof(str));
  for (i = LEN(str); i >= 0; i--) {
    printf("%c\n", *ptr);
    if (isdigit(*ptr)) {
      last_num = *ptr;
      break;
    }
    ptr--;
  }
  printf("\n");
  /*printf("f = %c\tl = %c\n", first_num, last_num);*/
  return 0;
}

int main(void) {
  char *file_name;
  FILE *input;
  char line[64];
  int sum = 0;

  file_name = "./t-input.txt";
  input = fopen(file_name, "r");
  fileExist(input);
  while (fgets(line, sizeof(line), input)) {
    sum += getInteger(line);
  }
  return 0;
}
