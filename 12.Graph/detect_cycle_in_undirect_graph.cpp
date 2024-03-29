#include<queue>

bool check(int start,int vis[],vector<int> adj[]){
    vis[start]=1;
    queue<pair<int,int>> q;
    q.push({start,-1});

    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto it:adj[node])
        {
            if(!vis[it]){

            vis[it]=1;
            q.push({it,node});

            }
            else if(parent!=it)
            return true;
        }

   } 

    return false;
}

 

string cycleDetection (vector<vector<int>>& edges, int n, int m){

    int vis[n+1]={0};
    vector<int> adj[n+1];
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
        if(check(i,vis,adj)==true)
        return "Yes";
        }
    }
    return "No";

}