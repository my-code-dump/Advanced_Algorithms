#include <iostream> 
#include <vector>
#include <algorithm>
#include <random>

class Permutate{
  private:
    double n;
    double H;
    double HSquared;
    double variance;
    double expectation;
    std::vector<int> permMe;
    void makeFac(int x);
    void initPermMe(int x);
    int vecN;
    int trials;
    bool random;

  public:
    Permutate(int , bool , int );
    
    long getFac ();

    void printVector(std::vector<int> &x);

    void hires (std::vector<int> &hires);

    void permutateArr ();

    void randomPermutateArr ();

    void calculateVE();

    void runExperiment();

    double getVariance();

    double getExpectation();

    void printBothResults();

};

