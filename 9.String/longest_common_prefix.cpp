// You are given an array ‘arr’ of ‘n’ strings.



// Find the longest common prefix in all these strings.



// If there is no common prefix in all the strings return "-1".


// Example:
// Input: 'arr' = [“abcd”, “abc”, “abref”, “abcde”]

// Output: ab

#include<bits/stdc++.h>

int check(string a,string b, int n, int m){

    int cnt=0;
    if(n<m){
        return check(b,a,m,n);
    }

    for(int i=0;i<m;i++){
        if(a[i]==b[i]){
           cnt++;
        }
        else{
            break;
        }
    }
    return cnt;

}

 

string commonPrefix(vector<string> &arr, int n) {

    int mini=INT_MAX;
    for(int i=0;i<n-1;i++){
        int number=check(arr[i],arr[i+1],arr[i].size(),arr[i+1].size());
        mini=min(mini,number);
    }
    if(mini==0)return "-1";
    return arr[0].substr(0,mini);

}