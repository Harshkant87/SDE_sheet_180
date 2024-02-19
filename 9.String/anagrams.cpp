// You have been given two strings 'STR1' and 'STR2'. You have to check whether the two strings are anagram to each other or not.

// Note:
// Two strings are said to be anagram if they contain the same characters, irrespective of the order of the characters.
// Example :
// If 'STR1' = “listen” and 'STR2' = “silent” then the output will be 1.

// Both the strings contain the same set of characters.

// method 1

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int n = str1.size();
    int m = str2.size();

    if(n != m) return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}

//method 2

#define NO_OF_CHARS 256

bool areAnagram(string &str1, string &str2){
    // Create a count array and initialize all values as 0.
    int hash[NO_OF_CHARS] = { 0 };
    int i;

    int n1 = str1.length();
    int n2 = str2.length();
    // If length of both strings is not same, then they cannot be anagram.
    if (n1 != n2){
       return false;
    }

    /*
       For each character in input strings, 
       increment count in the corresponding count array.
    */
    for (i = 0; i < n1; i++){
        hash[str1[i]]++;
        hash[str2[i]]--;
    }

    // Check if all values in hash array are 0.
    for (i = 0; i < NO_OF_CHARS; i++){
        if (hash[i]){
            return false;
        }
    }
    return true;
}