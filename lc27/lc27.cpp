#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t insertPositionIndex = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            int nowValue = nums[i];
            if(val != nowValue) {
                nums[insertPositionIndex] = nowValue;
                insertPositionIndex++;
            }
        }
        return insertPositionIndex;
    }
};