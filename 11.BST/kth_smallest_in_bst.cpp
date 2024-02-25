void findK(TreeNode<int> *root,int &k,int &count,int &ans)
{

    if(!root) return ;

    findK(root->left,k,count,ans);
    count++;
    if(count==k)
    {
        ans = root->data;
        return ;
    }
    findK(root->right,k,count,ans);

}

 

int kthSmallest(TreeNode<int> *root, int k)
{
    int ans=0;
    int count=0;
    findK(root,k,count,ans);
    return ans;

}