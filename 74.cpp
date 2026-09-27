#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        if(matrix.size() <= 1 && matrix[0][0] == target) {
            return true;
        }
        int startRow = 0, endRow = matrix.size()-1;
        int rowFound = -1;
        while(startRow <= endRow && matrix.size() >= 1) {
            int midRow = startRow + (endRow-startRow)/2;
            int midRowLastVal = matrix[midRow][matrix[midRow].size() - 1];
            int midRowFirstVal = matrix[midRow][0];
            if(target < midRowFirstVal) {
                // shift end row one behind mid row
                endRow = midRow - 1;
            } else if( target > midRowLastVal) {
                // shift start row one ahead mid row
                startRow = midRow + 1;
            } else {
                rowFound = midRow;
                break;
            }
        }

        if(rowFound == -1) {
            return false;
        }
        int start = 0, end = matrix[rowFound].size() - 1;
        while(start <= end) {
            int  mid = start + (end - start) /2;
            if(target < matrix[rowFound][mid]) {
                end = mid-1;
            } else if(target > matrix[rowFound][mid]) {
                start = mid+1;
            } else {
                return true;
            }
        }
        return false;
    }
};