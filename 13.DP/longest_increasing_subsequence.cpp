// method 1: 

int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>>& dp) {
    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
    
    int take = 0;
    
    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n) {
    // Create a 2D DP array initialized to -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    return getAns(arr, n, 0, -1, dp);
}


//method 2:

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int nums[], int n)
{
    // Write Your Code here
    int maxi = 1;
    vector<int> dp(n,1);

    for(int ind=0; ind<n; ind++){
        for(int prev=0; prev<ind; prev++){
            if (nums[ind] > nums[prev] && dp[prev] + 1 > dp[ind]) {
                dp[ind] = dp[prev] + 1;
            }
        }
        if(maxi < dp[ind]){
            maxi = dp[ind];
        }
    }

    return maxi;
}


// method: 3

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int nums[], int n)
{
    // Write Your Code here
   vector<int> temp;
   temp.push_back(nums[0]);
   for(int i=1; i<n; i++){
       if(nums[i] > temp.back()){
           temp.push_back(nums[i]);
       }else{
           int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin(); // inserting at right place
           temp[ind]=nums[i];
       }
   }
   return temp.size();
}