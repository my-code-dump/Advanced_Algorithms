#include "permutate.h"

Permutate::Permutate(int &sz) {
  H = 0;
  HSquared = 0;
  variance = 0;
  expectation = 0;
  n = 1;

  makeFac(sz);  
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

void Permutate::hires (std::vector<int> &hires) {
  int limit = hires.size();
  int youreHired = 1;
  int max = hires[0];
  
  for (int i = 0; i < limit; i++) {
    if (hires[i] > max) {
      max = hires[i];
      youreHired++;
    }   
  }
  H += youreHired;
  HSquared += (youreHired * youreHired);
}

void Permutate::permutateArr () {
  std::vector<int> A = permMe;
  do {
    hires(A);
  } while(std::next_permutation(A.begin(),A.end()));
}

void Permutate::calculateVE() {
  expectation = (float) H/n;
  float expHSquared = (float) HSquared/n;
  variance = expHSquared - expectation;
}

float Permutate::getVariance() {
  if (variance == 0) {
    permutateArr();
    calculateVE();
  }
  return variance;
}

float Permutate::getExpectation() {
  if (expectation == 0) {
    permutateArr();
    calculateVE();
  }
  return expectation;
}
