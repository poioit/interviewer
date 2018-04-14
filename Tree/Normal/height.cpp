
leaf node: both left and right child are NULL

/* ============================================================================
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
============================================================================ */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
#if 1
    // DFS
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        int rst = INT_MAX;
        if (root->left)
            rst = min(rst, minDepth(root->left));
        if (root->right)
            rst = min(rst, minDepth(root->right));
        return rst + 1;
    }
#else
    // BFS
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        int rst = 0;
        q.push(root);
        while (q.size() > 0) {
            rst++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *n = q.front();
                q.pop();
                if (n->left == NULL && n->right == NULL)
                    return rst;
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
            
        }
        return rst;
    }
#endif
};

/* ============================================================================
104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
============================================================================ */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
#if 1
    // DFS
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
#else
    // BFS
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        int rst = 0;
        q.push(root);
        while (q.size() > 0) {
            rst++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *n = q.front();
                q.pop();
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
        }
        return rst;
    }
#endif
};