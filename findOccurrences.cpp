#include <vector>

int findFirstOccurrence(std::vector<int>& vec,int target){
    int l = 0;
    int h = static_cast<int>(vec.size()) - 1;

    while(l < h){
        int mid = l +(h-l)/2;
        if(vec[mid] < target){
            l = mid+1;
        } else{
            h = mid;
        }
    }
    if(vec[l] == target){
        return l;
    }
    return -1;
}

int findFirstOccurrence2(std::vector<int>& vec,int target){
    int l = 0, h = static_cast<int>(vec.size()) - 1;
    int ans = -1;

    while(l <= h){
        int mid = l + (h-l)/2;
        if(vec[mid] == target){
            ans = mid;
            h = mid-1;
        } else if(vec[mid] < target){
            l = mid+1;
        } else{
            h = mid-1;
        }
    }

    return ans;
}

int findLastOccurrence(std::vector<int>& vec,int target){
    int l = 0;
    int h = static_cast<int>(vec.size()) - 1;

    while(l < h){
        int mid = l + (h-l+1)/2;
        if(target < vec[mid]){
            h = mid-1;
        } else{
            l = mid;
        }
    }
    if(vec[l] == target){
        return l;
    }
    return -1;
}

int findLastOccurrence2(std::vector<int>& vec,int target){
    int l = 0, h = static_cast<int>(vec.size()) - 1;
    int ans = -1;

    while(l <= h){
        int mid = l + (h-l)/2;
        if(vec[mid] == target){
            ans = mid;
            l = mid+1;
        } else if(vec[mid] < target){
            l = mid+1;
        } else{
            h = mid-1;
        }
    }

    return ans;
}
