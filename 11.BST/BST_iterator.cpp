class BSTiterator
{   

public:
    queue<int>q;
    
    void inOrder(TreeNode<int> *root){
        if(!root) return;
        
        inOrder(root->left);
        q.push(root->data);
        inOrder(root->right);
        
    }
    BSTiterator(TreeNode<int> *root)
    {
        inOrder(root);
    }

    int next()
    {
        if(q.empty()) return -1;
        int top= q.front();
        q.pop();
        return top;
    }

    bool hasNext()
    {
        return !q.empty();
    }
};