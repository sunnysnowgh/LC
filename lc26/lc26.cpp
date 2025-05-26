// leetcode 26
// 删除有序数组中的重复项
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t insertPositionIndex = 1;
        int lastInsertValue = nums.front();
        for (size_t i = 1; i < nums.size(); i++) {
            int nowValue = nums[i];
            if(lastInsertValue != nowValue) {
                nums[insertPositionIndex] = nowValue;
                lastInsertValue = nowValue;
                insertPositionIndex++;
            }
        }
        return insertPositionIndex;
    }
};