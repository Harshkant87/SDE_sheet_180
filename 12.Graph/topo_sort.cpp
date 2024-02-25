//Kahn's Algo

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>adj(v);
    for(auto i: edges){
        adj[i[0]].push_back(i[1]);
    }

    vector<int>topo;
    queue<int>q;
    vector<int>indegree(v, 0);

    for(int i = 0; i < v; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--; //KAHN'S ALGO
            if(indegree[it] == 0){
            q.push(it);
            }
        }
    }
    return topo;
}