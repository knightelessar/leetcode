class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](const vector<int>& left, const vector<int>& right) {
            return left[0] != right[0] ? (left[0] < right[0]) : (left[1] < right[1]);
        };
        sort(begin(people), end(people), cmp);
        
        vector<int> remPos;
        for (int i{0}; i < people.size(); ++i) {
            remPos.push_back(i);
        }
        vector<vector<int>> result(people.size(), vector<int>());
        int sameHeight = 0;
        int prevH = -1;
        for (auto p: people) {
            if (prevH == p[0]) {
                sameHeight++;
            }
            else {
                sameHeight = 0;
            }
            int relInd = p[1] - sameHeight;
            int pos = remPos[relInd];
            remPos.erase(begin(remPos) + relInd);
            result[pos] = p;
            prevH = p[0];
        }
        return result;
    }
};
