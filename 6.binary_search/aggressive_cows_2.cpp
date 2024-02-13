// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



// You are also given an integer 'k' which denotes the number of aggressive cows.



// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



// Print the maximum possible minimum distance.



// Example:
// Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

// Output: 2

// Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.

#include<bits/stdc++.h>

bool canWePlace(vector<int> &stalls, int cows, int dist){
    int n = stalls.size();
    int cntCows = 1;
    int lastPlace = stalls[0];

    for(int i = 1; i < n; i++){
        if(stalls[i] - lastPlace >= dist){
            cntCows++;
            lastPlace = stalls[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int high = stalls[n - 1] - stalls[0];

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(canWePlace(stalls, k, mid)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}