class Solution {
    // learn solution 13:30 - 14:00
    // work 14:08 - 14:35

public:
    int numSquares(int n) {
        vector<int> dp(n + 1, numeric_limits<int>::max());
        vector<int> squares(static_cast<int>(sqrt(n)) + 1, 0);
        dp[0] = 0;
        for (size_t i{0}; i < squares.size(); ++i)
        {
            squares[i] = i * i;
        }

        for (size_t i{1}; i < n + 1; ++i)
        {
            for (size_t j{1}; j < squares.size(); ++j)
            {
                if (i < squares[j])
                {
                    break;
                }
                dp[i] = min(dp[i - squares[j]] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};
