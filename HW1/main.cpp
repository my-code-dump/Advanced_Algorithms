#include <iostream>
#include "permutate.h"

int main() {
  int size = 8;
  Permutate ex1 (size);
  std::cout << "E[x] = " << ex1.getExpectation() << std::endl;
  std::cout << " Var = " << ex1.getVariance() << std::endl;
}
