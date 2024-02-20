void preorderUtils(TreeNode *root, vector<int> &ans){
    if(!root) return;

    preorderUtils(root -> left, ans);
    preorderUtils(root -> right, ans);
    ans.push_back(root -> data);

}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>ans;
    preorderUtils(root, ans);
    return ans;
}

//method: 2

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Create answer array to store traversal.
    vector<int> answer;

    // Base case.
    if (root == NULL)
    {
        return answer;
    }

    // Create an empty stack.
    stack<TreeNode *> s;
    TreeNode *current = root;

    // Push current node to stack.
    s.push(current);

    // Run a loop until stack is not empty.
    while (!s.empty())
    {

        // Pop a node from 'S'.
        current = s.top();
        s.pop();

        // Add data of popped node to 'ANSWER'.
        answer.push_back(current->data);

        // Push left child of current node  to stack.
        if (current->left)
        {
            s.push(current->left);
        }

        // Push right child of current node  to stack.
        if (current->right)
        {
            s.push(current->right);
        }
    }

    // Reverse all elements of 'ANSWER' array.
    reverse(answer.begin(), answer.end());

    // Return answer.
    return answer;
}