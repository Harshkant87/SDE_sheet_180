void BTtoDLLUtils(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &prev1, BinaryTreeNode<int>* &head){
    if(!root) return;
    BTtoDLLUtils(root -> left, prev1, head);

    if(!prev1){
        head = root;
    }
    else{
        prev1 -> right = root;
        root -> left = prev1;
    }
    prev1 = root;

    BTtoDLLUtils(root -> right, prev1, head);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* head = NULL;
    BinaryTreeNode<int>* prev1 = NULL;
    BTtoDLLUtils(root, prev1, head);
    return head;
}