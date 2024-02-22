TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if (root->data < P->data && root->data < Q->data)
    {
        // Moving towards right.
        return LCAinaBST(root->right, P, Q);
    }

    if (root->data > P->data && root->data > Q->data)
    {
        // Moving towards left.
        return LCAinaBST(root->left, P, Q);
    }

    return root;
}