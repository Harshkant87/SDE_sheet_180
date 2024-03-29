// Given a string input of length n, find the length of the longest substring without repeating characters i.e return a substring that does not have any repeating characters.

// Substring is the continuous sub-part of the string formed by removing zero or more characters from both ends.

#include <bits/stdc++.h> 
int uniqueSubstrings(string str)
{
    //Write your code here
  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}