https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rec(root,0,ans);
        return ans;
    }
    
    void rec(TreeNode* root,int l,vector<int>& ans)
    {
        if(root==NULL)
            return;
        if(l==ans.size())
            ans.emplace_back(root->val);
        
        rec(root->right,l+1,ans);
        rec(root->left,l+1,ans);
    }
};