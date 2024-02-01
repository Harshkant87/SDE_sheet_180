// You are given an array 'a' of 'n' integers.



// A majority element in the array ‘a’ is an element that appears more than 'n' / 2 times.



// Find the majority element of the array.



// It is guaranteed that the array 'a' always has a majority element.

int majorityElement(vector<int> v) {
	// Write your code here
	int count = 0;
	int maj_elememnt = 0;

	for(int num: v){
		if(count == 0){
			count++;
			maj_elememnt = num;
		}
		else if(num == maj_elememnt){
			count++;
		}
		else{
			count--;
		}
	}
	return maj_elememnt;
}