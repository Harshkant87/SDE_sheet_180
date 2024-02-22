bool isSymUtil(TreeNode<int> *root1, TreeNode<int> *root2){
    if(root1 == NULL || root2 == NULL)
        return root1 == root2;
    
    return (root1 -> data == root2 -> data) && isSymUtil(root1 -> left, root2 -> right) && isSymUtil(root1 -> right, root2 -> left);
}

bool isSymmetric(TreeNode<int> *root)
{
    // Write your code here
    if(root == NULL) return true;
    return isSymUtil(root -> left, root -> right);
}