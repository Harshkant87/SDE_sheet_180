#include<bits/stdc++.h>

bool isCyclic(int V, vector<vector<int>>&adj) {
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		int cnt = 0;
		// o(v + e)
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cnt++;
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (cnt == V) return false; //topo sort logic kahn's algo
		return true;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<vector<int>>adj(n + 1);
    for(auto i: edges){
      adj[i.first].push_back(i.second);
    }

    return isCyclic(n + 1, adj);

}