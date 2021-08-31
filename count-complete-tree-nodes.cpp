https://leetcode.com/problems/count-complete-tree-nodes/
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
    int countNodes(TreeNode* root) {
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh)
            return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    int leftheight(TreeNode* root)
    {
        int c=0;
        while(root)
            c++,root=root->left;
        return c;
    }
    
    int rightheight(TreeNode* root)
    {
        int c=0;
        while(root)
            c++,root=root->right;
        return c;
    }
};