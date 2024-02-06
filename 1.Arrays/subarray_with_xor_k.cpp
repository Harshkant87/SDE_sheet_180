// Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’ whose bitwise XOR( ⊕ ) of all elements is equal to ‘B’.



// A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.



// Example:
// Input: ‘N’ = 4 ‘B’ = 2
// ‘A’ = [1, 2, 3, 2]

// Output: 3

// Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].

#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    unordered_map<int, int>map_hash;
    int count = 0;
    int n = a.size();
    int xr = 0;
    map_hash[xr]++;

    for(int i = 0; i < n; i++){
        xr ^= a[i];
        int x = xr ^ b;
        count += map_hash[x];
        map_hash[xr]++;
    }
    return count;

}