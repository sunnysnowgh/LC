// leetcode 58
// 最后一个单词的长度
// 算法思路
// 反向找到倒数第一个字母，在统计连续的字母的长度

#include<string>
using namespace std;
class Solution {
    int getIndexOfLastLetter(string s) {
        int i = s.length()-1;
        for(; s[i] == ' '; --i)
            ;
        return i;
    }
public:
    int lengthOfLastWord(string s) {
        int wordCharItor = getIndexOfLastLetter(s);
        int res = wordCharItor;
        
        do {
            --wordCharItor;
        } while (wordCharItor >= 0 && s[wordCharItor] != ' ');
        res -= wordCharItor;
        return res;
    }
};