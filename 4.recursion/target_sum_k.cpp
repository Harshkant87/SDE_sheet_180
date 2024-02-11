// Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.

// Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.

// Note :
// The order of subsets is not important. 

// The order of elements in a particular subset should be in increasing order of the index.

void sumUtil(int index, int n, int target, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
    if(index == n){
        if(target == 0){
            ans.push_back(temp);
        }
        return;
    }

    temp.push_back(arr[index]);
    sumUtil(index + 1, n, target - arr[index], arr, temp, ans);
    temp.pop_back();
    sumUtil(index + 1, n, target, arr, temp, ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>temp;
    sumUtil(0, n, k, arr, temp, ans);
    return ans;
}