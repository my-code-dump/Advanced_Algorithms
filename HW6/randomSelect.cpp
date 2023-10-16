#include <iostream>
#include <random>
#include <vector>

float count = 0;
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
    count = count + 1;
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

int randomized_select(std::vector<int> &A, int p, int r, int i) {
    if (p == r){
        return A[p];
    }

    int q = randomized_partition(A,p,r);
    int lessQ = q - 1;
    int greatQ = q + 1;

    int k = q - p + 1;

    // If the pivot is the answer
    if (i == k) {
        return A[q];
    }
    else if (i < k) {
        return randomized_select(A,p,lessQ,i);
    }   
    else {
        return randomized_select(A,greatQ,r,i - k);
    }
}

void printVector(std::vector<int> &A) {
    std::cout << "[ ";
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " "; 
    }
    std::cout << "]";
}

void oneExperiment(std::vector<int> &A, int i) {
    count = 0;
    std::vector<int> B = A;
    int ans = randomized_select(A,0, A.size() - 1,i);
    std::cout << "ith statistic = " << i << 
        " of array:"; 
    printVector(B);
    std::cout << " is " << ans << std::endl;
    printVector(A);
    std::cout << std::endl;
}

void tExperiment (std::vector<int> A, int i, float trials) {
    count = 0;
    for (int j = 0; j < trials; j++) {
        int ans = randomized_select(A,0,A.size() - 1,i);   
    }
    float avgRPCalls = count / trials;
    std::cout << "Average R-Select Random Partition call for " 
        << trials << " = " << avgRPCalls << std::endl; 
}

int main() {
    std::vector<int> A = {16,5,10,20,4,7,8,15,1,10};
    //oneExperiment(A,4);
    tExperiment(A,4,100);

    return 0;
}
