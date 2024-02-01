You are given an array of size ‘N’. The elements of the array are in the range from 1 to ‘N’.

// Ideally, the array should contain elements from 1 to ‘N’. But due to some miscalculations, there is a number R in the range [1, N] which appears in the array twice and another number M in the range [1, N] which is missing from the array.

// Your task is to find the missing number (M) and the repeating number (R).

// For example:
// Consider an array of size six. The elements of the array are { 6, 4, 3, 5, 5, 1 }. 
// The array should contain elements from one to six. Here, 2 is not present and 5 is occurring twice. Thus, 2 is the missing number (M) and 5 is the repeating number (R). 
// Follow Up
// Can you do this in linear time and constant additional space? 

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int m, r;
	
	// traversing the array 
	for(int i = 0; i < n; i += 1)
	{
		if( arr[abs(arr[i]) - 1] > 0 )
		{
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
		}
		// if arr[i] is already negative, it is the repeating number
		else  		
		{
			r = abs(arr[i]);
		}
	}
	
	
	for(int i = 0; i < n; i += 1)
	{
		// the index at which the element is positive is the missing number 
		if( arr[i] > 0 )
		{
			m = i + 1;
			break;
		}
	}
	
	pair<int, int>ans;
	
	ans.first = m;
	ans.second = r;
	
	return ans;
	 
	
}