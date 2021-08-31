https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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
    
    // Sets parent for every node
    void findpar(TreeNode* root,map<TreeNode*,TreeNode*>& par)
    {
        if(root->left!=NULL)
        {
            par[root->left]=root;
            findpar(root->left,par);
        }
        if(root->right!=NULL)
        {
            par[root->right]=root;
            findpar(root->right,par);
        }
    }
    
    // Adds the K-th node to the answer vector
    void nodeK(TreeNode* root,map<TreeNode*,TreeNode*> par,map<TreeNode*,bool> vis,vector<int>& ans,int k)
    {
        vis[root]=true;
        if(k==0)
        {
            ans.emplace_back(root->val);
            return;
        }
        if(vis.find(root->left)==vis.end())nodeK(root->left,par,vis,ans,k-1);
        if(vis.find(root->right)==vis.end())nodeK(root->right,par,vis,ans,k-1);
        if(vis.find(par[root])==vis.end())nodeK(par[root],par,vis,ans,k-1);
    }
    
    // Answer function
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        map<TreeNode*,TreeNode*> par;
        map<TreeNode*,bool> vis;
        par[root]=NULL;
        vis[NULL]=true;
        findpar(root,par);
        vector<int> ans;
        
        nodeK(target,par,vis,ans,k);
        return ans;
    }
};