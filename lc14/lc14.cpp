// leetcode 14 
// 编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
    string lCP(const string& a, const string& b) {
        int len = min(a.length(),b.length());
        string res;
        for (size_t i = 0; i < len; i++) {
            if (a[i] != b[i])
                break;
            res.push_back(a[i]);
        }
        return res;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs.front();
        for (size_t i = 1; i < strs.size(); i++) {
            if (res.empty())
                break;
            res = lCP(res, strs[i]);
        }
        return res;
    }
};