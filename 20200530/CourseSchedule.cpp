class Solution {
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
        for (int i {0}; i < numCourses; ++i) {
            path[i] = 0;
        }
        // check all the course nodes see if start from 1 we can finish
        for (int course{0}; course < numCourses; ++course) {
            if (isCyclic(course, courseDict, path)) {
                return false;
            }
        }
        return true;
    }
    
    /* 
     * using breadcrumb in the path, start from a course node, 
     * incrementally follow the path by backtracking
     */
    bool isCyclic(int course, unordered_map<int, vector<int>>& courseDict, bool path[]) {
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
            hasRevisited = isCyclic(nextCourse, courseDict, path);
            // stop (backtrack) when a node is revisited
            if (path[nextCourse] == true) {
                break;
            }
        }
        
        // clear the breadcrumb
        path[course] = false;
        
        return hasRevisited;
    }
};