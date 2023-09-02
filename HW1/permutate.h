#include <iostream> 
#include <vector>
#include <algorithm>

class Permutate{
  private:
    long n;
    long H;
    long HSquared;
    float variance;
    float expectation;
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

    float getVariance();

    float getExpectation();
};

