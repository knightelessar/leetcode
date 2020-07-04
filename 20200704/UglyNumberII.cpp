class Solution
{
    // attempt 30 min cannot figure out three pointer how to avoid duplicate
    // read solution 15 min
    // implement solution 12 min
public:
    int nthUglyNumber(int n)
    {
        if (n < 1)
            return 0;
        vector<int> nums(n, 0);
        nums[0] = 1;
        size_t p2{0}, p3{0}, p5{0};
        for (size_t i{1}; i < n; ++i)
        {
            int next = min(nums[p2] * 2,
                           min(nums[p3] * 3, nums[p5] * 5));
            nums[i] = next;
            if (nums[p2] * 2 == next)
                ++p2;
            if (nums[p3] * 3 == next)
                ++p3;
            if (nums[p5] * 5 == next)
                ++p5;
        }
        return nums[n - 1];
    }
};
