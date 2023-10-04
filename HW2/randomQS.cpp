#include <iostream>
#include <random>
#include <vector>

int comps = 0;
int partition(std::vector<int> &A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        comps++;
        if (A[j] <= x) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    i++;
    int temp = A[i];
    A[i] = A[r];
    A[r] = temp;

    return i;
}

int randomized_partition(std::vector<int> &A, int p, int r) {
    // Randomizer, pick a number between [p,r]
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(p,r);

    // Randomized index i
    // A[i] will be exhange with A[r] to create a randomized effect while
    // keeping the QS functions the same
    int i = dis(gen);
    int temp = A[r];
    A[r] = A[i];
    A[i] = temp;

    return partition(A,p,r);
}

void randomized_quicksort(std::vector<int> &A, int p, int r) {
    if (p < r) {
        int q = randomized_partition(A,p,r);
        int lessQ = q - 1;
        int greatQ = q + 1;

        randomized_quicksort(A,p,lessQ);
        randomized_quicksort(A,greatQ,r);
    }
} 

void printVector(std::vector<int> &A) {
    std::cout << "[ ";
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " "; 
    }
    std::cout << "]" << std::endl;
}

void experiment (std::vector<int> A, int tests) {
    int i = 0;  
    int testComp = 0;
    while (i < tests) {
        randomized_quicksort(A,0,A.size() - 1);
        i++;
        testComp += comps;
        comps = 0;
    }

    int avg = testComp / tests;
    std::cout << "Average Comparisons = " << avg << 
        " | Tests = " << tests << std::endl;
}

int main() {
    std::vector<int> A = {5,8,17,3,14,20,18,19,10,9
                        ,7,6,15,11,4,1,16,2,13,12};
    experiment(A,10000);
    return 0;
}
