// leetcode 31
// 整数数组的 下一个排列
// 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的
// 下一个排列
// 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
// 算法思路
// 出现倒序意味着对应长度的子问题遇到了最大排列（倒序指降序）
// 从结尾开始看看倒序的长度
// 将倒序开始的前一个元素 与
// 倒序排列中倒着数第一个大于它的数交换，此时子排列仍为降序
// 将子排列变为升序，即直接翻转子排序
// tips
// lower_bound默认传入数组为使cmp为真的顺序排列，返回第一个使cmp为假的元素
// reverse翻转数组
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  int tailReverseIndex(vector<int> &nums) {
    int res;
    for (res = nums.size() - 1; res > 0; res--) {
      if (nums[res] > nums[res - 1])
        return res;
    }
    return 0;
  }

public:
  void nextPermutation(vector<int> &nums) {
    int reverseIndex = tailReverseIndex(nums);
    if (reverseIndex == 0) {
      reverse(nums.begin(), nums.end());
      return;
    }
    auto reverseIt = nums.begin() + reverseIndex;
    auto toSwap = lower_bound(reverseIt, nums.end(), nums[reverseIndex - 1],
                              greater<int>()) -
                  1;
    int mid = *toSwap;
    *toSwap = nums[reverseIndex - 1];
    nums[reverseIndex - 1] = mid;
    reverse(nums.begin() + reverseIndex, nums.end());
  }
};