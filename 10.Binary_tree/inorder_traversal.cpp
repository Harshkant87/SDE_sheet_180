void inorderUtils(TreeNode *root, vector<int>&ans){
    if(root == NULL) return ;

    inorderUtils(root -> left, ans);
    ans.push_back(root -> data);
    inorderUtils(root -> right, ans);

}


vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>ans;
    inorderUtils(root, ans);
    return ans;
}

//iterative solution

vector<int> getInOrderTraversal(TreeNode *root)
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

    // Initialize current node as 'ROOT'.
    TreeNode *current = root;

    // Run a loop until 'CURRENT'!= NULL or stack is not empty.
    while (current != NULL || s.empty() == false)
    {
        while (current != NULL)
        {
            // Push current node to stack.
            s.push(current);

            // Move to left subtree of 'CURRENT'.
            current = current->left;
        }

        // 'CURRENT' must be NULL at this point.
        current = s.top();

        // Pop top node from stack.
        s.pop();

        // Add data of popped node to answer.
        answer.push_back(current->data);

        // Visit right subtree of current node.
        current = current->right;
    }

    // Return answer.
    return answer;
}