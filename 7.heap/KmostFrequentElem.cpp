// You are given an Integer array ‘ARR’ and an Integer ‘K’.



// Your task is to find the ‘K’ most frequent elements in ‘ARR’. Return the elements in any order.



// For Example:

// You are given ‘ARR’ = {1, 2, 2, 3, 3} and ‘K’ = 2. 

// The answer will {2, 3} as 2 and 3 are the elements occurring most times.

//method: 1

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> map;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> ans;

    for (int num : arr) map[num]++;
    for (auto& pair: map) {
        minHeap.push({pair.second, pair.first});
        if (minHeap.size() > k) minHeap.pop();
    }
    while (!minHeap.empty()) {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return ans;
}

//method: 2

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
 unordered_map<int, int> mp;

    // Build map where the key is element
    // and value is how often this element appears in 'ARR'.
    for (int ele : arr)
    {
        mp[ele]++;
    }

    vector<int> bucket[n + 1];

    for (auto x : mp)
    {
        int freq = x.second;

        // Add in correct bucket.
        bucket[freq].push_back(x.first);
    }

    vector<int> ans(k);
    int cur = 0;

    // Add 'K' elements to answer array starting from the rightmost bucket.
    for (int i = n; i > 0 && k > 0; i--)
    {
        if (bucket[i].size() == 0)
        {
            continue;
        }

        for (int num : bucket[i])
        {

            ans[cur++] = num;
            k--;
            if (k == 0)
            {
                break;
            }
        }
    }

    return ans;
}