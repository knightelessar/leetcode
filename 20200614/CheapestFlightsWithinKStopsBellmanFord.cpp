class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // K stops means K+1 Bellman Ford iterations over the edge list
        // Bellman Ford should use V - 1 iterations, 
        // After V - 1, it gives incorrect shortest distances when negative cycles exist.
        // Here V = n. K <= n - 1. So K+1 <= n, so K+1 <= V, the last iteration is valid
        // since the problem guarantees no self cycles.
        
        // Note vector<int> (N_SIZE, INIT_VAL)
        vector<int> dist(n, numeric_limits<int>::max());
        dist[src] = 0;
        
        for (size_t i{0}; i < K + 1; ++i)
        {
            vector<int> tmp = dist;
            for (auto& edge: flights)
            {
                int u = edge[0], v = edge[1], uv = edge[2];
                // Note: query the old incoming node info from dist,
                // query and update the new temp copy for the current dst node.
                if (dist[u] != numeric_limits<int>::max() && dist[u] + uv < tmp[v])
                {
                    tmp[v] = dist[u] + uv;
                }
            }
            dist = tmp;
        }
        
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};

