#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "instruction.h"

int parse_register(const char *register_buffer, uint64_t *register_code) {
  if (register_buffer == NULL) {
    fprintf(stderr, "Register name buffer was null.\n");
    assert(!"Register name buffer was null.");
    return 0;
  }

  if (register_code == NULL) {
    fprintf(stderr, "Register code write buffer was null.\n");
    assert(!"Register code write buffer was null.\n");
    return 0;
  }

  int len = strlen(register_buffer);
  if (len < 2 || len > 3) {
    fprintf(stderr, "Unrecognized register: '%s'.\n", register_buffer);
    assert(!"Unrecognized register.\n");
    return 0;
  }

  if (*register_buffer != 'r') {
    fprintf(stderr, "Unrecognized register: '%s'.\n", register_buffer);
    assert(!"Unrecognized register.\n");
    return 0;
  }

  const char *register_identifier = register_buffer + 1;

  if (!strcmp(register_identifier, "zr")) {
    *register_code = REGISTER_RZR;
    return 1;
  }

  char *read_end;
  uint64_t parsed_register_number = strtoul(register_identifier, &read_end, 10);
  if (read_end == register_identifier) {
    fprintf(stderr, "Failed to parse register: '%s'\n", register_buffer);
    return 0;
  }

  if (parsed_register_number > REGISTER_R31) {
    fprintf(stderr, "Unrecognized register: '%s'\n", register_buffer);
    return 0;
  }

  *register_code = parsed_register_number;
  return 1;
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
  if (!strcmp(opcode_name_buffer, "subr")) {
    *opcode = SUBR;
    return 1;
  }

  fprintf(stderr, "Unrecognized opcode: '%s'\n", opcode_name_buffer);
  return 0;
}

int main(void) {
  char source[] = "subr    r0    r0    r1";

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
