#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int>ans;
    if(root == NULL) return ans;
    map<int, vector<int>> mpp;
    queue<pair<TreeNode<int>*, int>>q;
    TreeNode<int>* curr = root;
    q.push({curr, 0});

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        auto node = front.first;
        int level = front.second;

        mpp[level].push_back(node -> data);
        if(node -> left) q.push({node -> left, level - 1});
        if(node -> right) q.push({node -> right, level + 1});
    }

    for(auto it: mpp){
        for(int i: it.second){
            ans.push_back(i);
        }
    }
    return ans;
}