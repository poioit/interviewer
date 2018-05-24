// Keys:
// 1. Recursive: judge nodes existance in left/right tree, base on current root.
// 2. Iterative:

//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
// For BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL)
            return NULL;
        // LCA is in the left subtree
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        // LCA is in the right subtree
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};


//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// For general binary tree
class Solution {
public:
    // if p or q is not in the tree
    // simply do LCA will be wrong
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL)
            return NULL;
        // check both p & q are in the tree
        if (!exist(root, p) || !exist(root, q))
            return NULL;
        return LCA(root, p, q);
    }
    
    bool exist(TreeNode *root, TreeNode *n) {
        if (root == NULL)
            return false;
        if (root == n)
            return true;
        return exist(root->left, n) || exist(root->right, n);
    }
    
    TreeNode * LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)
            return root;
        TreeNode *l = LCA(root->left, p, q);
        TreeNode *r = LCA(root->right, p, q);
        if (l && r)
            return root;
        else if (l)
            return l;
        else
            return r;
    }
};