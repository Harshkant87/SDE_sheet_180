#include <bits/stdc++.h>

using namespace std;

void dfs(int start, vector<int> adj[], vector<int> &innerAns, int vis[]) {
  vis[start] = 1;
  innerAns.push_back(start);
  for (auto it : adj[start]) {
    if (!vis[it]) {
      dfs(it, adj, innerAns, vis);
    }
  }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
     // Creating adjacency list

  vector<int> adj[V];
  for (int it = 0; it < edges.size(); it++) {
    int u = edges[it][0];
    int v = edges[it][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Array for visited mark initially all are 0
  int vis[V] = {0};
  // Answer vetor to store the final ans
  vector<vector<int>> ans;

  // loop through out the vertices and look for unvisited one and then go dipper

  // and push ans for that
  for (int it = 0; it < V; it++) {
    if (!vis[it]) {
      vector<int> innerAns;
      // deeply visit the adjacency one by DFS
      dfs(it, adj, innerAns, vis);
      ans.push_back(innerAns);
    }
  }
  return ans;
}