#include <bits/stdc++.h> 

void insert(stack<int> &stack, int num){
	if(stack.size() == 0 || num >= stack.top()){
		stack.push(num);
		return;
	}
	int temp = stack.top();
	stack.pop();
	insert(stack, num);
	stack.push(temp);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.size() == 0 || stack.size() == 1){
		return;
	}
	int temp = stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack, temp);
}