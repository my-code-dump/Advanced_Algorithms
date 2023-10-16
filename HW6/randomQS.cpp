#include <iostream>
#include <random>
#include <vector>

int count = 0;
int partition(std::vector<int> &A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
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

void printVector(std::vector<int> &A) {
    std::cout << "[ ";
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " "; 
    }
    std::cout << "]" << std::endl;
}

void randomized_select(std::vector<int> &A, int p, int r, int i) {
    if (p < r) {
        int q = randomized_partition(A,p,r);
        int lessQ = q - 1;
        int greatQ = q + 1;

        randomized_select(A,p,lessQ,i);
        randomized_select(A,greatQ,r,i);
    }
}

void experiment (std::vector<int> A, int i, int trials) {
    
}

int main() {
    std::vector<int> A = {16,5,10,20,4,7,8,15,1,10};
    experiment(A,4,100);
    return 0;
}
