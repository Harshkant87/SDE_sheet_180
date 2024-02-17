// There are ‘N’ people at a party. Each person has been assigned a unique id between 0 to 'N' - 1(both inclusive). A celebrity is a person who is known to everyone but does not know anyone at the party.

// Given a helper function ‘knows(A, B)’, It will returns "true" if the person having id ‘A’ know the person having id ‘B’ in the party, "false" otherwise. Your task is to find out the celebrity at the party. Print the id of the celebrity, if there is no celebrity at the party then print -1.

// Note:
// 1. The helper function ‘knows’ is already implemented for you.
// 2. ‘knows(A, B)’ returns "false", if A doesn't know B.
// 3. You should not implement helper function ‘knows’, or speculate about its implementation.
// 4. You should minimize the number of calls to function ‘knows(A, B)’.
// 5. There are at least 2 people at the party.
// 6. At most one celebrity will exist.

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	stack<int> s;
    for(int i = 0; i < n; i++){
        s.push(i);
    }
    //take out 2 person and compare them
    while(s.size() != 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(a,b)){
           s.push(b);
        }else{
            s.push(a);
        }
    }
    int person = s.top();
    //verify if person is celebrity or not
    //checking rows if all row are zero;
    int zeroCount = 0;

    for(int i = 0; i < n; i++){
        if(M[person][i] == 0){
            zeroCount++;
        }
    }

    if(zeroCount != n) return -1;
    //check column
    int oneCount = 0;

    for(int i = 0; i < n; i++){
        if(M[i][person] == 1){
          oneCount++;
        }
    }

    if(oneCount != n-1) return -1;  

    return person;
}