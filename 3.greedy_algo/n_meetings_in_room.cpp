// You are given the schedule of 'N' meetings with their start time 'Start[i]' and end time 'End[i]'.



// You have only 1 meeting room. So, you need to return the maximum number of meetings you can organize.



// Note:
// The start time of one chosen meeting can’t be equal to the end time of the other chosen meeting.

struct meeting{
    int start;
    int end;
    int pos;
};

bool comparator(meeting m1, meeting m2){
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n = start.size();
    vector<meeting> meetings(n);

    for(int i = 0; i < n; i++){
        meeting m;
        m.start = start[i];
        m.end = end[i];
        m.pos = i + 1;
        meetings[i] = m;
    }

    sort(meetings.begin(), meetings.end(), comparator);
    int ans = 1;
    int limit = meetings[0].end;

    for (int i = 1; i < n; i++) {
        if (meetings[i].start > limit) {
        limit = meetings[i].end;
        ans++;
        }
    }  
    return ans; 
}