#include <bits/stdc++.h>

void pwsetUtils(int index, vector<int>&v, vector<int>& permutation, vector<vector<int>> &ans){
    if(index == v.size()){
        ans.push_back(permutation);
        return;
    }
    permutation.push_back(v[index]);
    pwsetUtils(index + 1, v, permutation, ans); //take
    permutation.pop_back();
    pwsetUtils(index + 1, v, permutation, ans); // do not take
}


vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>>ans;
    vector<int>permutation;
    pwsetUtils(0, v, permutation, ans);
    return ans;
}