#include<bits/stdc++.h>
int KthLargest(vector<int> &arr, int k){
	priority_queue<int> pq(arr.begin(), arr.end()); //maxheap
	int pop_time = k;
	while(pop_time != 1){
		pq.pop();
		pop_time--;
	}
	return pq.top();
}

int KthSmallest(vector<int> &arr, int k){
	priority_queue<int, vector<int>, greater<int>>pq(arr.begin(), arr.end()); // minheap
	int pop_time = k;
	while(pop_time != 1){
		pq.pop();
		pop_time--;
	}
	return pq.top();
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	int kth_small = KthSmallest(arr, k);
	int kth_largest = KthLargest(arr, k);
	return {kth_small,  kth_largest};
}