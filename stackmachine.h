#include "instr.h"
#include <vector>

typedef Int Operand ;

class vm {
  std::vector<Int> code;
  std::vector<Operand> stack;
  Int pc;
  Int sp;

  vm(const std::vector<Int> & code_, const std::vector<Operand> & stack_,
    Int init_pc):code(code_),stack(stack_),pc(init_pc),sp(0) {}

  void push(Operand op) {stack.push_back(op);sp++;}
  Operand pop(void) {sp--; Operand retval = stack.back(); stack.pop_back(); return retval;}

  Operand run(void);
  
  #define INSTR(name, opcode, size) \
    name = opcode ,
  enum {
    #include "instr.def"
    OPNUM
  };
  #undef INSTR
};