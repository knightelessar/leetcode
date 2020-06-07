class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pCurr, p0r, p2l;
        pCurr = 0;
        p0r = 0;
        p2l = nums.size() - 1;
        while (pCurr <= p2l) {
            if (nums[pCurr] == 0) {
                swap(nums[pCurr], nums[p0r]);
                ++p0r;
                ++pCurr;
            }
            else if (nums[pCurr] == 2) {
                swap(nums[pCurr], nums[p2l]);
                --p2l;
            }
            else {
                ++pCurr;
            }
        }
    }
};
