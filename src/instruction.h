#ifndef CJIS64_ASM_INSTRUCTION_H_
#define CJIS64_ASM_INSTRUCTION_H_

#include <stdint.h>

#define REGISTER_R0  (uint64_t)0
#define REGISTER_R1  (uint64_t)1
#define REGISTER_R2  (uint64_t)2
#define REGISTER_R3  (uint64_t)3
#define REGISTER_R4  (uint64_t)4
#define REGISTER_R5  (uint64_t)5
#define REGISTER_R6  (uint64_t)6
#define REGISTER_R7  (uint64_t)7
#define REGISTER_R8  (uint64_t)8
#define REGISTER_R9  (uint64_t)9
#define REGISTER_R10 (uint64_t)10
#define REGISTER_R11 (uint64_t)11
#define REGISTER_R12 (uint64_t)12
#define REGISTER_R13 (uint64_t)13
#define REGISTER_R14 (uint64_t)14
#define REGISTER_R15 (uint64_t)15
#define REGISTER_R16 (uint64_t)16
#define REGISTER_R17 (uint64_t)17
#define REGISTER_R18 (uint64_t)18
#define REGISTER_R19 (uint64_t)19
#define REGISTER_R20 (uint64_t)20
#define REGISTER_R21 (uint64_t)21
#define REGISTER_R22 (uint64_t)22
#define REGISTER_R23 (uint64_t)23
#define REGISTER_R24 (uint64_t)24
#define REGISTER_R25 (uint64_t)25
#define REGISTER_R26 (uint64_t)26
#define REGISTER_R27 (uint64_t)27
#define REGISTER_R28 (uint64_t)28
#define REGISTER_R29 (uint64_t)29
#define REGISTER_R30 (uint64_t)30
#define REGISTER_R31 (uint64_t)31
#define REGISTER_RZR (uint64_t)32

#define ADDR 0
#define SUBR 1

struct instruction {
  uint64_t opcode;

  uint64_t field_0;
  uint64_t field_1;
  uint64_t field_2;
};
typedef struct instruction instruction;

#endif // CJIS64_ASM_INSTRUCTION_H_
