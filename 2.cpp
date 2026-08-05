#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> answer;

        for(int i=0; i<nums.size(); i++) {
            int first = nums[i];
            int second = target - first;

            if(m.find(second) != m.end()){
                answer.push_back(i);
                answer.push_back(m[second]);
                break;
            }
            m[first] = i;
        }
        return answer;
    }
};