// You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.

// An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>>ans;
	sort(arr.begin(), arr.end());

	for(int i = 0; i < n; i++){

		if( i != 0 && arr[i] == arr[i - 1])
			continue;

		int j = i + 1;
		int k = n - 1;

		while(j < k){
			int sum = arr[i] + arr[j] + arr[k];
			if(sum > K){
				k--;
			}
			else if(sum < K){
				j++;
			}
			else{
				vector<int>temp = {arr[i], arr[j], arr[k]};
				ans.push_back(temp);
				j++;
				k--;

				//skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--; 
			}
		}
	}
	return ans;
}