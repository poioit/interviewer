

/* ============================================================================
112. Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf
path such that adding up all the values along the path equals the given sum.

113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
https://leetcode.com/problems/path-sum-ii/description/
============================================================================ */
// Trick:
// 1. Path always start from root, solve subproblem of finding sum - root->val in left/right child.
// 2. Traverse the whole tree once, no helper function needed.
// 3. Pass rst vector as reference, and another vector for recording current path from root to current node.

// O(n) time: traverse the tree
// O(n^2) space: rst might include whole tree

/* ============================================================================
437. Path Sum III
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
https://leetcode.com/problems/path-sum-iii/description/
============================================================================ */
// 1. Traverse the tree, pass to helper.
// 2. A helper to find path sum that must start from current node. (no need to end in leaf)

    // O(nlogn) time: suppose tree is balanced, otherwise mighe be O(n^2)
    // O(n) space