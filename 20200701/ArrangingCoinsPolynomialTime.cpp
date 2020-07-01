class Solution
{
public:
    int arrangeCoins(int n)
    {
        size_t res{0};
        for (size_t s{static_cast<size_t>(sqrt(n))};
             s <= static_cast<size_t>(sqrt(2) * sqrt(n)) + 1;
             ++s)
        {
            if (s * (s + 1) / 2 <= n && n < (s + 1) * (s + 2) / 2)
            {
                res = s;
            }
        }
        return static_cast<int>(res);
    }
};
