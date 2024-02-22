
bool check(BinaryTreeNode<int> *root,int max,int min) {

    if(root == NULL) {
        return true;
    }

    if(root->data >= min && root->data <= max) {
        bool left = check(root->left,root->data,min);
        bool right = check(root->right,max,root->data);
        return (left && right);
    }
    else {
        return false;
    }

}

bool validateBST(BinaryTreeNode<int> *root) {

    // Write your code here

    return check(root,INT_MAX,INT_MIN);

}