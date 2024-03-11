// method: 1

long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    // Base case: if we're at the first element
    if (ind == 0) {
        // Check if the target sum is divisible by the first element
        return (T % arr[0] == 0);
    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the number of ways without taking the current element
    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);
    
    // Calculate the number of ways by taking the current element
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);
        
    // Store the sum of ways in the DP table and return it
    return dp[ind][T] = notTaken + taken;
}


// method: 2 

long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, 0)); // Create a DP table

    // Initializing base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = 1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            long notTaken = dp[ind - 1][target];

            long taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind][target - arr[ind]];

            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][T];
}

