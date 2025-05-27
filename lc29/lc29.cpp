// leetcode 29
// 两数相除

// 算法思路
// dividend == divisor * 2^k + r * 2^k  (divisor >= r * 2^k)
// dividend / divisor == 2^k + (r * 2^k) / divisor
#include<cstdint>
const unsigned int intMax = INT32_MAX; 
const int intMin = INT32_MIN;
class Solution {
    inline unsigned int neg2pos(int a) {
        return (unsigned int)(-(a+1)) + 1;
    }
public:
    int divide(int dividend, int divisor) {
        bool isDividendNeg = dividend < 0;
        bool isDivisorNeg = divisor < 0;
        unsigned int PosDividend = isDividendNeg ? neg2pos(dividend) : dividend;
        unsigned int PosDivisor = isDivisorNeg ? neg2pos(divisor) : divisor;
        bool isResNeg = isDividendNeg ^ isDivisorNeg;

        unsigned int res = 0;
        while (PosDividend >= PosDivisor) {
            unsigned int midPosDivisor = PosDivisor;
            int k = 0;
            for ( ;PosDividend > midPosDivisor; ++k) {
                midPosDivisor <<= 1;
            }
            if(PosDividend == midPosDivisor) {
                res += (unsigned int) 1 << k;
                break;
            }
            res += (unsigned int)1 << k-1;
            PosDividend -= midPosDivisor >> 1;
        }
        if(res ==  intMax + 1) return isResNeg ?  intMin : intMax;
        return isResNeg ? -(int)res : res;
    }
};