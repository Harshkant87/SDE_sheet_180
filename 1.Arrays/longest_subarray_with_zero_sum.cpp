// Ninja loves playing with numbers. So his friend gives him an array on his birthday. The array consists of positive and negative integers. Now Ninja is interested in finding the length of the longest subarray whose sum is zero.

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    unordered_map<int, int>hash_map;
    int sum = 0;
    int maxLength = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++){
      sum += arr[i];

      if(sum == 0){
        maxLength = i + 1;
      }
      else{
        if(hash_map.find(sum) != hash_map.end()){
          maxLength = max(maxLength, i - hash_map[sum]);
        }
        else{
          hash_map[sum] = i;
        }
      }
    }
    return maxLength;

}