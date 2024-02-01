// You are given an array/list say ‘ARR’ of size ‘N’. We call pair (i, j) a Reverse Pair when i < j and 'ARR[i]' > 2 * 'ARR[j]'.

// Your task is to find the number of Reverse Pairs present in given 'ARR'.

// For example :

// For the array [50, 21, 9], if we follow 1-based indexing, the Reverse Pairs are (1, 2), (1, 3) and (2, 3). Thus, the total count i.e. the answer becomes 3.
// Note :

// A single index of the pair (i, j) can be used multiple times.


#include <bits/stdc++.h>

 

void merge(vector<int>& arr, int low, int mid, int high){

    vector<int> temp;

    int left = low;

    int right = mid+1;

 

    while(left <= mid && right <= high){

        if(arr[left] <= arr[right]){

            temp.push_back(arr[left]);

            left++;

        }

        else{

            temp.push_back(arr[right]);

            right++;

        }

    }

 

    while(left <=  mid){

        temp.push_back(arr[left]);

        left++;

    }

 

    while(right <=  high){

        temp.push_back(arr[right]);

        right++;

    }

 

    for(int i=low; i<=high; i++){

        arr[i] = temp[i-low];

    }

}

int countPairs(vector<int>& arr, int low, int mid, int high){

    int right = mid+1;

    int cnt = 0;

    for(int i=low; i<=mid; i++){

        while(right <= high && arr[i] > 2*static_cast<long long>(arr[right])) right++; //change in logic

        cnt += (right - (mid+1));

    }

    return cnt;

}

    int mergeSort(vector<int>& arr, int low, int high){

        int cnt = 0;

        if(low >= high) return cnt;

        int mid = (low + high)/2;

        cnt += mergeSort(arr, low, mid);

        cnt += mergeSort(arr, mid+1, high);

        cnt += countPairs(arr, low, mid, high);

        merge(arr, low, mid, high);

        return cnt;

    }

int reversePairs(vector<int> &arr, int n){

    return mergeSort(arr, 0, n-1);

}