#include "stackmachine.h"


Operand vm::run(void)
{
  bool terminated = false;
  while (!terminated) {
    switch (code[pc]) {
      default:
        terminated = true;
        break;
    }
  }
}

