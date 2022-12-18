#include "instr.h"

#define INSTR(name, opcode, size) \
  case opcode : return size; break;
Int get_size(Int opcode) 
{
  switch (opcode) {
    #include "instr.def"
    default: return 0; break;
  }
}
#undef INSTR