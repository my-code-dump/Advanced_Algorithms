#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int findLargest(std::vector<int> &A) {
    int largestL = 1;
    int currentL = 1;
    for (int i = 1; i < A.size(); i++) {
        if (A[i - 1] < A[i]) {
            //std::cout << "Compare " << A[i - 1] << " " << A[i] << std::endl;
            currentL++;
        } 
        else {
            currentL = 1;
        }
        if (currentL > largestL) {
            largestL = currentL;
        }
    }
    return largestL;
}

int main () {
    int size = 20;
    int bigL = 0;
    int tests = 2000;

    for (int i = 0; i < tests; i++) {
        std::vector<int> A(size,0);

        srand(time(0));
        generate(A.begin(), A.end(), rand);
        bigL += findLargest(A);
    }
    
    double results = (double) bigL / (double) tests;
    std::cout <<"Average Largest Increasing Order = " << results << std::endl;

    return 0;
}
