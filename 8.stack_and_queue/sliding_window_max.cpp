// You are given an array 'ARR' of integers of length 'N' and a positive integer 'K'. You need to find the maximum elements for each and every contiguous subarray of size K of the array.

// For example
// 'ARR' =  [3, 4, -1, 1, 5] and 'K' = 3
// Output =  [4, 4, 5]

#include<deque>
vector<int> maxSlidingWindow(vector<int> &arr, int n, int k){
    // Write your code here.
    vector<int>ans;
    deque<int>dq;

    for(int i = 0; i < n; i++){
        
        if(!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while(!dq.empty() && arr[i] > arr[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
        if(i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;

}