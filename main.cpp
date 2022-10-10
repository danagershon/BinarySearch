#include <iostream>
#include <vector>
#include "regularBinarySearch.cpp"

void printVector(std::vector<int>& vec){
    for(const auto& num: vec){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void testBinarySearch(std::vector<int>& vec,std::vector<int>& targets,
        int (*func)(std::vector<int>&, int)){
    for(const auto& target: targets){
        std::cout << "\ncurrent target: " << target << std::endl;
        std::cout << "target index: " << func(vec,target) << std::endl;
    }
}

int main() {
    std::vector<int> vec{1,3,5,7,12};
    std::cout << "vector is:" << std::endl;
    printVector(vec);

    std::vector<int> targets{0,1,5,12,13};

    std::cout << "\nTesting binary search function 1:" << std::endl;
    testBinarySearch(vec,targets,&binarySearch1);
    std::cout << "\nTesting binary search function 2:" << std::endl;
    testBinarySearch(vec,targets,&binarySearch2);
    std::cout << "\nTesting binary search function 3:" << std::endl;
    testBinarySearch(vec,targets,&binarySearch3);

    return 0;
}