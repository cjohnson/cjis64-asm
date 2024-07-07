#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "instruction.h"

int parse_register(const char *register_name_buffer, uint64_t *register_code) {
  if (register_name_buffer == NULL) {
    fprintf(stderr, "Register name buffer was null.\n");
    return 0;
  }

  if (!strcmp(register_name_buffer, "rzr")) {
    *register_code = 32;
    return 1;
  }

  if (*register_name_buffer == 'r') {
    const char *register_name_buffer_code_part = register_name_buffer + 1;
    char *end_pointer;

    uint64_t parsed_register_code = strtoul(register_name_buffer_code_part, &end_pointer, 10);
    if (register_name_buffer_code_part == end_pointer) {
      fprintf(stderr, "Unrecognized register name: '%s'\n", register_name_buffer);
      return 0;
    }

    if (parsed_register_code > 31) {
      fprintf(stderr, "Unrecognized register name: '%s'\n", register_name_buffer);
      return 0;
    }

    *register_code = parsed_register_code;
    return 1;
  }

  fprintf(stderr, "Unrecognized register name: '%s'\n", register_name_buffer);
  return 0;
}

int parse_opcode(const char *opcode_name_buffer, uint64_t *opcode) {
  if (opcode_name_buffer == NULL) {
    fprintf(stderr, "Opcode name buffer was null.\n");
    return 0;
  }

  if (!strcmp(opcode_name_buffer, "addr")) {
    *opcode = ADDR;
    return 1;
  }

  fprintf(stderr, "Unrecognized opcode: '%s'\n", opcode_name_buffer);
  return 0;
}

int main(void) {
  char source[] = "addr    r0    r0    r1";

  instruction inst;

  char *opcode_buffer = strtok(source, " \t");
  if (opcode_buffer == NULL || !parse_opcode(opcode_buffer, &inst.opcode)) {
    fprintf(stderr, "Failed to parse opcode!\n");
    return EXIT_FAILURE;
  }
  printf("Read opcode 0x%lx from '%s'\n", inst.opcode, opcode_buffer);

  char *result_register_buffer = strtok(NULL, " \t");
  if(result_register_buffer == NULL || !parse_register(result_register_buffer, &inst.field_0)) {
    fprintf(stderr, "Failed to parse result register!\n");
    return EXIT_FAILURE;
  }
  printf("Read result register id 0x%lx from '%s'\n", inst.field_0, result_register_buffer);

  char *data_register_1_buffer = strtok(NULL, " \t");
  if(data_register_1_buffer == NULL || !parse_register(data_register_1_buffer, &inst.field_1)) {
    fprintf(stderr, "Failed to parse register 1!\n");
    return EXIT_FAILURE;
  }
  printf("Read data register id 1 as 0x%lx from '%s'\n", inst.field_1, data_register_1_buffer);

  char *data_register_2_buffer = strtok(NULL, " \t");
  if(data_register_2_buffer == NULL || !parse_register(data_register_2_buffer, &inst.field_2)) {
    fprintf(stderr, "Failed to parse register 2!\n");
    return EXIT_FAILURE;
  }
  printf("Read data register id 2 as 0x%lx from '%s'\n", inst.field_2, data_register_2_buffer);
}
