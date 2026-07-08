#include <vector>
using namespace std;

class Solution {
    public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1;
        int end = arr.size() - 2;
        int mid;

        while(start <= end){
            mid = start + (end-start)/2;
            if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid]){
                // peak element found
                break;
            } else if(arr[mid-1] < arr[mid]){
                // in left side of mountain peak, hence move to right
                start = mid + 1;
            } else if(arr[mid-1] > arr[mid]){
                // in right side of mountain peak, hence move to left
                end = mid -1;
            }
        }
        return mid;
    }
};