https://www.interviewbit.com/problems/path-to-given-node/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void fun(TreeNode* root,int b,vector<int>& ans,int& f)
{
    if(root==NULL)
        return;
    if(root->val==b)
        f=1;
    if(f==0)
        fun(root->left,b,ans,f);
    if(f==0)
        fun(root->right,b,ans,f);
    if(f==1)
        ans.push_back(root->val);

}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    int f=0;
    fun(A,B,ans,f);
    reverse(ans.begin(),ans.end());
    return ans;
}
