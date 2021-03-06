// 154. Find Minimum in Rotated Sorted Array II
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <vector>

class Solution
{
public:
    int findMin(std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            {
                right--;
            }
        }

        return nums[left];
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {2, 2, 2, 1, 2};
    int val = Solution().findMin(nums);
    printf("Minimum is %d\n", val);
    return 0;
};
