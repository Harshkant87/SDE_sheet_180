#include <algorithm>

class Kthlargest {
public:
    
    priority_queue<int,vector<int>,greater<int>>pq;
    int kval;

    Kthlargest(int k, vector<int> &arr) {
        for(int i=0;i<arr.size();i++){
        if(pq.size()>k){
            pq.pop();
        }
        pq.push(arr[i]);
    }
    kval=k;
    }

    int add(int num) {
       pq.push(num);
       if(pq.size()>kval){
           pq.pop();
       }
     return pq.top();
    }

};