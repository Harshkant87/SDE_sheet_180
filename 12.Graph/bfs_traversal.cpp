#include<bits/stdc++.h>
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int>vis(n, 0);
    vector<int>ans;
    queue<int>q;
    q.push(0);
    vis[0] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;

}