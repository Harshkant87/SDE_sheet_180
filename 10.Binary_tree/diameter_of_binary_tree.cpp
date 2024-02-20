int diameterUtils(TreeNode<int> *root, int &diameter){
    if(!root)
        return 0;
    
    int lh = diameterUtils(root -> left, diameter);
    int rh = diameterUtils(root -> right, diameter);

    diameter = max(diameter, lh + rh);
    return 1 + max(lh,rh);

}


int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    int diameter = -1;
    diameterUtils(root, diameter);
    return diameter;
}