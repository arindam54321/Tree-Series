https://leetcode.com/problems/symmetric-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return fun(root,root);
    }
    
    // check if two tree are opposite of each other
    bool fun(TreeNode* l,TreeNode* r)
    {
        if(l==NULL||r==NULL)
            return l==r;
        
        if(l->val!=r->val)
            return false;
        
        return fun(l->left,r->right)&&fun(l->right,r->left);
    }
};