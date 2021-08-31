https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=inorder.size()-1;i>=0;i--)
            mpp[inorder[i]]=i;
        
        TreeNode* root= build(postorder,0,postorder.size()-1,
                    inorder,0,inorder.size()-1,
                    mpp);
        return root;
    }
    
    TreeNode* build(vector<int>& postorder,int pl,int pr,
                    vector<int>& inorder,int il,int ir,
                    map<int,int>& mpp){
        if(pl>pr || il>ir)
            return NULL;
        
        TreeNode* root=new TreeNode(postorder[pr]);
        int inroot=mpp[root->val];
        int inleft=inroot-il;
        
        root->left=build(postorder,pl,pl+inleft-1,inorder,il,inroot-1,mpp);
        root->right=build(postorder,pl+inleft,pr-1,inorder,inroot+1,ir,mpp);
        
        return root;
    }
};