#define INSTR(name, opcode, size) 
#include "instr.def"
#undef INSTR



typedef int Int;

class Instr {
public:
  Int opcode;
  Int op1;
  Int op2;
  Int size;
};

#define INSTR(name, opcode, size) \
  class name : public Instr {};
#include "instr.def"
#undef INSTR



