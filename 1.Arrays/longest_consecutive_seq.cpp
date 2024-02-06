// You are given an unsorted array/list 'ARR' of 'N' integers. Your task is to return the length of the longest consecutive sequence.

// The consecutive sequence is in the form ['NUM', 'NUM' + 1, 'NUM' + 2, ..., 'NUM' + L] where 'NUM' is the starting integer of the sequence and 'L' + 1 is the length of the sequence.

// Note:

// If there are any duplicates in the given array we will count only one of them in the consecutive sequence.
// For example-
// For the given 'ARR' [9,5,4,9,10,10,6].

// Output = 3
// The longest consecutive sequence is [4,5,6].

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int>set_hash;
    int longest = INT_MIN;
    for(int num: arr){
        set_hash.insert(num);
    }

    for(auto it: set_hash){
        if(set_hash.find(it - 1) == set_hash.end()){
            int count = 0;
            int x = it;

            while(set_hash.find(x) != set_hash.end()){
                count++;
                x += 1;
            }

            longest = max(longest, count);
        }
    }
    return longest;
    
}