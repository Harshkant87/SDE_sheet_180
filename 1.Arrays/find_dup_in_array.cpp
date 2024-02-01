// You are given an array of integers 'ARR' containing N elements. Each integer is in the range [1, N-1], with exactly one element repeated in the array.

// Your task is to find the duplicate element. The duplicate element may be repeated more than twice in the error, but there will be exactly one element that is repeated in the array.

// Note :

// All the integers in the array appear only once except for precisely one integer which appears two or more times.

// hint, hare tortoise method

#include <bits/stdc++.h>

int findDuplicate(vector<int> &nums, int n){
	// Write your code here.
	int slow = nums[0];
	int fast = nums[0];

	do{
		slow = nums[slow];
		fast = nums[nums[fast]];
	}while(slow != fast);

	slow = nums[0];
	while(slow != fast){
		slow = nums[slow];
		fast = nums[fast];
	}

	return slow;
}