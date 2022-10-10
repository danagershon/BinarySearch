#include <vector>

// classic version
int binarySearch1(std::vector<int>& vec, int target){
    int l = 0;
    int h = static_cast<int>(vec.size() - 1);

    while(l <= h){
        int mid = l + (h-l)/2; // lower mid if length is even. High mid works the same
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

/* version without vec[mid] == target and choosing lower mid.
 * because we choose lower mid when length is even, in the case that
 * l is mid we must not do l<-mid because it will cause infinite loop.
 * This case happens when there are two element: [1,3] for example.
*/
int binarySearch2(std::vector<int>& vec, int target){
    int l = 0;
    int h = static_cast<int>(vec.size() - 1);

    while(l < h){
        int mid = l + (h-l)/2;
        if(vec[mid] < target) {
            l = mid+1;
        } else {
            h = mid;
        }
    }

    return vec[l] == target ? l : -1;
}

// example when there is infinite loop
/*int binarySearch2bad(std::vector<int>& vec, int target){
    int l = 0;
    int h = static_cast<int>(vec.size() - 1);

    while(l < h){
        int mid = l + (h-l)/2;
        if(vec[mid] <= target) {
            l = mid;
        } else {
            h = mid-1;
        }
    }

    return vec[l] == target ? l : -1;
}*/

/* version without vec[mid] == target and choosing higher mid.
 * because we choose lower mid when length is even, in the case that
 * h is mid we must not do h<-mid because it will cause infinite loop.
 * This case happens when there are two element: [1,3] for example.
*/
int binarySearch3(std::vector<int>& vec, int target){
    int l = 0;
    int h = static_cast<int>(vec.size() - 1);

    while(l < h){
        int mid = l + (h-l+1)/2;
        if(vec[mid] > target) {
            h = mid-1;
        } else {
            l = mid;
        }
    }

    return vec[l] == target ? l : -1;
}

// example when there is infinite loop
/*int binarySearch3bad(std::vector<int>& vec, int target){
    int l = 0;
    int h = static_cast<int>(vec.size() - 1);

    while(l < h){
        int mid = l + (h-l+1)/2;
        if(vec[mid] < target) {
            l = mid+1;
        } else {
            h = mid;
        }
    }

    return vec[l] == target ? l : -1;
}*/

