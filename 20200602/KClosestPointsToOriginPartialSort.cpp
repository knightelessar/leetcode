class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        psort(points, 0, points.size() - 1, K);
        vector<vector<int>> res;
        for (int i{0}; i < K ; ++i) {
            res.push_back(points[i]);
        }
        return res;
    }
    
    void psort(vector<vector<int>>& arr, int i, int j, int K) {
        if (i >= j) {
            return;
        }
        
        // select a k using your favorite method
        int k = (i + j) / 2;
        swap(arr[i], arr[k]);
        // now [e_pivot, i+1, ..., oi, ..., j]
        int mid = partition(arr, i, j);
        int leftLength = mid - i + 1;
        // now [i, ..., mid, mid + 1, ..., j]
        // where i, ..., mid - 1 <= mid
        // where mid <= mid + 1, ..., j
        // where mid is the pivot
        // i.e.[i, ..., e_pivot, mid + 1, ..., j]
        if (K > mid - i + 1) {
            // have mid - i + 1 psorted, need K in total, 
            // need K - mid + i - 1 more,
            psort(arr, mid + 1, j, K - mid + i - 1);
        }
        else {
            psort(arr, i, mid, K);
        }
    }
    
    /*
     * first elem is the pivot
     * partition the array from i+1 to j inclusive, [i+1, j]
     * so that [i+1, mid] is less than pivot, [mid + 1, j] is ge pivot
     * swap i with mid, so mid is pivot, then return mid
     */
    int partition(vector<vector<int>>& arr, int i, int j) {
        int oi{i};
        int pivot{dist(arr[oi])};
        while (true) {
            while (i < j && dist(arr[i]) < pivot) {
                ++i;
            }
            while (j >= i && j > oi && dist(arr[j]) >= pivot) {
                --j;
            }
            if (i >= j) {
                break;
            }
            swap(arr[i], arr[j]);
        }
        swap(arr[oi], arr[j]);
        return j;
    }
    
    int dist(const vector<int>& p) {
        return p[0]*p[0] + p[1]*p[1];
    }
};