void preorderUtils(TreeNode *root, vector<int>&ans){
    if(!root)
        return;
    ans.push_back(root -> data);
    preorderUtils(root -> left, ans);
    preorderUtils(root -> right, ans);

}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>ans;
    preorderUtils(root, ans);
    return ans;
}

//method:2 

vector<int> getPreOrderTraversal(TreeNode *root)
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

    // Push 'ROOT' to stack.
    s.push(root);

    // Run a loop until stack is not empty.
    while (s.empty() == false)
    {

        // Get the top node from stack.
        TreeNode *node = s.top();

        // Add data of top node to 'ANSWER'.
        answer.push_back(node->data);

        // Pop the top node.
        s.pop();

        // Push right subtree of node to stack.
        if (node->right)
        {
            s.push(node->right);
        }

        // Push left subtree of node to stack.
        if (node->left)
        {
            s.push(node->left);
        }
    }

    // Return answer.
    return answer;
}