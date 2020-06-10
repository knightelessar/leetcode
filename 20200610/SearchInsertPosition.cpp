class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Binary search
        size_t left{0};
        size_t right{nums.size() - 1};
        size_t mid{0};
        while (left < right) {
            cout << "left = " << left << ", right = " << right << endl;
            mid = (left + right) / 2;
            cout << "mid = " << mid << endl;
            if (target <= nums[mid]) {
                cout << "target = " << target << " <= " << "nums[" << mid << "] = " << nums[mid] << endl;
                right = mid;
                cout << "right <- mid = " << mid << endl;
            }
            else {
                cout << "target = " << target << " > " << "nums[" << mid << "] = " << nums[mid] << endl;
                left = mid + 1;
                cout << "left <- mid + 1 = " << mid+1 << endl;
            }
        }
        return left;
    }
};
