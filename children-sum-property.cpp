https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL) return;
    int l=0,r=0;
    if(root->left) l=root->left->data;
    if(root->right) r=root->right->data;
    
    if(l+r==0)
    {
        return;
    }
    if(root->data>l+r)
    {
        if(l!=0)
            root->left->data+=root->data-l-r;
        else
            root->right->data+=root->data-l-r;
    }
    changeTree(root->left);
    changeTree(root->right);
    
    l=0,r=0;
    if(root->left) l=root->left->data;
    if(root->right) r=root->right->data;
    
    root->data=l+r;
}  
