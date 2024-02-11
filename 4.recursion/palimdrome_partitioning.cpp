// Given a string 's', partition s such that every partition string is a palindrome.



// Return all possible palindrome partitioning of s.



// Note:
// You don’t need to print anything. Just implement the given function.
// Example:
// Input: s = “aab”
// Output: [
//   ["a","a","b"]
//   ["aa","b"]
//  ]

// Explanation: There are two possible ways to partition the given string.
//  1st: aa|b
//  2nd: a|a|b

#include<bits/stdc++.h>

bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--])
        return false;
    }
    return true;
}

void partitionHelper(int index, string s, vector < string > & path,vector < vector < string > > & res){
    if (index == s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); ++i) {
        if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    // Write your code here.
      vector < vector < string > > res;
      vector < string > path;
      partitionHelper(0, s, path, res);
      return res;

}