// =====================================================================================
//
//       Filename:  number_of_bits.cpp
//
//    Description:  191. Number of 1 Bits.
//
//        Version:  1.0
//        Created:  08/21/2019 08:19:00 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stdint.h>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int m = 0;
        while (n != 0)
        {
            if (n & 0x1)
            {
                m++;
            }
            n >>= 1;
        }
        return m;
    }
};

int main(int argc, char* argv[])
{
    uint32_t n = 43261596;
    int m = Solution().hammingWeight(n);
    printf("%d -> %d\n", n, m);
    return 0;
}
