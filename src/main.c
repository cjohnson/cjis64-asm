#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "instruction.h"

int main(void) {
  char source[] = "addr    r0    r0    r1";

  instruction inst;

  char *opcode_buffer = strtok(source, " \t");
  if (opcode_buffer == NULL) {
    fprintf(stderr, "Failed to read opcode from assembly instruction! Exiting...\n");
    return EXIT_FAILURE;
  }
  if (!strcmp(opcode_buffer, "addr")) {
    inst.opcode = ADDR;
  } else {
    fprintf(stderr, "Unrecognized opcode: '%s'. Exiting...\n", opcode_buffer);
    return EXIT_FAILURE;
  }
  printf("Read opcode 0x%lx from '%s'\n", inst.opcode, opcode_buffer);

  char *result_register_buffer = strtok(NULL, " \t");
  if (result_register_buffer == NULL) {
    fprintf(stderr, "Failed to read result register from assembly instruction! Exiting...\n");
    return EXIT_FAILURE;
  }
  if (*result_register_buffer != 'r') {
    fprintf(stderr, "Unrecognized register declaration: '%s'. Exiting...\n", result_register_buffer);
    return EXIT_FAILURE;
  }
  inst.field_0 = atoi(result_register_buffer + 1);
  printf("Read result register id 0x%lx from '%s'\n", inst.field_0, result_register_buffer);

  char *data_register_1_buffer = strtok(NULL, " \t");
  if (data_register_1_buffer == NULL) {
    fprintf(stderr, "Failed to read data register 1 from assembly instruction! Exiting...\n");
    return EXIT_FAILURE;
  }
  if (*data_register_1_buffer != 'r') {
    fprintf(stderr, "Unrecognized register declaration: '%s'. Exiting...\n", data_register_1_buffer);
    return EXIT_FAILURE;
  }
  inst.field_1 = atoi(data_register_1_buffer + 1);
  printf("Read data register 1 id 0x%lx from '%s'\n", inst.field_1, data_register_1_buffer);

  char *data_register_2_buffer = strtok(NULL, " \t");
  if (data_register_2_buffer == NULL) {
    fprintf(stderr, "Failed to read data register 2 from assembly instruction! Exiting...\n");
    return EXIT_FAILURE;
  }
  if (*data_register_1_buffer != 'r') {
    fprintf(stderr, "Unrecognized register declaration: '%s'. Exiting...\n", data_register_2_buffer);
    return EXIT_FAILURE;
  }
  inst.field_2 = atoi(data_register_2_buffer + 1);
  printf("Read data register 2 id 0x%lx from '%s'\n", inst.field_2, data_register_2_buffer);
}
