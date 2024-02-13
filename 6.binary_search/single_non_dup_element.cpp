// You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, which appears only once.



// Return the number that appears once.



// Example:
// Input: 'arr' = [1,1,2,2,4,5,5]

// Output: 4 

// Explanation: 
// Number 4 only appears once the array.


// Note :
// Exactly one number in the array 'arr' appears once.

int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
    int n = arr.size();
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1;
    int high = n - 2;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]){
            return arr[mid];
        }
        else if(mid % 2 == 1 && arr[mid] == arr[mid - 1] || mid % 2 == 0 && arr[mid] == arr[mid + 1]){ //even odd index concept
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;

}