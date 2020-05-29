class Solution {
public:
    vector<int>** graph;
    unordered_map<int, int> colorMask;

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // Initialize graph of people nodes
        graph = new vector<int>*[N+1];
        for (int i = 1; i <= N; ++i) {
            graph[i] = new vector<int>;
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
                cout << "Initial blue node: " << node << endl;
                return false;
            }
        }
        return true;
    }
    
    bool paintFirstNodeBlueAndItsNeighbourWithAlternateColorDFS(int node, int c) {
        if (colorMask.find(node) != colorMask.end()) {
            // Color mask does already contain the node
            if (node == 2) {
                cout << "Initial chain node 2 has color: " << colorMask[2] << ", new color: " << c << endl;
            }
            return colorMask[node] == c;
        }
        colorMask.insert({node, c});
        
        for (int nei: *graph[node]) {
            if (nei == 41 && node == 2) {
                cout << "Chain initial node 2 with indirect Nei node 41: " << endl;
            }
            if(!paintFirstNodeBlueAndItsNeighbourWithAlternateColorDFS(nei, c ^ 1)) {
                cout << "Chain initial node: " << node << ", " << "new color: " << c << ", " << "current nei node: " << nei << ", current color: " << colorMask[nei] << ", new color: " << (c ^ 1) << endl;
                return false;
            }
        }
        return true;
    }
};