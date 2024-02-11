long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    long long water = 0;
    long long prefix[n];
    long long suffix[n];
    prefix[0] = arr[0];
    suffix[n - 1] = arr[n - 1];

    for(int i = 1; i < n; i++)
        prefix[i] = max(prefix[i - 1], arr[i]);
    
    for(int i = n - 2; i >=0; i--)
        suffix[i] = max(suffix[i + 1], arr[i]);

    for(int i = 0; i < n; i++)
        water += min(prefix[i], suffix[i]) - arr[i];
    
    return water;

}