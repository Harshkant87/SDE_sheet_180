#include<bits/stdc++.h>
vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.
    vector<int>ans;
    if(root == NULL) return ans;
    map<int,int>mpp;
    queue<pair<TreeNode<int>*, int>>q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        TreeNode<int> *node = it.first;
        int line = it.second;

        q.pop();
        mpp[line] = node -> data; //update the line with latest

        if(node -> left){
            q.push({node -> left, line - 1});
        }

        if(node -> right){
            q.push({node -> right, line + 1});
        }

    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }

    return ans;
}