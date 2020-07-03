class Solution
{
    // 1 hour copy implementing and debugging solution approach 1
public:
    int cellToBitmap(const vector<int> &cells)
    {
        int bitmap{0};
        for (auto x : cells)
        {
            bitmap = bitmap << 1;
            bitmap = bitmap | x;
        }
        return bitmap;
    }

    vector<int> nextDay(vector<int> &cells)
    {
        vector<int> curr{cells};
        for (size_t i{0}; i < 8; ++i)
        {
            if (i == 0 || i == 7)
            {
                curr[i] = 0;
            }
            else
            {
                curr[i] = !(cells[i - 1] ^ cells[i + 1]);
            }
        }
        return curr;
    }

    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        unordered_map<int, int> seen;
        vector<int> cellCopy{cells};
        bool isFastForwarded{false};
        while (N > 0)
        {
            if (!isFastForwarded)
            {
                int currBitmap = cellToBitmap(cellCopy);
                if (seen.find(currBitmap) != end(seen))
                {
                    // same pattern: last time number of simulations left
                    // subtracted by this time number of simulations left
                    int cycle = seen[currBitmap] - N;
                    N = N % cycle;
                    // N = N % seen.size();
                    // This is incorrect.
                    // When initial state has 1(s) on the boundaries,
                    // we cannot evolve into the initial state.
                    isFastForwarded = true;
                }
                else
                {
                    seen.insert(make_pair(currBitmap, N));
                }
            }

            if (N > 0)
            {
                cellCopy = nextDay(cellCopy);
                --N;
            }
        }
        return cellCopy;
    }
};
