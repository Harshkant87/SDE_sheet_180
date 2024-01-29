// For ‘N’ = 4, and 
// ‘Arr’ = {{1, 3}, {2, 4}, {3, 5}, {6, 7}}
// We can see that {1, 3} and {2, 4} overlap, so if we merge them, we get {1, 4}.
// Now ‘Arr’ becomes: {{1, 4}, {3, 5}, {6, 7}}
// Still, we observe that {1, 4} and {3, 5} overlap, hence we merge them into {1, 5}.
// Hence, ‘Arr’ becomes {{1, 5}, {6, 7}}.

#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
    vector<vector<int>> ans;

    int first = arr[0][0];

    int end = arr[0][1];

    for(int i = 1; i< arr.size(); i++){

        if(end >= arr[i][0]){

            end = max(end, arr[i][1]);

        }

        else{

            ans.push_back({first,end});

            first = arr[i][0];

            end = arr[i][1];

        }

    }

    ans.push_back({first,end});

    return ans;
	
}


