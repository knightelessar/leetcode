class Solution
{
    // wrong answer algorithm and work: 1h 10m
public:
    int perimeter;
    vector<vector<int>> grid;
    int islandPerimeter(vector<vector<int>> &grid)
    {
        this->perimeter = 0;
        this->grid = grid;
        int row{-1}, col{-1};
        vector<vector<int>> visited(grid);
        for (size_t r{0}; r < grid.size(); ++r)
        {
            for (size_t c{0}; c < grid[0].size(); ++c)
            {
                visited[r][c] = 0;
            }
        }
        for (size_t r{0}; r < grid.size(); ++r)
        {
            for (size_t c{0}; c < grid[0].size(); ++c)
            {
                if (grid[r][c] == 1)
                {
                    row = r;
                    col = c;
                    break;
                }
            }
            if (row > -1 && col > -1)
            {
                break;
            }
        }
        countPerimeter(row, col, visited);
        return perimeter;
    }

    void countPerimeter(int row, int col, vector<vector<int>> &visited)
    {
        if (this->grid[row][col] == 0)
        {
            this->perimeter++;
            return;
        }

        visited[row][col] = 1;
        int rowOffset[4]{-1, 0, 1, 0};
        int colOffset[4]{0, 1, 0, -1};

        for (int i = 0; i < 4; ++i)
        {
            int r = row + rowOffset[i];
            int c = col + colOffset[i];
            if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            {
                this->perimeter++;
                continue;
            }

            if (visited[r][c] == 0)
            {
                countPerimeter(r, c, visited);
            }
        }
    }
};
