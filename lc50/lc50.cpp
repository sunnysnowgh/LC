// leetcode 50
// 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。
#include<cstddef>
#include<cstdint>
class Solution {
    double i32MinPow(double x) {
        x = 1 / x;
        for (size_t i = 0; i < 31; i++) {
            x *= x;
        }
        return x;
    }
public:
    double myPow(double x, int n) {
        double res = 1;
        if(n==INT32_MIN) return i32MinPow(x);
        if(n<0) {
            x = 1 / x;
            n = -n;
        }
        for(int i = 0;i < 31; ++i) {
            bool isSet = (n >> i) & 0x00000001;
            if (isSet) res *= x;
            x *= x;
        }
        return res;
    }
};