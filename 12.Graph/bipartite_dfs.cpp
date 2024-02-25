#include<bits/stdc++.h>

bool dfs(vector<vector<int>>&adj, vector<int>&color, int col, int node){
	color[node] = col;

	for(auto it: adj[node]){
		if(color[it] == -1){
			if(dfs(adj, color, !col, it) == false) return false; //important step
		}
		else if(color[it] == col){ //important step
			return false;
		}
	}
	return true;
}


bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n = edges.size();
	vector<vector<int>>adj(n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(edges[i][j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int>color(n, -1);
    int col = 0;
	for(int i = 0; i < n; i++){
		if(color[i] == -1){
			if(dfs(adj, color, col, i) == false){
				return false;
			}
		}
	}
	return true;
}