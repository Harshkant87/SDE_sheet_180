// You are given an integer array 'a' of size 'n'.



// For each element in the array, check whether the immediate right element of the array is smaller or not.



// If the next element is smaller, update the current index to that element. If not, then -1. The last element does not have any elements on its right.



// Example :
// Input: 'a' = [4, 7, 8, 2, 3, 1]

// Output: Modified array 'a' = [-1, -1, 2, -1, 1, -1]


void immediateSmaller(vector<int>& a)
{
	// Write your code here.
    int n = a.size();
    for(int i = 0; i < n; i++){
        if(i + 1 == n)
            a[i] = -1;
    
        if(a[i] > a[i + 1])
            a[i] = a[i + 1];
        else
            a[i] = -1;
    }
    return;
}