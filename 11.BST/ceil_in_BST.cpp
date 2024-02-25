void ceilBSTUtils(BinaryTreeNode<int> * root, int x, int &ceil){
    if(!root)
        return ;
    if(root -> data == x){
        ceil = root -> data;
        return;
    }
    else if(root -> data < x){
        ceilBSTUtils(root -> right, x, ceil);
    }
    else{
        ceil = root -> data;
        ceilBSTUtils(root -> left, x, ceil);
    }
}


int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil = -1;
    ceilBSTUtils(node, x, ceil);
    return ceil;
}