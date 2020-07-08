class Solution
{
    // Contemplate on set algorithm 35m
    // Read two pointer solution 25m
    // Implement two pointer solution 20m
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                twoSum(nums, i, result);
            }
        }
        return result;
    }

    void twoSum(vector<int> &nums, int i, vector<vector<int>> &result)
    {
        int lo = i + 1;
        int hi = nums.size() - 1;
        while (lo < hi)
        {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0 || (lo - 1 > i && nums[lo] == nums[lo - 1]))
            {
                ++lo;
            }
            else if (sum > 0 || (hi + 1 < nums.size() && nums[hi] == nums[hi + 1]))
            {
                --hi;
            }
            else
            {
                result.push_back({nums[i], nums[lo], nums[hi]});
                --hi;
                ++lo;
            }
        }
    }
};
