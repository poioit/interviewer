// This structure might apply to many other backtracking questions,
// but here I am just going to demonstrate Subsets, Permutations, and Combination Sum.
// https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c++-solution-use-backtracking-easy-understand.
// https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)

// 40. Combination Sum II
/*
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

 https://leetcode.com/problems/combination-sum-ii/description/
*/
    vector<vector<int>> combinationSum2(vector<int>& can, int t) {
        vector<vector<int>> rst;
        vector<int> path;
        sort(can.begin(), can.end());
        find(can, 0, t, path, rst);
        return rst;
    }
    void find(vector<int> &can, int s, int t, vector<int> &path, vector<vector<int>> &rst) {
        if (t == 0) {
            rst.push_back(path);
            return;
        }
        for (int i = s; i < can.size() && can[i] <= t; i++) {
            path.push_back(can[i]);
            // skip the same starting candidates,
            // will this miss some combin.? no
            // [(1),1,1,2,2,2]
            // all combinations start at 1 are found when recurse into the first 1
            if (i == s || can[i] != can[i-1])
                find(can, i + 1, t - can[i], path, rst);
            path.pop_back();
        }
    }