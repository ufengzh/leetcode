/*
 * =====================================================================================
 *
 *       Filename:  pow.cpp
 *
 *    Description:  Pow(x, n): Implement pow(x, n), which calculates x raised to the 
 *                  power n.
 *
 *        Version:  1.0
 *        Created:  07/09/18 01:30:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Iterative
class Solution1
{
public:
    double myPow(double x, int n)
    {
        if (x == -1)
        {
            return (n & 0x01 ? -1 : 1);
        }

        double k = 1;
        if (n == INT_MIN)
        {
            k /= x;
            n += 1;
        }

        bool minus = (n < 0 ? true : false);
        n = (minus ? -n : n);

        while (n > 0)
        {
            if (minus)
            {
                k /= x;
            }
            else
            {
                k *= x;
            }
            if (k == 0.0)
            {
                break;
            }
            else if (abs(x) < 2.0 && k == 1.0)
            {
                break;
            }
            n -= 1;
        }

        return k;
    }
};

// Recursive
class Solution2
{
public:
    double myPow(double x, int n)
    {
        return myPow(x, n, 1.0);
    }

private:
    double myPow(double x, int n, double val)
    {
        if (x == 0 || val == 0.0)
        {
            return 0.0;
        }
        if (abs(x) == 1)
        {
            return (n & 0x1) ? (x * val) : val;
        }
        if (n == 0)
        {
            return val;
        }
        if (n > 0)
        {
            return myPow(x, n - 1, x * val);
        }
        else
        {
            return myPow(x, n + 1, (1.0 / (double)x * val));
        }
    }
};

// Binary search
class Solution3
{
public:
    double myPow(double x, int n)
    {
        if (x == 0.0)
        {
            return 0.0;
        }
        if (abs(x) == 1)
        {
            return (n & 0x1) ? x : 1.0;
        }
        if (n == 0)
        {
            return 1.0;
        }

        double val = 1.0;
        if (n < 0)
        {
            if (n == INT_MIN)
            {
                n++;
                val = 1 / x;
            }
            n = -n;
            x = 1 / x;
        }

        if (n & 0x1)
        {
            val *= x;
        }
        return val * myPow(x * x, n / 2);
    }
};

using Solution = Solution3;

int main(int argc, char* argv[])
{
    double x = 2.0;
    int n = 10;
    if (argc > 2)
    {
        x = atof(argv[1]);
        n = atoi(argv[2]);
    }

    double x_pow = Solution().myPow(x, n);
    printf("pow(%F, %d) = %F\n", x, n, x_pow);

    return 0;
}

