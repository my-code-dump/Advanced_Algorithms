#include "permutate.h"

Permutate::Permutate(int sz, bool choice, int iterations) {
  vecN = sz;
  H = 0;
  HSquared = 0;
  variance = 0;
  expectation = 0;
  n = 1;
  random = choice;

  if (random) {
    n = iterations;
  }
  else {
    makeFac(sz);  
  }

  initPermMe(sz);
}

void Permutate::makeFac(int x) {
  // Calcuate the factorial
  if ((x == 0) || (x == 1)) {
    n = 1;
  } 
  else if (x > 1) {
    for (int i = x; i > 1; i--) {
      n *= i;
    }
  }
}

void Permutate::initPermMe(int x) {
  // Gets the array to permutate [1 ... sz]
  for (int i = 1; i <= x; i++) {
    permMe.push_back(i);
  }
}

long Permutate::getFac () {
  return n;
}

void Permutate::printVector(std::vector<int> &x) {
  int max = x.size();
  for (int i = 0; i < max; i++) {
    std::cout << x[i] << " ";
  }
  std::cout << std::endl;
}

void Permutate::hires (std::vector<int> &hireList) {
  int limit = hireList.size();
  int youreHired = 1;
  int max = hireList[0];
  
  for (int i = 1; i < limit; i++) {
    if (hireList[i] > max) {
      max = hireList[i];
      youreHired++;
    }   
  }
  H += (double) youreHired;
  HSquared += (double) (youreHired * youreHired);
}

void Permutate::permutateArr () {
  std::vector<int> A = permMe;
  do {
    hires(A);
  } while(std::next_permutation(A.begin(),A.end()));
}

void Permutate::randomPermutateArr() {
  std::vector<int> A = permMe;
  std::random_device rd;
  std::mt19937 g(rd());

  for (int i = 0; i < 1000; i++) {
    std::shuffle(A.begin(), A.end(), g);
    hires(A);
  }
}

void Permutate::calculateVE() {
  expectation = H/n;
  double expHSquared = HSquared/n;
  variance = expHSquared - (expectation * expectation);
}

void Permutate::runExperiment() {
  if (random) {
    std::cout << "Rand Permutations (" << n << " Iterations)" << std::endl;
    randomPermutateArr();
  }
  else {
    std::cout << "Full Permutations" << std::endl;
    permutateArr();
  }
  std::cout << "Size = " << vecN << std::endl;
  calculateVE();
}

double Permutate::getVariance() {
  return variance;
}

double Permutate::getExpectation() {
  return expectation;
}

void Permutate::printBothResults() {
  std::cout << "E[X] = " << getExpectation() << std::endl;
  std::cout << " Var = " << getVariance() << std::endl;
}

