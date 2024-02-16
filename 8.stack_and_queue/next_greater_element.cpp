// You are given an array 'a' of size 'n'.



// Print the Next Greater Element(NGE) for every element.



// The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, which is greater than 'x'.



// If no greater elements exist to the right of 'x', consider the next greater element as -1.



// For example:
// Input: 'a' = [7, 12, 1, 20]

// Output: NGE = [12, 20, 20, -1]

// Explanation: For the given array,

// - The next greater element for 7 is 12.

// - The next greater element for 12 is 20. 

// - The next greater element for 1 is 20. 

// - There is no greater element for 20 on the right side. So we consider NGE as -1

#include<stack>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	// Write your code here
	stack<int>st;
	vector<int>nge(n , -1);

	for(int i = n - 1; i >= 0; i--){ // start from back
		while(!st.empty() && st.top() <= arr[i]){ // pop elem till you get next greater element
			st.pop();
		}
		if(!st.empty() && st.top() > arr[i]){ // once you found nge, mark it.
			nge[i] = st.top();
		}
		st.push(arr[i]); // push every element to the stack
	}
	return nge;
}