class Solution {
public:
    shared_ptr<shared_ptr<vector<int>>> graph;
    unordered_map<int, int> colorMask;

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // Initialize graph of people nodes
        graph = shared_ptr<shared_ptr<vector<int>>[]>(new shared_ptr<vector<int>>[N+1]);
        for (int i = 1; i <= N; ++i) {
            graph[i] = shared_ptr<vector<int>>(new vector<int>);
        }
        
        // Draw the edges between the nodes
        for (int i = 0; i < dislikes.size(); ++i) {
            graph[dislikes[i][0]]->push_back(dislikes[i][1]);
            graph[dislikes[i][1]]->push_back(dislikes[i][0]);
        }

        // Try paint all nodes with alternating colors
        for (int node {1}; node <= N; ++node) {
            if (colorMask.find(node) == colorMask.end()
                && !paintFirstNodeBlueAndItsNeighbourWithAlternateColorDFS(node, 0)) {
                return false;
            }
        }
        return true;
    }
    
    bool paintFirstNodeBlueAndItsNeighbourWithAlternateColorDFS(int node, int c) {
        if (colorMask.find(node) != colorMask.end()) {
            // Color mask does already contain the node
            if (node == 2) {
            }
            return colorMask[node] == c;
        }
        colorMask.insert({node, c});
        
        for (int nei: *graph[node]) {
            if (nei == 41 && node == 2) {
            }
            if(!paintFirstNodeBlueAndItsNeighbourWithAlternateColorDFS(nei, c ^ 1)) {
                return false;
            }
        }
        return true;
    }
};