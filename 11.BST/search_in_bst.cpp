//method 1: recursive

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root == NULL) return false;

    if(root -> data == x){
        return true;
    } 
    else if(root -> data > x){
        return searchInBST(root -> left, x);
    }
    else{
        return searchInBST(root -> right, x);
    }
}

//method 2: iterative, constant space

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *ptr = root;
    
    while(ptr != NULL) {
        if(ptr->data == x) {
            return true;
        } else if(ptr->data > x) {
            // Move 'ptr' to left child. 
            ptr = ptr->left;
        } else {
            // Move 'ptr' to left child. 
            ptr = ptr->right;   
        }
    }

    return false;
}