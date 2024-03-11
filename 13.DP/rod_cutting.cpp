int memoHelper(int ind,int N,vector<int>&price,vector<vector<int>>&dp){

    if(ind==0){

        return N*price[0];

    }

    if(dp[ind][N]!=-1) return dp[ind][N];

    int notTake=memoHelper(ind-1,N,price,dp);

    int take=INT_MIN;

    int rodLength=ind+1;

    if(rodLength<=N)

        take=price[ind]+memoHelper(ind,N-rodLength,price,dp);

    return dp[ind][N]=max(take,notTake);        

}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    return memoHelper(n-1,n,price,dp);
}