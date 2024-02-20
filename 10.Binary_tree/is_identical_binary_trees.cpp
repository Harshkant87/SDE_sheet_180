bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.
    if(root1 == NULL && root2 == NULL)
        return true;
    else if(root1 == NULL || root2 == NULL)
        return false;

    bool checkLeft = identicalTrees(root1 -> left, root2 -> left);
    bool checkRight = identicalTrees(root1 -> right, root2 -> right);

    return root1 -> data == root2 -> data && checkLeft && checkRight;	 
}