#include <vector>

// find the greatest element that is smaller than target
int findClosestFromLeft(std::vector<int>& vec,int target){
    int l = 0;
    int h = static_cast<int>(vec.size()) - 1;

    while(l < h){
        int mid = l + (h-l+1)/2;
        if(target <= vec[mid]){
            h = mid-1;
        } else{
            l = mid;
        }
    }

    if(vec[l] >= target) {
        return -1;
    }
    return l;
}

// find the smallest element that is greater than target
int findClosestFromRight(std::vector<int>& vec,int target){
    int l = 0;
    int h = static_cast<int>(vec.size()) - 1;

    while(l < h){
        int mid = l + (h-l)/2;
        if(target < vec[mid]){
            h = mid;
        } else{
            l = mid+1;
        }
    }

    if(vec[l] <= target){
        return -1;
    }
    return l;
}
