#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& vec, int target){
    int l = 0;
    int h = static_cast<int>(vec.size() - 1);

    while(l <= h){
        int mid = l + (h-l/2);
        if(vec[mid] == target){
            return mid;
        } else if(vec[mid] < target){
            l = mid+1;
        } else {
            h = mid-1;
        }
    }

    return -1;
}

void printVector(std::vector<int>& vec){
    for(const auto& num: vec){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> vec{1,3,5,7,12};
    std::cout << "Testing binary search function:" << std::endl;
    std::cout << "vector is:" << std::endl;
    printVector(vec);

    std::vector<int> targets{0,1,5,12,13};
    for(const auto& target: targets){
        std::cout << "\ncurrent target: " << target << std::endl;
        std::cout << "target index: " << binarySearch(vec,target) << std::endl;
    }

    return 0;
}