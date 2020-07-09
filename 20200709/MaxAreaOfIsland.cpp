class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        const int ROW = grid.size();
        const int COL = grid[0].size();
        vector<vector<int>> visited(ROW, vector<int>(COL, 0));
        int maxArea{0};
        for (int i{0}; i < ROW; ++i)
        {
            for (int j{0}; j < COL; ++j)
            {
                int n = countAndDFSTravel(grid, visited, i, j);
                maxArea = max(maxArea, n);
            }
        }
        return maxArea;
    }

    int countAndDFSTravel(vector<vector<int>> &grid,
                          vector<vector<int>> &visited,
                          int row,
                          int col)
    {
        if (isOutOfBound(grid, row, col) || visited[row][col] || grid[row][col] == 0)
        {
            return 0;
        }
        visited[row][col] = 1;
        int currentTile = 1;
        int up = countAndDFSTravel(grid, visited, row - 1, col);
        int right = countAndDFSTravel(grid, visited, row, col + 1);
        int down = countAndDFSTravel(grid, visited, row + 1, col);
        int left = countAndDFSTravel(grid, visited, row, col - 1);
        return currentTile + up + right + down + left;
    }

    bool isOutOfBound(vector<vector<int>> &grid, int row, int col)
    {
        const int ROW = grid.size();
        const int COL = grid[0].size();
        return row < 0 || row >= ROW || col < 0 || col >= COL;
    }
};
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        const int ROW = grid.size();
        const int COL = grid[0].size();
        vector<vector<int>> visited(ROW, vector<int>(COL, 0));
        int maxArea{0};
        for (int i{0}; i < ROW; ++i)
        {
            for (int j{0}; j < COL; ++j)
            {
                int n = countAndDFSTravel(grid, visited, i, j);
                maxArea = max(maxArea, n);
            }
        }
        return maxArea;
    }

    int countAndDFSTravel(vector<vector<int>> &grid,
                          vector<vector<int>> &visited,
                          int row,
                          int col)
    {
        if (isOutOfBound(grid, row, col) || visited[row][col] || grid[row][col] == 0)
        {
            return 0;
        }
        visited[row][col] = 1;
        int currentTile = 1;
        int up = countAndDFSTravel(grid, visited, row - 1, col);
        int right = countAndDFSTravel(grid, visited, row, col + 1);
        int down = countAndDFSTravel(grid, visited, row + 1, col);
        int left = countAndDFSTravel(grid, visited, row, col - 1);
        return currentTile + up + right + down + left;
    }

    bool isOutOfBound(vector<vector<int>> &grid, int row, int col)
    {
        const int ROW = grid.size();
        const int COL = grid[0].size();
        return row < 0 || row >= ROW || col < 0 || col >= COL;
    }
};
