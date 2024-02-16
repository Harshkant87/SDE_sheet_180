bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<int> st;
    for(char c: s){
            if(c == '(' || c == '{' || c == '[' ){
            st.push(c);
        } 
        else{
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((c == ')' and ch == '(') or  (c == ']' and ch == '[') or (c == '}' and ch == '{')) continue;
                else return false;
        }
    }
    return st.empty();

}