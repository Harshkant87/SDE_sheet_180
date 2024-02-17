// You have been given a grid containing some oranges. Each cell of this grid has one of the three integers values:

// Value 0 - representing an empty cell.
// Value 1 - representing a fresh orange.
// Value 2 - representing a rotten orange.
// Every second, any fresh orange that is adjacent(4-directionally) to a rotten orange becomes rotten.

// Your task is to find out the minimum time after which no cell has a fresh orange. If it's impossible to rot all the fresh oranges then print -1.

// Note:
// 1. The grid has 0-based indexing.
// 2. A rotten orange can affect the adjacent oranges 4 directionally i.e. Up, Down, Left, Right.

#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int N, int M)
{
    // Write your code here.
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        } 
        return tot == cnt ? days : -1;
}