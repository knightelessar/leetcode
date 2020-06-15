using nodeStopPair = pair<int, int>;
bool operator==(const nodeStopPair& lhs, const nodeStopPair& rhs) {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}
template<> struct hash<nodeStopPair>
    {
        std::size_t operator()(nodeStopPair const& s) const noexcept
        {
            std::size_t h1 = hash<int>{}(s.first);
            std::size_t h2 = hash<int>{}(s.second);
            return h1 ^ (h2 << 1);
        }
    };

class Solution {// Start1 15:49 - end1 16:26
    // look at solution 16:27 - 17:24
    // Watched two YouTube single-source graph shortest path problem videos
    // 4.4 Bellman Ford Algorithm - Single Source Shortest Path - Dynamic Programming
    // https://www.youtube.com/watch?v=FtN3BYH2Zes
    // 3.6 Dijkstra Algorithm - Single Source Shortest Path - Greedy Method
    // https://www.youtube.com/watch?v=XB4MIexjvY0
    // keep looking at solution 18:15 - 19:18
    // modifying BFS answer from Java to C++ 19:30 - 20:00 and 22:23 - 23:00
    // debug 12:30 - 13:02 next day
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Build the adjacency matrix
        int adjMatrix[n][n];
        for (size_t r{0}; r < n; ++r)
        {
            for (size_t c{0}; c < n; ++c)
            {
                adjMatrix[r][c] = 0;
            }
        }

        for (auto flight: flights) {
            adjMatrix[flight[0]][flight[1]] = flight[2];
        }

        // Shortest distances dictionary
        unordered_map<nodeStopPair, long int> distances;
        distances[nodeStopPair(src, 0)] = 0;

        int stops = 0;
        long int ans = numeric_limits<long int>::max();

        queue<int> bfsQ;
        bfsQ.push(src);

        while(!bfsQ.empty() && stops < K + 1)
        {
            // Loop over current stop level
            int length = bfsQ.size();
            for (int i{0}; i < length; ++i)
            {
                assert(!bfsQ.empty());
                int node = bfsQ.front();
                bfsQ.pop();
                for (int nei{0}; nei < n; ++nei)
                {
                    assert(node < n && nei < n && "array out of bound");
                    if (adjMatrix[node][nei] > 0)
                    {
                        long int dU{0}, dV{0};
                        if (distances.find(nodeStopPair(node, stops)) != distances.end())
                        {
                            dU = distances[nodeStopPair(node, stops)];
                        }
                        else
                        {
                            dU = numeric_limits<long int>::max();
                            distances[nodeStopPair(node, stops)] = dU;
                        }

                        if (distances.find(nodeStopPair(nei, stops+1)) != distances.end())
                        {
                            dV = distances[nodeStopPair(nei, stops+1)];
                        }
                        else
                        {
                            dV = numeric_limits<long int>::max();
                            distances[nodeStopPair(nei, stops+1)] = dV;
                        }

                        assert(node < n && nei < n);
                        long int wUV = adjMatrix[node][nei];

                        if (stops == K && nei != dst)
                        {
                            continue;
                        }

                        if (dU + wUV < dV)
                        {
                            distances[nodeStopPair(nei, stops+1)] = dU + wUV;
                            bfsQ.push(nei);

                            if (nei == dst)
                            {
                                ans = min(ans, dU + wUV);
                            }
                        }
                    }
                }
            }
            stops++;
        }
        return (ans == numeric_limits<long int>::max()) ? -1 : static_cast<int>(ans);
    }
};
