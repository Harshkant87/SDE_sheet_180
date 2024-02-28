#include <bits/stdc++.h>

int mcm(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
    if(i == j){
        return 0; //  base case
    }

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int minAns = INT_MAX;
    for(int k = i; k < j; k++){
        int ans = mcm(arr, i, k, dp) + mcm(arr, k + 1, j, dp) + arr[i - 1]*arr[j]*arr[k];
        minAns = min(minAns, ans);
    }
    return minAns;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(N, vector<int>(N, -1));
    int i = 1;
    int j = N - 1;
    return mcm(arr, i, j, dp);
}

// method: 2

int matrixMultiplication(vector<int> &arr, int N)
{    
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i=N-1; i>=1; i--) {
      for (int j = i + 1; j < N; j++) {
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; k++)
          dp[i][j] = min(dp[i][j], arr[i - 1] * arr[k] * arr[j] + dp[i][k] +
                                       dp[k + 1][j]);
      }
    }
    return dp[1][N - 1];
}