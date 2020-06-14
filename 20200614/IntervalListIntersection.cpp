// 986. Interval List Intersections
class Solution {
    // Start1 12:43 pm - end1 13:37 pm, hint at 13:37 pm, start2 13:37 pm - 13:54 pm fail
    // 13:55 pm - 14:05 pm look at solution
    // 14:05 - 14:12 pm put away solution and try to implement
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> intersections;
        size_t i{0}, j{0};

        while (i < A.size() && j < B.size())
        {
            int low = max(A[i][0], B[j][0]);
            int high = min(A[i][1], B[j][1]);

            if (low <= high)
            {
                vector<int> inter{low, high};
                intersections.push_back(inter);
            }
            
            if (A[i][1] < B[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return intersections;
    }
};