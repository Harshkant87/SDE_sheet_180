// You are given N activities with their start time Start[] and finish time Finish[]. You need to tell the maximum number of activities a single person can perform.

// Note:
// A person can only work on a single activity at a time. The start time of one activity can coincide with the end time of another.

#include<bits/stdc++.h>


int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();
    vector<pair<int,int>>meet;

    for(int i = 0; i < n; i++){
        meet.push_back({finish[i], start[i]});
    }

    sort(meet.begin(), meet.end());
    int jobs = 1;
    int limit = meet[0].first;

    for(int i = 1; i < n; i++){
        if(limit <= meet[i].second){
            limit = meet[i].first;
            jobs++;
        }
    }
    return jobs;
}