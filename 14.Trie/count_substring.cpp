class TrieNode{
public:
    TrieNode *child[26];
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int n = s.size();
    int count = 1; // counting empty substring
    TrieNode *root = new TrieNode();

    for(int i = 0; i < n; i++){
        TrieNode *node = root;
        for(int j = i; j < n; j++){
            if(node -> child[s[j] - 'a'] == NULL){
                node -> child[s[j] - 'a'] = new TrieNode();
                count++;
            }
            node = node -> child[s[j] - 'a'];
        }
    }
    return count;
}