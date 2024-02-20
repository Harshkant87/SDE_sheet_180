TreeNode<int> *Utils(TreeNode<int> *root, int x, int y){

    if(root == NULL || root -> data == x || root -> data == y){
        return root;
    }

    TreeNode<int> *left = Utils(root -> left, x, y);
    TreeNode<int> *right = Utils(root -> right, x, y);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;

}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    TreeNode<int> *lca = Utils(root, x, y);
    return lca -> data;

}