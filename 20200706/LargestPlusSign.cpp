class Solution
{
    // O(N^3) Time Limit Exceeded Algorithm draft no code: 20m
    // Read O(N^2) DP solution: 15m
    // Implement O(N^2) solution: 30m
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
    {
        unordered_set<int> banned;
        int res{-1};
        for (const auto &m : mines)
        {
            banned.insert(N * m[0] + m[1]);
        }

        vector<vector<int>> dp(N, vector<int>(N, numeric_limits<int>::max()));
        int curr{0};
        bool isBanned{false};
        for (size_t r{0}; r < N; ++r)
        {
            curr = 0;
            for (size_t c{0}; c < N; ++c)
            {
                isBanned = banned.find(N * r + c) != banned.end();
                curr = isBanned ? 0 : (curr + 1);
                dp[r][c] = min(curr, dp[r][c]);
            }

            curr = 0;
            for (size_t c{static_cast<size_t>(N) - 1}; c < N; --c)
            {
                isBanned = banned.find(N * r + c) != banned.end();
                curr = isBanned ? 0 : (curr + 1);
                dp[r][c] = min(curr, dp[r][c]);
            }
        }

        for (size_t c{0}; c < N; ++c)
        {
            curr = 0;
            for (size_t r{0}; r < N; ++r)
            {
                isBanned = banned.find(N * r + c) != banned.end();
                curr = isBanned ? 0 : (curr + 1);
                dp[r][c] = min(dp[r][c], curr);
            }

            curr = 0;
            for (size_t r{static_cast<size_t>(N) - 1}; r < N; --r)
            {
                isBanned = banned.find(N * r + c) != banned.end();
                curr = isBanned ? 0 : (curr + 1);
                dp[r][c] = min(dp[r][c], curr);
                res = max(res, dp[r][c]);
            }
        }

        return res;
    }
};
