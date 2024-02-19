// Problem statement
// You are given a string 'str' of length 'N'.



// Your task is to return the longest palindromic substring. If there are multiple strings, return any.



// A substring is a contiguous segment of a string.



// For example :
// str = "ababc"

// The longest palindromic substring of "ababc" is "aba", since "aba" is a palindrome and it is the longest substring of length 3 which is a palindrome. 

// There is another palindromic substring of length 3 is "bab". Since starting index of "aba" is less than "bab", so "aba" is the answer.

#include<bits/stdc++.h>
//expand around the centre

string fun(int l,int r,string s){
    int n = s.length();

    while(l>=0 && r<n && s[l]==s[r]){
        l--;
        r++;
    }
    return s.substr(l+1,r-l-1);
}



string longestPalinSubstring(string str) {
    // Write your code here.
    int n = str.length();
    string longest="";

    for(int i=0;i<n;i++){
        string ps1= fun(i,i,str); //odd length
        string ps2 = fun(i,i+1,str); //even length

        if(ps1.length() > longest.length()) longest = ps1;
        if(ps2.length()> longest.length()) longest = ps2;

    }

    return longest;
}