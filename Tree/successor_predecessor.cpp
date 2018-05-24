//https://leetcode.com/problems/inorder-successor-in-bst/description/



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
    
    // the is for general tree, will traverse all nodes before p
    TreeNode* inorderSuccessor0(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        bool found = false;
        while(root || stk.size() > 0) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                TreeNode *n = stk.top();
                stk.pop();
                if (found) {
                    return n;
                }
                if (n == p) {
                    found = true;
                }
                root = n->right;
            }
        }
        return NULL;
    }
    
    // iterative for BST
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *suc = NULL;
        
        while (root) {
            if (p->val < root->val) {
                suc = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        
        return suc;
    }
    // Recursive for BST
    TreeNode* inorderSuccessor2(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL)
            return NULL;
        if (p->val < root->val) {
            TreeNode* l = inorderSuccessor(root->left, p);
            if (l)
                return l;
            return root;
        }
        else {
            return inorderSuccessor(root->right, p);
        }
    }
    
    
    // predecessor
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL)
            return NULL;
        if (p->val < root->val) {
            return inorderPredecessor(root->left, p);
        }
        else {
            TreeNode *r = inorderPredecessor(root->right, p);
            if (r)
                return r;
            return root;
        }
    }
};