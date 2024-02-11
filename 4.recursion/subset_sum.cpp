// You are given an array 'nums' of ‘n’ integers.



// Return all subset sums of 'nums' in a non-decreasing order.

void subsetSumUtil(int index, vector<int> &num, int sum, vector<int>&sumVector, int n){
	if(index == n){
		sumVector.push_back(sum);
		return;
	}
	subsetSumUtil(index + 1, num, sum + num[index], sumVector, n);
	subsetSumUtil(index + 1, num, sum, sumVector, n);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int>sumVector;
	int n = num.size();
	subsetSumUtil(0, num, 0, sumVector, n);
	sort(sumVector.begin(), sumVector.end());
	return sumVector;
}