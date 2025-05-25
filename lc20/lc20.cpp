// leetcode 20
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
    inline bool isLeft(char c) {
        return c == '(' || c == '[' || c == '{';
    }
    bool isMatch(char a, char b) {
        return (a=='(' && b==')')
                 || (a=='[' && b==']')
                 || (a=='{' && b=='}');
    }
public:
    bool isValid(string s) {
        vector<char> stack;
        for (auto &&c : s) {
            if(isLeft(c)) {
                stack.push_back(c);
            } 
            else {
                if(stack.empty())
                    return false;
                if(!isMatch(stack.back(), c))
                    return false;
                stack.pop_back();
            }
        }
        if(stack.empty())
            return true;
        return false;
    }
};