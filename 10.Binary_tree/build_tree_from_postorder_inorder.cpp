#include<bits/stdc++.h>
TreeNode<int> *buildTree(vector<int>& postOrder, int poStart, int poEnd, vector<int>& inOrder, int inStart, int inEnd, map<int, int> &mpp){

     if(poStart > poEnd || inStart > inEnd) return NULL;

     int element = postOrder[poEnd];
     int inRoot = mpp[element];
     int numsLeft = inRoot - inStart;

     TreeNode<int> *root = new TreeNode<int>(element);
     root -> left = buildTree(postOrder, poStart,  poStart + numsLeft - 1, inOrder, inStart, inRoot - 1, mpp);
     root -> right = buildTree(postOrder, poStart + numsLeft, poEnd - 1, inOrder, inRoot + 1, inEnd, mpp);

     return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	// Write your code here.
     int poStart = 0;
     int poEnd = postOrder.size() - 1;
     int inStart = 0;
     int inEnd = inOrder.size() - 1;

     map<int,int>mpp;
     for(int i = 0; i < inOrder.size(); i++){
          mpp[inOrder[i]] = i;
     }

     TreeNode<int> *root = buildTree(postOrder, poStart, poEnd, inOrder, inStart, inEnd, mpp);
     return root;
}
