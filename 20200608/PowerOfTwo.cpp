class Solution {
public:
    bool isPowerOfTwo(int n) {
        // The number should be positive
        if (n <= 0) {
            return false;
        }
        // The number should only have one 1-bit
        // Preserve only rightmost 1-bit
        return n == ( n & (-n) );
    }
};
