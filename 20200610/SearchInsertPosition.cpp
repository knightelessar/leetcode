class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums.front())
        {
            return 0;
        }
        if (target > nums.back())
        {
            return nums.size();
        }
        // Linear walk
        size_t pos{0};
        for (auto it = cbegin(nums); it != cend(nums); ++it)
        {
            if (target <= *it)
            {
                break;
            }
            pos++;
        }
        return pos;
    }
};
