int maxPathSumUtils(BinaryTreeNode<int> *root, int &maxAns){
    if(!root)
        return 0;
    int leftMaxSum = max(0, maxPathSumUtils(root -> left, maxAns));
    int rightMaxSum = max(0, maxPathSumUtils(root -> right, maxAns));

    int val = root -> data;

    maxAns = max(maxAns, (leftMaxSum + rightMaxSum) + val);

    return val + max(leftMaxSum, rightMaxSum);
}

int maxPathSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    int maxAns = INT_MIN;
    maxPathSumUtils(root, maxAns);
    return maxAns;

}