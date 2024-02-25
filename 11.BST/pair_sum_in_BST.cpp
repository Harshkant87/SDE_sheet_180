// method: 1

void ino(BinaryTreeNode *root,vector<int>&ans)
{
  if(!root)return;
  ino(root->left,ans);
  ans.push_back(root->data);
  ino(root->right,ans);
}

bool pairSumBst(BinaryTreeNode *root, int k)
{
    vector<int>ans;
    ino(root,ans);
    int i=0,j=ans.size()-1;
    while(i<j){
        if(ans[i]+ans[j]==k)return true;
        else if(ans[i]+ans[j]>k)j--;
        else i++;
    }
    return false;
}


// method: 2

#include <unordered_set>

bool helper(BinaryTreeNode *root, int k, unordered_set<int> &hashSet)
{
    if (root == NULL)
    {
        return false;
    }

    // If the pair is found then return "true".
    if (hashSet.count(k - root->data))
    {
        return true;
    }

    // If the pair is not found then simply insert the root's data into the 'hashSet'.
    hashSet.insert(root->data);

    // Recursively check for both left and right subtrees.
    return (helper(root->left, k, hashSet) || helper(root->right, k, hashSet));
}

bool pairSumBst(BinaryTreeNode *root, int k)
{

    // Set to store the nodes.
    unordered_set<int> hashSet;

    return helper(root, k, hashSet);
}