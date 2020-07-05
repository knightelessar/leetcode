class Solution
{
    // work: 10 min
public:
    int hammingDistance(int x, int y)
    {
        int z = x ^ y;
        int dist{0};
        while (z > 0)
        {
            z = z & (z - 1);
            ++dist;
        }
        return dist;
    }
};
