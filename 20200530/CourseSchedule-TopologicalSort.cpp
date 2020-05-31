struct GNode {
    int indegree;
    list<int> outnodes;
    GNode() : indegree(0), outnodes(list<int>()){}
};

class Solution {
    // Approach 3: Topological Sort
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int nTotalEdges = static_cast<int>(prerequisites.size());
        
        // Build the graph
        unordered_map<int, shared_ptr<GNode>> graph;
        for (vector<int> dep: prerequisites) {
            shared_ptr<GNode> prevNode = getCreateGNode(graph, dep[1]);
            shared_ptr<GNode> nextNode = getCreateGNode(graph, dep[0]);
            prevNode->outnodes.push_back(dep[0]);
            nextNode->indegree ++;
        }

        // Find initial no dependency courses
        list<int> noDepCourses;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            if (it->second->indegree == 0) {
                noDepCourses.push_back(it->first);
            }
        }
        
        int nRemovedEdges{0};
        while (noDepCourses.size() > 0) {
            // Pop the no income edge node into list L, here L is the void
            // since we don't need to return the topological order
            int course = noDepCourses.back();
            noDepCourses.pop_back();
            for (int nei: graph[course]->outnodes) {
                graph[nei]->indegree --;
                nRemovedEdges ++;
                if (graph[nei]->indegree == 0) {
                    noDepCourses.push_back(nei);
                }
            }
        }
        
        if (nRemovedEdges == nTotalEdges) {
            // no cycles
            return true;
        }
        else {
            return false;
        }
    }
    
    shared_ptr<GNode> getCreateGNode(unordered_map<int, shared_ptr<GNode>> &graph, int node) {
        if (graph.find(node) == graph.end()) {
            graph[node] = shared_ptr<GNode>(new GNode);
        }
        return graph[node];
    }
};