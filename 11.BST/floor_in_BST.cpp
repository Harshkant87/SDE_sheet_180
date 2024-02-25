void floorBSTUtils(TreeNode<int> * root, int X, int &floor){
    if(!root)
        return ;
    if(root -> val == X){
        floor = root -> val;
        return;
    }
    else if(root -> val < X){
        floor = root -> val;
        floorBSTUtils(root -> right, X, floor);
    }
    else{
        floorBSTUtils(root -> left, X, floor);
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int floor = -1;
    floorBSTUtils(root, X, floor);
    return floor;
}