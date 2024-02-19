// You are given a string 'str' of length 'N'.



// Your task is to reverse the original string word by word.



// There can be multiple spaces between two words and there can be leading or trailing spaces but in the output reversed string you need to put a single space between two words, and your reversed string should not contain leading or trailing spaces.



// Example :
// If the given input string is "Welcome to Coding Ninjas", then you should return "Ninjas Coding to Welcome" as the reversed string has only a single space between two words and there is no leading or trailing space.

string reverseString(string &s){
	// Write your code here.
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    
    //Iterate the string and keep on adding to form a word
    //If empty space is encountered then add the current word to the result
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }
    
    //If not empty string then add to the result(Last word is added)
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans; 
}