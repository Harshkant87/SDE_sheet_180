//method 1: recursion

void flattenBinaryTreeUtil(TreeNode<int>* root, TreeNode<int> **prev)
{
    // Write your code here.
    if(root == NULL) return ;

    flattenBinaryTreeUtil(root -> right, prev);
    flattenBinaryTreeUtil(root -> left, prev);

    root -> left = NULL;
    root -> right = *prev;
    *prev = root;
}

void flattenBinaryTree(TreeNode<int>* root)
{
    // Write your code here.
    TreeNode<int> *prev = NULL;
    flattenBinaryTreeUtil(root, &prev);

}

// method 2: iterative with stack

class Solution {
  node * prev = NULL;
  public:

  void flatten(node * root) {
  if (root == NULL) return;
  stack < node * > st;
  st.push(root);
  while (!st.empty()) {
    node * cur = st.top();
    st.pop();

    if (cur -> right != NULL) {
      st.push(cur -> right);
    }
    if (cur -> left != NULL) {
      st.push(cur -> left);
    }
    if (!st.empty()) {
      cur -> right = st.top();
    }
    cur -> left = NULL;
  }

}

//method 3: morris traversal

class Solution {
  node * prev = NULL;
  public:
   void flatten(node* root) {
        node* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				node* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }

};

};