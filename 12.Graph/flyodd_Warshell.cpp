int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
        // Write your code here.

    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 1e9));

    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        dis[u][v] = w;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
        }
    }

 
    for (int via = 1; via <= n; via++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][via] != 1e9 && dis[via][j] != 1e9) {
                    dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j] == 1e9){
                dis[i][j]=-1;
            } else {
                dis[i][j] = dis[i][j];
            }
        }
    }

     if (dis[src][dest] == -1) 
          return 1e9; // No path exists
     }
     if(dis[src][dest] > 1e8) return 1e9;

    return dis[src][dest];
}