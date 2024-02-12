// You are given an input string 'S'. Your task is to find and return all possible permutations of the input string.

// Note:
// 1. The input string may contain the same characters, so there will also be the same permutations.

// 2. The order of permutation does not matter.

#include <bits/stdc++.h> 

void Utils(int index, string s, vector<string> &ans){
    if(index == s.size()){
        ans.push_back(s);
        return;
    }

    for(int i = index; i < s.size(); i++){
        swap(s[i], s[index]);
        Utils(index + 1, s, ans); //permutation snippets
        swap(s[i], s[index]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    Utils(0, s, ans);
    return ans;
}