
leaf node: both left and right child are NULL

/* ============================================================================
207. Course Schedule
https://leetcode.com/problems/course-schedule/description/
============================================================================ */

// Check if cycle exist in directed graph,
// need two array to record visited
// one is permanent, one is dynamic

class Solution {
public:
    // DFS
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> edge(numCourses);
        for (auto p : prerequisites) {
            edge[p.second].insert(p.first);
        }
        vector<bool> visit(numCourses, false);
        vector<bool> path(numCourses, false); // this is very important!
        
        for (int i = 0; i < numCourses; ++i) {
            if (visit[i] == false && cycle(i, edge, visit, path) == true)
                return false;
        }
        return true;
    }
 private:   
    bool cycle(int n, vector<unordered_set<int>> &edge, vector<bool> &visit, vector<bool> &path) {
        if (visit[n])
            return false;
        visit[n] = true;
        path[n] = true; // mark visted
        for (int e : edge[n]) {
            if (path[e] || cycle(e, edge, visit, path))
                return true;
        }
        path[n] = false; // unmarked visisted
        return false;
    }
};

/* ============================================================================
[LeetCode] Graph Valid Tree 图验证树

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
write a function to check whether these edges make up a valid tree.
============================================================================ */
http://www.cnblogs.com/grandyang/p/5257919.html