#include <iostream>
#include "permutate.h"
#include <algorithm>

int main() {
  int size = 8;
  Permutate ex1 (size);
  ex1.runExperiment();
  std::cout << "E[x] = " << ex1.getExpectation() << std::endl;
  std::cout << " Var = " << ex1.getVariance() << std::endl;

  return 0;  
}
