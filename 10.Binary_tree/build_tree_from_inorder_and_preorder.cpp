#include<bits/stdc++.h>

TreeNode<int> *buildBinaryTreeUtils(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int>&mpp){
    if(preStart > preEnd || inStart > inEnd) return NULL;

    int element = preorder[preStart];
    int inIndex = mpp[element];
    TreeNode<int> *root = new TreeNode<int>(element);
    int nElem = inIndex - inStart; //main catch

    root -> left = buildBinaryTreeUtils(preorder, preStart + 1, preStart + nElem, inorder, inStart, inIndex - 1,mpp);
    root -> right = buildBinaryTreeUtils(preorder, preStart+ nElem + 1, preEnd, inorder, inIndex + 1 , inEnd ,mpp);

    return root; 
}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int preStart = 0;
    int preEnd = preorder.size() - 1;
    int inStart = 0;
    int inEnd = inorder.size() - 1;

    map<int, int>mpp;
    for(int i = 0; i < inorder.size(); i++){
        mpp[inorder[i]] = i;
    }

    TreeNode<int> *root = buildBinaryTreeUtils(preorder, preStart, preEnd, inorder, inStart, inEnd, mpp);
    return root;
}