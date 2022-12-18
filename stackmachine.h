#ifndef STACKMACHINE_H
#define STACKMACHINE_H
#include "instr.h"
#include <vector>
#include <cassert>

typedef Int Operand ;

class vm {
public:
  std::vector<Int> code;
  std::vector<Operand> stack;
  Int pc;
  Int sp;

  vm(const std::vector<Int> & code_, const std::vector<Operand> & stack_,
    Int init_pc):code(code_),stack(stack_),pc(init_pc),sp(-1) {}

  void dump();

  void push(Operand op) {stack.push_back(op);sp++;}
  Operand pop(void) {assert(sp >= 0);sp--; Operand retval = stack.back(); stack.pop_back(); return retval;}

  Operand run(void);
  
  #define INSTR(name, opcode, size) \
    name = opcode ,
  enum {
    #include "instr.def"
    OPNUM
  };
  #undef INSTR
};


#endif // STACKMACHINE_H