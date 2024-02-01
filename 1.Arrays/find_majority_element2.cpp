// Given an array ‘A’ of ‘N’ integers, find the majority elements of the array.

// A majority element in an array ‘A’ of size ‘N’ is an element that appears more than floor(N / 3) times.

// Note: The floor function returns the number rounded down to the nearest integer.

// Note: Return the array of majority elements in sorted order.

// Example:
// Input: ‘N’ = 9 ‘A’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]

// Output: 1

// Explanation: The frequency of ‘1’ is 5, which is greater than floor(N / 3), hence ‘1’ is the majority element.

vector<int> majorityElement(vector<int> v) {
	// Write your code here
	int count1 = 0;
	int count2 = 0;
	int element1 = INT_MIN;
	int element2  = INT_MIN;

	for(int num: v){
		if(count1 == 0 && num != element2){
			count1++;
			element1 = num;
		}
		else if(count2 == 0 && num != element1){
			count2++;
			element2 = num;
		}
		else if(num == element1){
			count1++;
		}
		else if(num == element2){
			count2++;
		}
		else{
			count1--;
			count2--;
		}
	}

	count1 = 0;
	count2 = 0;

	for(int num: v){
		if(num == element1)
			count1++;
		if(num == element2)
			count2++;
	}
    
	int n = v.size();
	vector<int>ans;
	if(count1 > floor(n/3)) ans.push_back(element1);
	if(count2 > floor(n/3)) ans.push_back(element2);

	sort(ans.begin(), ans.end());
	return ans;

}