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
        int myRand = getRand(this->bounds.back());
        // int myRand = rand() % bounds.back();
        int index = static_cast<int>(bounds.size() - 1);
        for (size_t i{0}; i < this->bounds.size(); ++i) {
            if (myRand < this->bounds[i]) {
                index = static_cast<int>(i);
                break;
            }
        }
        return index;
    }
    
    int getRand(int modulo) {
        if (modulo == 0) {
            cout << "modulo = 0" << endl;
            return 0;
        }
        while (true) {
            int x = rand();
            cout << RAND_MAX << endl;
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