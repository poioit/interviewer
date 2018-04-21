/**
https://leetcode.com/problems/validate-binary-search-tree/description/

Two kind to thoughts, both useful:
1. Validate relation between current node and previous node.
2. Recursion: validate the min ~ max range of left/right subtree,
   start with INT_MIN ~ INT_MAX on root.
 */



class Solution {
public:
    // recursive solution
    TreeNode *pre = nullptr;
    bool isValidBST0(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (pre) {
            if (pre->val >= root->val)
                return false;
            else {
                pre = root;
            }
        }
        else
            pre = root;
        if (!isValidBST(root->right))
            return false;
        return true;
    }
    
    
    // this allows duplicate but will fail this problem, because of problem definition
    // but this is useful in many other problems
    bool isValidBST1(TreeNode* root) {
        if (root == NULL)
            return true;
        return validate(root, INT_MIN, INT_MAX);
    }
    bool validate(TreeNode *root, int l, int r) {
        if (root == NULL)
            return true;
        if (root->val > l && root->val <= r)
            return validate(root->left, l, root->val) && validate(root->right, root->val, r);
        else
            return false;
    }
    
    
    // optimal iterative from dicussion
    // when duplicates allows, this is wrong
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> stk;
        TreeNode *pre = nullptr;
        while (root != nullptr || stk.size() > 0) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                root = stk.top();
                stk.pop();
                if (pre && pre->val >= root->val)
                    return false;
                pre = root;
                root = root->right;
            }
        }
        return true;
    }
#endif
};