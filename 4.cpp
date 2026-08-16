#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, k = 0;
        double median;
        vector<int> answer(nums1.size() + nums2.size()); 
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                answer[k++] = nums1[i++];
            } else answer[k++] = nums2[j++];
        }

        while(j < nums2.size()) {
            answer[k++] = nums2[j++];
        }

        while(i < nums1.size()) {
            answer[k++] = nums1[i++];
        }

        int start = 0;
        int end = answer.size() - 1;
        int mid = start + (end - start)/2.0;

        if(answer.size() % 2 == 0) {
            // there is no exact mid because there are even elements
            int mid1 = answer.size()/2 - 1, mid2 = answer.size()/2;
            median = (answer[mid1] + answer[mid2]) / 2.0;
        } else {
            // There is exact mid and that is the median
            median = answer[mid];
        }
        return median;
    }
};