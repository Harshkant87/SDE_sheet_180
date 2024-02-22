TreeNode *preToBST(vector<int> &preOrder, int max_val, int &index){
    if(index == preOrder.size() || preOrder[index] > max_val)
        return NULL;
    
    TreeNode *root = new TreeNode(preOrder[index++]);
    root -> left = preToBST(preOrder, root -> data, index);
    root -> right = preToBST(preOrder, max_val, index);

    return root;

}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int index = 0;
    return preToBST(preOrder, INT_MAX, index);

}