class Solution
{
    // read and implement solution: 8m
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int p{0};
        for (size_t r{0}; r < grid.size(); ++r)
        {
            for (size_t c{0}; c < grid[0].size(); ++c)
            {
                if (grid[r][c] == 1)
                {
                    p = p + 4;
                    if (r - 1 < grid.size() && grid[r - 1][c] == 1)
                    {
                        p = p - 2;
                    }
                    if (c - 1 < grid[0].size() && grid[r][c - 1] == 1)
                    {
                        p = p - 2;
                    }
                }
            }
        }
        return p;
    }
};
