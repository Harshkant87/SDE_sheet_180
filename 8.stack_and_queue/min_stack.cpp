#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		stack<pair<int, int>>st;
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(st.empty()){
				st.push({num, num});
			}
			else{
				auto temp = st.top();
				int min_num = min(num, temp.second);
				st.push({num, min_num});
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty())
				return -1;
			else{
				auto temp = st.top();
				int top_num = temp.first;
				st.pop();
				return top_num;
			}
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st.empty())
				return -1;
			else{
				auto temp = st.top();
				int top_num = temp.first;
				return top_num;
			}
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty())
				return -1;
			else{
				auto temp = st.top();
				int min_num = temp.second;
				return min_num;
			}
		}
};