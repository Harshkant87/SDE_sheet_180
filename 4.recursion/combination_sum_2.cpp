// You are given an array ‘arr’ of ‘n’ positive integers.



// You are also given a positive integer ‘target’.



// Your task is to find all unique combinations of elements of array ‘arr’ whose sum is equal to ‘target’. Each number in ‘arr’ may only be used once in the combination.



// Elements in each combination must be in non-decreasing order and you need to print all unique combinations in lexicographical order.



// Note:
// In lexicographical order, combination/array  ‘a’  comes before array ‘b’ if at the first index 'i' where 'a[i]' differs from 'b[i]', 'a[i]' < 'b[i]  or length of 'a' is less than 'b'.

#include<bits/stdc++.h>

void Utils(int index, int n, int target, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans){
	if(target == 0){
		ans.push_back(temp);
		return;
	}
	for(int i = index; i < n; i++){
		if(i != index && arr[i] == arr[i - 1]) continue;
		if(arr[i] > target) break;
		temp.push_back(arr[i]);
		Utils(i + 1, n, target - arr[i], arr, temp, ans);
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<int> temp;
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	Utils(0, n, target, arr, temp, ans);
	return ans;

}