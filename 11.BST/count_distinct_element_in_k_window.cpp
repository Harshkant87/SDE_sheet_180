#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    vector<int>ans;
    unordered_map<int, int>mpp;
    int n = arr.size();
    int start = 0;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;

        if(i - start + 1 == k){
            ans.push_back(mpp.size());
            mpp[arr[start]]--;

            if(mpp[arr[start]] == 0)
                mpp.erase(arr[start]);
            
            start++;
        }

    }
    return ans;
	
}