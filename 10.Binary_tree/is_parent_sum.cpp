bool isParentSum(Node *root){
    // Write your code here.
    if(root == NULL || (root -> left == NULL && root -> right == NULL)) return true;

    int sumOfChild = 0;
    if(root -> left)
        sumOfChild += root -> left -> data;
    if(root -> right)
        sumOfChild += root -> right -> data;
    
    if(root -> data != sumOfChild)
        return false;
    
    return isParentSum(root -> left) && isParentSum(root -> right);
}