#include<queue>

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode<int> *>q;
    q.push(root);

    while(!q.empty()){
        int levelSize = q.size();
        BinaryTreeNode<int> *prev = NULL;

        while(levelSize--){
            BinaryTreeNode<int> *curr = q.front();
            q.pop();

            if(prev){
                prev -> next = curr;
            }
            prev = curr;
            
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
        }
    }
    return;

}