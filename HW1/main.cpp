#include <iostream>
#include "permutate.h"
#include <algorithm>

int main() {
  Permutate ex1 (8, false, 1000);
  ex1.runExperiment();
  ex1.printBothResults();

  Permutate ex2 (8, true, 1000);
  ex2.runExperiment();
  ex2.printBothResults();
  
  Permutate ex3 (20, true, 1000);
  ex3.runExperiment();
  ex3.printBothResults();
  return 0;  
}
