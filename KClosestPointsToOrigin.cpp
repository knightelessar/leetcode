class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [](vector<int>& left, vector<int>& right) {
            float distLeft = sqrt(pow(left[0], 2) + pow(left[1], 2));
            float distRight = sqrt(pow(right[0], 2) + pow(right[1], 2));
            return distLeft < distRight;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> closestPoints(cmp);
        for (vector<int> p: points) {
            closestPoints.push(p);
            if (closestPoints.size() > K) {
                closestPoints.pop();
            }
        }
        
        vector<vector<int>> smallestK;
        for (int i{0}; i < K; ++i) {
            smallestK.push_back(closestPoints.top());
            closestPoints.pop();
        }
        
        return smallestK;
    }
};
