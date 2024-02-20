vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.size()) {
        int i, n=q.size();
        for(i=0;i<n;i++) {
            root=q.front(); q.pop();
            if(i==0) ans.push_back(root->data); // i = n - 1 for right view
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
    }
    return ans;
}