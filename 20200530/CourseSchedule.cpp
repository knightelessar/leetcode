class Solution {
    // DFS solution based on O(V^2 + E) backtrack
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build directed graph as adjacency list in a dictionary
        // direction is prerequisite A -> dependent B
        unordered_map<int, vector<int>> courseDict;
        for (vector<int> pair: prerequisites) {
            // pair[0] depends on (is prerequisite of) pair[1]
            // node pair[0] <- node pair[1], course pair[1] has next course pair[0]
            // key: pair[1] -> adjacency list [pair[0]]
            if (courseDict.find(pair[1]) != courseDict.end()) {
                // node pair[1] found in courseDict
                courseDict[pair[1]].push_back(pair[0]);
            }
            else {
                courseDict[pair[1]] = vector<int>{pair[0]};
            }
        }

        bool path[numCourses];
        bool checked[numCourses];
        for (int i {0}; i < numCourses; ++i) {
            path[i] = 0;
            checked[i] = 0;
        }
        // check all the course nodes see if start from 1 we can finish
        for (int course{0}; course < numCourses; ++course) {
            if (isCyclic(course, courseDict, checked, path)) {
                return false;
            }
        }
        return true;
    }
    
    /* 
     * using breadcrumb in the path, start from a course node, 
     * incrementally follow the path by backtracking
     * enhanced by avoiding revisiting checked nodes, so post order
     * child 1 -> child 2 -> ... -> self node visiting will not revist
     * checked nodes
     * Failed candidate is in the sense of cyclic, returning true.
     * Good candidate is one node with acyclic sub graph, returning false.
     */
    bool isCyclic(int course,
                  unordered_map<int, vector<int>>& courseDict,
                  bool checked[],
                  bool path[]) {
        
        // if checked the node has no cyclic sub nodes, it is a good candidate
        if (checked[course] == true) {
            return false;
        }
        
        // failed candidate solution criteron to start backtrack (abondon the invalid)
        if (path[course] == true) {
            return true;
        }
        
        // valid candidate, no more next course
        if (courseDict.find(course) == courseDict.end()) {
            return false;
        }
        
        // before backtrack, leave a breadcrumb in the path
        path[course] = true;
        
        bool hasRevisited = false;
        // build all solutions from the initial course node incrementally
        for (int nextCourse: courseDict[course]) {
            hasRevisited = isCyclic(nextCourse, courseDict, checked, path);
            // stop (backtrack) when a node is revisited
            if (hasRevisited == true) {
                break;
            }
        }
        
        // clear the breadcrumb
        path[course] = false;

        // we have not revisted any sub graph child node before processing self
        // in post order DFS
        // thus self node is checked
        // as no sub graph is cyclic
        checked[course] = true;

        return hasRevisited;
    }
};