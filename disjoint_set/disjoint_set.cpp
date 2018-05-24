//https://leetcode.com/problems/similar-string-groups/description/
/*
1. N sets
2. path compression
3. union two sets
*/


class Solution {
    bool isSimilar(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                diff++;
            if (diff > 2)
                return false;
        }
        return diff == 2;
    }
    
    int findRoot(vector<int> &parent, int r) {
        // this does path compression, which is faster
        if (parent[r] != r) {
            parent[r] = findRoot(parent, parent[r]);
        }
        return parent[r];
    }
public:
    
    // disjoint sets
    int numSimilarGroups(vector<string>& A) {
        vector<int> parent(A.size());
        // initialize as N sets
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;
        int setCount = A.size();
        for (int i = 1; i < A.size(); i++) {
            int group = -1;
            for (int j = 0; j < i; j++) {
                if (isSimilar(A[i], A[j])) {
                    // union two disjoint sets
                    int r1 = findRoot(parent,i);
                    int r2 = findRoot(parent,j);
                    if (r1 != r2) {
                        parent[r1] = r2;
                        setCount--;
                    }
                }
            }
        }
        return setCount;
    }
};