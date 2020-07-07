class Solution
{
    // read solution 30m
    // implement solution 30m
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        const int N = board.size();
        unordered_map<int, int> dist; // square number: number moves
        queue<int> q;
        dist[1] = 0;
        q.push(1);

        while (!q.empty())
        {
            int sCurr = q.front();
            q.pop();
            if (sCurr == N * N)
            {
                return dist[sCurr];
            }

            for (int sNext = sCurr + 1; sNext <= min(sCurr + 6, N * N); ++sNext)
            {
                auto coord = squareNum2Coord(sNext, N);
                int r = coord.first;
                int c = coord.second;

                int sFinal = board[r][c] == -1 ? sNext : board[r][c];
                if (dist.find(sFinal) == dist.end())
                {
                    // sFinal not found
                    dist.insert(make_pair(sFinal, dist[sCurr] + 1));
                    q.push(sFinal);
                }
            }
        }
        return -1;
    }

    pair<int, int> squareNum2Coord(int sNext, int N)
    {
        int quot = (sNext - 1) / N;
        int row = N - quot - 1;
        int col = (sNext - 1) % N;
        if (row % 2 == N % 2)
        {
            col = N - col - 1;
        }
        return make_pair(row, col);
    }
};
