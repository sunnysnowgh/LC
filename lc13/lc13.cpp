// leetcode 13
// 给定一个罗马数字，将其转换成整数。
#include <iostream>
#include <string>

using namespace std;
class solve {
    string chars = "MDCLXVI";
    int values[7] = {1000, 500, 100, 50, 10, 5, 1};

    int c2int(char c) {
        for (size_t i = 0; i < 7; i++)
        {
            if (chars[i] == c)
                return values[i];
        }
        return -1;
    }
    inline bool isCXI(int value) {
        return value == 1 || value == 10 || value == 100;
    }

public:
    int toroman(string s) {
        int res = 0;
        int last;
        int now;
        int i = 1;
        do
        {
            last = c2int(s[i-1]);
            now = c2int(s[i]);
            if (last != 1 && last != 10 && last != 100) {
                res += last;
            }
            else {
                if (now > last) {
                    res += now - last;
                    i++;
                }
                else {
                    res += last;
                }
            }
            i++;
        } while (i < s.length());
        if (i == s.length())
            res += c2int(s[i-1]);
        return res;
    }

    int toroman1(string s) {
        int res = 0;
        int last;
        int now;
        int i = 1;
        do
        {
            last = c2int(s[i-1]);
            now = c2int(s[i]);
            res += last;
            if (isCXI(last) && now > last)
            {
                res += now - (last << 1);
                i++;
            }
            i++;
        } while (i < s.length());
        if (i == s.length())
            res += c2int(s[i-1]);
        return res;
    }
};

int main() {
    solve so;
    std::cout << so.toroman1("LVIII") << std::endl;
    return 0;
}