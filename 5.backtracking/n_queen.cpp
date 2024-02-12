#include <bits/stdc++.h>

 bool issafe(int row, int col, int n, vector<vector<int>> &board){

    for(int j=col; j>=0; j--){

 

        if(board[row][j]==1) return false;

 

    }

    for(int i=row, j=col; i<n && j>=0; i++, j--){

 

        if(board[i][j]==1) return false;

 

    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {

 

        if (board[i][j] == 1)

          return false;

    }

    return true;

}

void solve(int col,int n,vector<vector<int>>&ans,vector<vector<int>>&board)

{

    if(col==n)

    {

        vector<int>temp;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++)

            {

                temp.push_back(board[i][j]);

            }

        }

        ans.push_back(temp);

        return;

    }

    for(int row=0;row<n;row++)

    {

        if(issafe(row,col,n,board))

        {

            board[row][col]=1;

            solve(col+1,n,ans,board);

            board[row][col]=0;

        }

    }

 

}

 

vector<vector<int>> solveNQueens(int n) {

    // Write your code here.

     vector<vector<int>> ans;

    vector<vector<int>> board(n, vector<int>(n,0));

    solve(0,n, ans, board);

    return ans;

}