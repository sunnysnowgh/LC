// leetcode 17
// 电话号码的字母组合

#include<vector>
#include<string>
using namespace std;
class Solution {
    vector<string> digit2Letter = {"abc", "def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> *res = new vector<string>;
        if(digits.empty()) return *res;
        res->push_back("");
        for(char &c : digits) {
            vector<string> *mid = new vector<string>;
            for(char &cc : digit2Letter[c-'2']) {
                for(string s : *res){
                    s.push_back(cc);
                    mid->push_back(s);
                }
            }
            delete res;
            res = mid;
        }
        return *res;
    }
};