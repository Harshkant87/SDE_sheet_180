#include<algorithm>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";

    sort(arr.begin(),arr.end());
    string start = arr[0];
    string end = arr[n-1];

    for(int i=0; i<start.length(); ++i)
    {
        if(start[i]!=end[i])
        {
            return ans;
        }
        else
        {
            ans+=start[i];
        }
    }
    return ans;
}
