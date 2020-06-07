class Solution {
public:
    unordered_map<int, unordered_map<int, int>> ways; // key: rest, value: pair<currCoin, nWays>
    int change(int amount, vector<int>& coins) {
        // Sort the coins in ascending order
        sort(begin(coins), end(coins), greater());
        return nValidChange(amount, coins, 0, coins.size() - 1);
    }
    
    int nValidChange(int rest, vector<int>& coins, size_t coinType, size_t lastCoinType) {
        if (coinType > lastCoinType || coins.empty()) {
            // Out of coin type
            return rest == 0 ? 1 : 0;
        }
        else if (coinType == lastCoinType) {
            // Last (smallest coin type)
            return rest % coins[coinType] == 0 ? 1 : 0;
        }
        
        if (ways.find(rest) != ways.end()) {
            if (ways[rest].find(coinType) != ways[rest].end())
            return ways[rest][coinType];
        }

        int nWay = 0;
        int maxCoinType = rest / coins[coinType];
        
        for (int i = maxCoinType; i >= 0; --i) {
            nWay = nWay += nValidChange(rest - i * coins[coinType],
                                        coins,
                                        coinType + 1,
                                        lastCoinType);
        }
        if (ways.find(rest) == ways.end() || ways[rest].find(coinType) == ways[rest].end()){
            ways[rest][coinType] = nWay;
        }
        return nWay;
    }
};
