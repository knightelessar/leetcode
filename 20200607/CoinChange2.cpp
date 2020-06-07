class Solution
{
    int counter;
public:
    unordered_map<int, unordered_map<int, int>> ways; // key: rest, value: pair<currCoin, nWays>
    int change(int amount, vector<int> &coins)
    {
        // Sort the coins in ascending order
        sort(begin(coins), end(coins));
        vector<vector<int>> ans;
        bc(coins, amount, 0, ans);
        return counter;
    }

    int nValidChange(int rest, vector<int> &coins, size_t coinType, size_t lastCoinType)
    {
        if (coinType > lastCoinType || coins.empty())
        {
            // Out of coin type
            return rest == 0 ? 1 : 0;
        }
        else if (coinType == lastCoinType)
        {
            // Last (smallest coin type)
            return rest % coins[coinType] == 0 ? 1 : 0;
        }

        if (ways.find(rest) != ways.end())
        {
            if (ways[rest].find(coinType) != ways[rest].end())
                return ways[rest][coinType];
        }

        int nWay = 0;
        int maxCoinType = rest / coins[coinType];

        for (int i = maxCoinType; i >= 0; --i)
        {
            nWay = nWay += nValidChange(rest - i * coins[coinType],
                                        coins,
                                        coinType + 1,
                                        lastCoinType);
        }
        if (ways.find(rest) == ways.end() || ways[rest].find(coinType) == ways[rest].end())
        {
            ways[rest][coinType] = nWay;
        }
        return nWay;
    }

    /* 
     * Mincan's back track routine
     * For number of valid combinations, we do not need to save the path.
     */
    void bc(vector<int>& coins, int target, int curIdx, vector<vector<int>>& ans, vector<int>&& path = {})
    {
        if (target == 0)
        {
            ans.push_back(path);
            counter++;
            for (auto a: path) {
                cout << " " << a;
            }
            cout << ": counter = " << counter << endl;
            return;
        }

        for (int i = curIdx; i < coins.size(); i++)
        {
            path.push_back(coins[i]);
            for (auto a: path) {
                if (a > 0)
                cout << " " << a;
            }
            cout << endl;
            cout << ": target = " << target << ", coins[" << i << "] = " << coins[i] << endl;
            if (target - coins[i] < 0) {
                continue;
            }
            bc(coins, target - coins[i], i, ans, move(path));
            path.pop_back();
        }
    }
};
