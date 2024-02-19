// Given a string STR of length N. The task is to return the count of minimum characters to be added at front to make the string a palindrome.

// For example, for the given string “deed”, the string is already a palindrome, thus, minimum characters needed are 0.

// Similarly, for the given string “aabaaca”, the minimum characters needed are 2 i.e. ‘a’ and ‘c’ which makes the string “acaabaaca” palindrome.

int minCharsforPalindrome(string str) {
	// Write your code here.
	int i=0,j=str.length()-1;
    int count=0;
    int k=j;

    while(i<=j)
    {
        if(str[i]==str[j])
         {
             i++;
             j--;
         }
         else {
             i=0;
             k--;
             j=k;
             count++;
         }
    }

    return count;	
}