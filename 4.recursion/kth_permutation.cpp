// You have been given two integers ‘N’ and ‘K’. Your task is to find the K-th permutation sequence of numbers from 1 to ‘N’. The K-th permutation is the K-th permutation in the set of all sorted permutations of string 1 to ‘N’.

// For example :
// If ‘N’ = 3 and ‘K’ = 4. Then all permutations for ‘N’ = 3 are “123”, “132”, “213”, “231”, “312”, “321”. So the 4-th permutation is “231”.

#include<bits/stdc++.h>

void Utils(int index, string s, vector<string>&res){
    if(index == s.size()){
        res.push_back(s);
        return;
    }

    for(int i = index; i < s.size(); i++){
        swap(s[i], s[index]);
        Utils(index + 1, s, res); //generate permutations of same length
        swap(s[i], s[index]);
    }
}

string kthPermutation(int n, int k) {
    // Write your code here.
    string s;
    vector<string>res;
    for(int i = 1; i <= n; i++)
        s.push_back(i + '0');
    
    Utils(0, s, res);
    sort(res.begin(), res.end());
    auto it = res.begin() + (k - 1);
    return *it;
}