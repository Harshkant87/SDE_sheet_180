int isBalancedBTUtil(TreeNode<int>* root){

    if(!root) return 0;
    
    int left = isBalancedBTUtil(root -> left);
    if(left == -1)
    return -1;

    int right = isBalancedBTUtil(root -> right);
    if(right == -1)
    return -1;

    if(abs(left - right) > 1)
    return -1;

    return max(left, right) + 1;

}


bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.

    return isBalancedBTUtil(root) != -1;


} 