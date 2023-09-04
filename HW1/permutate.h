#include <iostream> 
#include <vector>
#include <algorithm>

class Permutate{
  private:
    double n;
    double H;
    double HSquared;
    double variance;
    double expectation;
    int vecN;
    std::vector<int> permMe;
    void makeFac(int x);
    void initPermMe(int x);

  public:
    Permutate(int &);
    
    long getFac ();

    void printVector(std::vector<int> &x);

    void hires (std::vector<int> &hires);

    void permutateArr ();

    void calculateVE();

    void runExperiment();

    double getVariance();

    double getExpectation();

};

