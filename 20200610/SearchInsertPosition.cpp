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
        // Binary search
        size_t left{0};
        size_t right{nums.size() - 1};
        size_t mid{0};
        while (left < right) {
            mid = (left + right) / 2;
            if (target <= nums[mid]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
