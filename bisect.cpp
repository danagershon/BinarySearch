#include <vector>

int bisectLeft(std::vector<int>& vec,int num){
    int l = 0;
    int h = static_cast<int>(vec.size());

    while(l < h){
        int mid = l + (h-l)/2;
        if(num > vec[mid]){
            l = mid+1;
        } else {
            h = mid;
        }
    }

    return l;
}

int bisectRight(std::vector<int>& vec,int num){
    int l = 0;
    int h =  static_cast<int>(vec.size());

    while(l < h){
        int mid = l + (h-l)/2;
        if(num < vec[mid]){
            h = mid;
        } else{
            l = mid+1;
        }
    }

    return l;
}


