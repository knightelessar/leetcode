class Solution {
public:
    bool isPowerOfTwo(int n) {
        // The number should be positive
        if (n <= 0) {
            return false;
        }
        
        // The number should has exactly one bit as one, 
        // and the other bits should be zero.
        size_t nOne{0};
        for (size_t i{0}; static_cast<unsigned int>(1<<i) <= static_cast<unsigned int>(n); ++i) {
            if ( (static_cast<unsigned int>(n) & static_cast<unsigned int>(1 << i) )
                == static_cast<unsigned int>(1 << i) ) ++nOne;
            if (nOne > 1) break;
        }
        return nOne == 1;
    }
};
