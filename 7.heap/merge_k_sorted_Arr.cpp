// You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> >pq;
    for(int i = 0; i < k; i++){
      pq.push(make_tuple(kArrays[i][0], i, 0)); //push all first elem to min heap
    }

    vector<int>  ans;
    while(pq.size() != 0){
        tuple<int, int, int> tup = pq.top();
        ans.push_back(get<0>(tup));
        int kthArr = get<1>(tup);
        int index = get<2>(tup);
        pq.pop();
        if(index + 1 < kArrays[kthArr].size())
          pq.push(make_tuple(kArrays[kthArr][index + 1], kthArr, index + 1));
    }
    return ans;
}