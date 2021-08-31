https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        TreeNode* t;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int ans=0,mn,sz,l,r,cur;
        while(!q.empty())
        {
            sz=q.size();
            mn=q.front().second;
            for(int i=0;i<sz;i++)
            {
                cur=q.front().second-mn;
                if(i==0) l=cur;
                if(i==sz-1) r=cur;
                t=q.front().first;
                q.pop();
                if(t->left) q.push({t->left,cur*2+1});
                if(t->right) q.push({t->right,cur*2+2});
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};