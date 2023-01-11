#include "stackmachine.h"
#include <iostream>

std::vector<Int> cst_test {vm::Cst,1,vm::Exit};
std::vector<Int> if_test {vm::Cst,0,vm::IfZero,8,vm::Cst,100,vm::Goto,10,vm::Cst,200,vm::Exit};
std::vector<Int> if_test2 {vm::Cst,1,vm::IfZero,8,vm::Cst,100,vm::Goto,10,vm::Cst,200,vm::Exit};
std::vector<Int> add_test {vm::Cst,2,vm::Cst,3,vm::Add,vm::Exit};
std::vector<Int> mul_test {vm::Cst,2,vm::Cst,3,vm::Mul,vm::Exit};
std::vector<Int> swap_test {vm::Cst,2,vm::Cst,4,vm::Swap,vm::Pop,vm::Exit};
std::vector<Int> call_test {vm::Call,4,0,vm::Exit,vm::Cst,15,vm::Ret,0};
std::vector<Int> call_test2 {vm::Cst,2,vm::Cst,3,vm::Cst,5,vm::Call,10,3,vm::Exit,vm::Var,2,vm::Var,2,vm::Add,vm::Var,1,vm::Mul,vm::Ret,3};
std::vector<Int> var_test {vm::Cst,25,vm::Cst,10,vm::Var,1,vm::Swap,vm::Pop,vm::Swap,vm::Pop,vm::Exit};
std::vector<Int> leq_test {vm::Cst,1, vm::Cst,2, vm::Leq, vm::Exit};
std::vector<Int> sub_test {vm::Cst,4, vm::Cst,-1, vm::Add, vm::Exit};
std::vector<Int> fib_test {  6,  4, 0, 10, 0,  5,  6, 11,  1, 7,
  0,  3, 0,  0, 1, 11,  8, 22,  0, 1,
  9, 39, 3,  0, 0, -1,  1,  6, 11, 1,
  3,  1, 0, -2, 1,  6, 11,  1,  1, 7,
  1};

bool test_code(const std::vector<Int> & code, const std::vector<Operand> & stack, Int init_pc, Operand ans)
{
  vm s (code, stack, init_pc);

  return s.run() == ans;
}

void test(void)
{
  Int init_pc = 0;
  std::vector<Operand> stack;

  assert(test_code(cst_test,stack,init_pc,1));
  assert(test_code(if_test,stack,init_pc,200));
  assert(test_code(if_test2,stack,init_pc,100));
  assert(test_code(add_test,stack,init_pc,5));
  assert(test_code(mul_test,stack,init_pc,6));
  assert(test_code(swap_test,stack,init_pc,4));
  assert(test_code(call_test,stack,init_pc,15));
  assert(test_code(call_test2,stack,init_pc,25));
  assert(test_code(var_test,stack,init_pc,25));
  assert(test_code(leq_test,stack,init_pc,1));
  assert(test_code(sub_test,stack,init_pc,3));
  assert(test_code(fib_test,stack,init_pc,8));

  std::cout << "test passed!" << std::endl;
}

int main (void)
{
  test();
  
  return 0;
}
