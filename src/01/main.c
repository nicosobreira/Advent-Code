#include "src.h"
#include <stdio.h>

int main(void) {
  char *file_name;
  FILE *input;
  char line[128];
  int sum = 0;
  file_name = "./input.txt";
  input = fopen(file_name, "r");
  fileExist(input);

  while (fgets(line, sizeof(line), input)) {
    sum += getInteger(line);
  }
  analyseAnswer(sum, 56049);
  return 0;
}
