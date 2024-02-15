// Given that integers are read from a data stream. Your task is to find the median of the elements read so far.

// Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.

// For example :
// [2,3,4] - median is 3.
// [2,3] - median is floor((2+3)/2) = 2.

#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here
    priority_queue<int> pq1;  //max on top

    priority_queue<int,vector<int>,greater<int>> pq2; //min on top

    

    vector<int>ans;

 

    for(int i=0;i<n;i++){

        if(pq1.size()==0 || arr[i]< pq1.top())

            pq1.push(arr[i]);

        else pq2.push(arr[i]);

 

        if(pq1.size() > pq2.size()+1){

            pq2.push(pq1.top());

            pq1.pop();

        }

        if(pq2.size() > pq1.size()+1){

            pq1.push(pq2.top());

            pq2.pop();

        }

 

        if((i+1)%2==0){

            int median = (pq1.top()+pq2.top())/2;

            ans.push_back(median);

        }else{

            if(pq1.size() > pq2.size()) ans.push_back(pq1.top()); 

            else ans.push_back(pq2.top());

        }

        

    }

 

    return ans;
}
