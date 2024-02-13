int upperBound(vector<int> &arr, int x, int n){

    // Write your code here.

        int low=0;

    int high=n-1;

    int ans=0;

    while(low<=high){

      int mid=low+(high-low)/2;

      if(arr[mid]<=x){

          ans=mid+1;

          low=mid+1;

          } 

          else {

                  high = mid-1;

          }

        }

    return ans; 

}

 

int median(vector<vector<int>> &A, int m, int n) {

    int low = 1;

  int high = 1e9;

  //int n = A.size();

  //int m = A[0].size();

  while (low <= high)

  {

    int mid = (low + high) >> 1;

    int cnt = 0;

    for (int i = 0; i < m; i++)

    {

      cnt += upperBound(A[i], mid,n);

    }

    if (cnt <= (n * m) / 2)

      low = mid + 1;

    else

      high = mid - 1;

  }

  return low;

 

}