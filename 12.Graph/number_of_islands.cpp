#include<bits/stdc++.h>

void dfs(int **arr, vector<vector<bool>>&vis, int n, int m, int row, int col){
   vis[row][col] = true; // visited

   int dx[]={0,-1,-1,-1,0,1,1,1};
   int dy[]={-1,-1,0,1,1,1,0,-1};

   for(int k = 0; k < 8; k++){
      int newRow = row + dx[k];
      int newCol = col + dy[k];

      if(newRow >= 0 && newRow < n && newCol >=0 && newCol < m 
       && !vis[newRow][newCol] && arr[newRow][newCol] == 1){
         dfs(arr, vis, n, m, newRow, newCol);
      }
   }
}


int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<vector<bool>>vis(n, vector<bool>(m, false));
   int countOfIsland = 0;

   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(arr[i][j] == 1 && vis[i][j] == false){
            dfs(arr, vis, n, m, i, j);
            countOfIsland++;
         }
      }
   }

   return countOfIsland; 
}