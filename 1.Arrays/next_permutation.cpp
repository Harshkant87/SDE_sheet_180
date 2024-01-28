// You are given an array ‘a’ of ‘n’ integers.



// You have to return the lexicographically next to greater permutation.



// Note:

// If such a sequence is impossible, it must be rearranged in the lowest possible order.


// Example:

// Input: 'a' = [1, 3, 2]

// Output: 2 1 3


vector<int> nextGreaterPermutation(vector<int> &v) {
    // Write your code here.
        int ind=-1;

    int n=v.size()-1;

    for(int i=n-1;i>=0;i--){

        if(v[i]<v[i+1]){

            ind=i;

            break;

        }

    }

    if(ind==-1){

        reverse(v.begin(),v.end());

         return v;       

 

    }

    for(int i=n;i>=ind;i--){

        if(v[i]>v[ind]){

            swap(v[i],v[ind]);

            break;

        }

    }

    reverse(v.begin()+ind+1,v.end());

    return v;
}