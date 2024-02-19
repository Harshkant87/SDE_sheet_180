// You are given a string 's' that represents a Roman number. Convert the Roman number to an integer and return it.



// Roman numerals are represented by seven different symbols: I, V, X, L, C, D, and M.



// Table of values:
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000






int val(char ch){

    if(ch=='I'){
        return 1;
    }else if(ch=='V'){
        return 5;
    }else if(ch=='X'){
        return 10;
    }else if(ch=='L'){
        return 50;
    }else if(ch=='C'){
        return 100;
    }else if(ch=='D'){
        return 500;
    }else if(ch=='M'){
        return 1000;
    }   

}

int romanToInt(string s) {
    // Write your code here
    int count = 0;
    int prev = 0;
    int cur=0;

    for(int i = 1 ; i<s.length();i++){
        prev = val(s[i-1]);
        cur = val(s[i]);

        if(prev<cur){
            count-=prev; // handling cases like IX, XL etc
        }else{
            count+=prev;
        }

    }
    count+=val(s[s.length()-1]);

    return count;
}