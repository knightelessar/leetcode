class Solution {
        vector<int> bounds;
public:
    Solution(vector<int>& w) {
        for (auto n: w) {
            bounds.push_back(
                (bounds.empty() ? 0 : bounds.back())
                + n);
        }
    }
    
    int pickIndex() {
        int myRand = getRand(bounds.back());
        // int myRand = rand() % bounds.back();
        size_t right = bounds.size();
        size_t left = 0;
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (myRand >= bounds[mid]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
    
    int getRand(int modulo) {
        if (modulo == 0) {
            return 0;
        }
        while (true) {
            int x = rand();
            if (x < RAND_MAX - RAND_MAX % modulo) {
                return x % modulo;
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
