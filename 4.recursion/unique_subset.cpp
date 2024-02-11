// Ninja is observing an array of ‘N’ numbers and wants to make as many unique subsets as possible. Can you help the Ninja to find all the unique subsets?

// Note: Two subsets are called same if they have same set of elements.For example {3,4,1} and {1,4,3} are not unique subsets.

// You are given an array ‘ARR’ having N elements. Your task is to print all unique subsets.

// For Example
// For the given if ARR = [1,1,3],the answer will be [ ],[1],[1,1],[1,3],[3],[1,1,3].

#include <bits/stdc++.h>
void uniqueSubsetsUtil(int index, int n,  vector<int> &arr, vector<int>&temp, vector<vector<int>>&ans){
    ans.push_back(temp);
    for(int i = index; i < n; i++){
        if(i != index && arr[i] == arr[i - 1])
        continue;
        temp.push_back(arr[i]);
        uniqueSubsetsUtil(i + 1, n, arr, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>temp;
    sort(arr.begin(), arr.end());
    uniqueSubsetsUtil(0, n, arr, temp, ans);
    return ans;

}