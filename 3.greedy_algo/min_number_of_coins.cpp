vector<int> MinimumCoins(int n)
{
    // Write your code here
    int curr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int curr_n = 9;
    vector<int>coins;

    for(int i = curr_n - 1; i >=0 ; i--){
        while(n >= curr[i]){
            n = n - curr[i];
            coins.push_back(curr[i]);
        }
    }
    return coins;
}