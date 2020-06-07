class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pCurr, p0r, p2l;
        pCurr = 0;
        p0r = 0;
        p2l = nums.size() - 1;
        for (pCurr = 0; pCurr < p2l; ++pCurr) {
            if (nums[pCurr] == 0) {
                swap(nums[pCurr], nums[p0r]);
                ++p0r;
            }
            else if (nums[pCurr] == 2) {
                swap(nums[pCurr], nums[p2l]);
                --p2l; // <= bug here, the number 2 is swapped to pCurr, 
                       // and we left it unprocessed in future loops.
            }
        }
    }
};
