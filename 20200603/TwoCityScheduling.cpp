class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto cmp = [](const vector<int>& left, const vector<int>& right) {
            return left[0] - left[1] < right[0] - right[1];
        };
        sort(costs.begin(), costs.end(), cmp);
        int sum{0};
        for (int i = 0; i < costs.size() / 2; ++i) {
            sum += costs[i][0];
            sum += costs[i + costs.size()/2][1];
        }

        return sum;
    }
};
