#ifndef CJIS64_ASM_INSTRUCTION_H_
#define CJIS64_ASM_INSTRUCTION_H_

#include <stdint.h>

#define ADDR 0

struct instruction {
  uint64_t opcode;

  uint64_t field_0;
  uint64_t field_1;
  uint64_t field_2;
};
typedef struct instruction instruction;

#endif // CJIS64_ASM_INSTRUCTION_H_
