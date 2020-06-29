class Solution {
public:
    int uniquePaths(int m, int n) {
        // n row m column DP matrix
        int dp[n][m];
        for (auto &row: dp)
        {
            for (auto &elem: row)
            {
                elem = 0;
            }
        }

        for (auto &elem: dp[0])
        {
            elem = 1;
        }

        for (size_t i{0}; i < n; ++i)
        {
            dp[i][0] = 1;
        }

        for (size_t i{1}; i < n; ++i)
        {
            for (size_t j{1}; j < m; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};
