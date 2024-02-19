// You are given two strings, ‘s’ of size ‘n’, which is the text string, and ‘pattern’ of size ‘m’, which is the pattern string.



// Your task is to return all the indices in sorted order (in 1-based indexing) of string ‘s’ such that starting from that index, the substring in ‘s’ of length ‘m’ is equal to ‘pattern’.


// Example:
// Input: ‘n’ = 8, ‘m’ = 3
// ‘s’ = “abdchabd”, ‘pattern’ = “abd”

// Output: 1 6
vector<int> search(string s, string pattern) {
    // Write Your Code Here
    int n = s.size();
    int m = pattern.size();

    vector<int> ans;
    string tot = pattern + '$' + s;
    int tot_size = tot.size();
    int i = 0, j = 1;

    while(j < tot_size){
        int cnt = 0;
        int k = j;

        while(k < tot_size){

            if(tot[i] == tot[k]){
                cnt++;
                i++;
                k++;
            }

            else break;

        }
        if(cnt == m) ans.push_back(j - m);
        i = 0;
        j++;

    }

    return ans;
}