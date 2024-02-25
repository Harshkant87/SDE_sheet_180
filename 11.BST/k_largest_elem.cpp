#include <bits/stdc++.h>

int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int, vector<int>, greater<int>>pq; //min heap
	int n = arr.size();
	for(int i = 0; i < n; i++){
		pq.push(arr[i]);
		if(pq.size() > K){
			pq.pop();
		}
	}
	return pq.top();
}