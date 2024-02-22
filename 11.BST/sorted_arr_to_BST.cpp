TreeNode<int> * sortedArrToBSTUtil(vector<int> &arr, int low, int high){

    if(low > high) return NULL;

    int mid = low + (high - low) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    TreeNode<int> *rootLeft = sortedArrToBSTUtil(arr, low, mid - 1);
    TreeNode<int> *rootRight = sortedArrToBSTUtil(arr, mid + 1, high);

    root -> left = rootLeft;
    root -> right = rootRight;

    return root;

}


TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return sortedArrToBSTUtil(arr, 0, n - 1);
}