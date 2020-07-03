class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        vector<int> prev{cells};
        vector<int> curr{cells};
        for (int day{0}; day < N; ++day)
        {
            prev = curr;
            for (size_t i{0}; i < 8; ++i)
            {
                if (i == 0 || i == 7)
                {
                    curr[i] = 0;
                }
                else
                {
                    curr[i] = !(prev[i - 1] ^ prev[i + 1]);
                }
            }
        }
        return curr;
    }
};
