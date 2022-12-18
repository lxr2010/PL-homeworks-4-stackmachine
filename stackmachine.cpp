#include "stackmachine.h"
#include <algorithm>
#include <iostream>
#include <cassert>


Operand vm::run(void)
{
  bool terminated = false;
  Int next_pc;
#define OP1 code[pc+1]
#define OP2 code[pc+2]
  while (!terminated) {
    next_pc = pc + get_size(code[pc]);
    switch (code[pc]) {
      case Cst:
        push(OP1);
        break;
      case Add:
        push(pop() + pop());
        break;
      case Mul:
        push(pop() * pop());
        break;
      case Var:
        assert(sp >= OP1);
        push(stack[sp-OP1]);
        break;
      case Pop:
        pop();
        break;
      case Swap:
        {
          assert(sp-1 >= 0);
          std::swap(stack[sp],stack[sp-1]);
        }
        break;
      case Call:
        {
          stack.insert(stack.end()-OP2, next_pc);
          sp++;
          next_pc = OP1;
        }
        break;
      case Ret:
        {
          Operand retval = pop();
          sp -= OP1;
          stack.erase(stack.end()-OP1,stack.end());
          next_pc = pop();
          push(retval);
        }
        break;
      case IfZero:
        {
          Operand a = pop();
          if (!a) next_pc = OP1;
        }
        break;
      case Goto:
        {
          next_pc = OP1;
        }
        break;
      case Exit:
        terminated = true;
        break;
      default:
        terminated = true;
        break;
    }
    pc = next_pc;
  }
  return pop();
}

void vm::dump(void)
{
  std::cout << "dump..." << std::endl;

  std::cout << "code : ";  
  for (auto e : code) std::cout << e << " ";
  std::cout << std::endl;

  std::cout << "stack : ";
  for (auto e : stack) std::cout << e << " ";
  std::cout << std::endl;

  std::cout << "pc : ";
  std::cout << pc << std::endl;
  std::cout << "sp : ";
  std::cout << sp << std::endl;

}