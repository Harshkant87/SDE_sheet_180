// You are given a 'Nx3' 2-D array 'Jobs' describing 'N' jobs where 'Jobs[i][0]' denotes the id of 'i-th' job, 'Jobs[i][1]' denotes the deadline of 'i-th' job, and 'Jobs[i][2]' denotes the profit associated with 'i-th job'.



// You will make a particular profit if you complete the job within the deadline associated with it. Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.



// Return the number of jobs to be done to get maximum profit.



// Note :
// If a particular job has a deadline 'x', it means that it needs to be completed at any time before 'x'.

// Assume that the start time is 0.

#include<bits/stdc++.h>
bool static comp(vector<int>&j1, vector<int>&j2){
    return (j1[2] > j2[2]);
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), comp);
    int n = jobs.size();
    int maxi = jobs[0][1];

    for (int i = 1; i < n; i++) {
        maxi = max(maxi, jobs[i][1]);
    }

    int slot[maxi + 1];

    for (int i = 0; i <= maxi; i++)
        slot[i] = -1;

    int countJobs = 0, jobProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i][1]; j > 0; j--) {
        if (slot[j] == -1) {
            slot[j] = i;
            countJobs++;
            jobProfit += jobs[i][2];
            break;
        }
        }
    }

    return {countJobs, jobProfit};
}