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

    /* 
     * Mincan's back track routine
     * For number of valid combinations, we do not need to save the path.
     */
    void bc(vector<int> &coins, int target, int curIdx, vector<vector<int>> &ans, vector<int> &&path = {})
    {
        if (target == 0)
        {
            ans.push_back(path);
            counter++;
            return;
        }

        for (int i = curIdx; i < coins.size(); i++)
        {
            path.push_back(coins[i]);
            if (target - coins[i] < 0)
            {
                continue;
            }
            bc(coins, target - coins[i], i, ans, move(path));
            path.pop_back();
        }
    }
};
