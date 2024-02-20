int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root == NULL) return 0;
    int count = 0, ans = INT_MIN;
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode<int> *top = q.front();
        q.pop();
        if(top == NULL){
            if(q.empty()) return ans = max(ans,count);
            ans = max(ans,count);
            count = 0;
            q.push(NULL);
        }
        else{
            count++;
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
    }
    return ans;
}