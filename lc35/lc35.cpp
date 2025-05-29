// leetcode 35
// 搜索插入位置
// 算法思路
// 二分查找没找到时，low为插入位置
// tips
// low,high,mid 用有符号数，有变成-1的情况
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return low;
    }
};