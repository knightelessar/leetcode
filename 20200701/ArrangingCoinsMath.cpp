class Solution
{
public:
    int arrangeCoins(int n)
    {
        return static_cast<int>(sqrt(2 * static_cast<long long>(n) + 0.25) - 0.5);
    }
};
