class Node {
public:
    Node *child[26];
    bool isTerminal;

    Node(){
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
        
        isTerminal = false;
    }

};

class Trie {
public:
    Node *root;

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(node -> child[word[i] - 'a'] == NULL){
                node -> child[word[i] - 'a'] = new Node();
            }
            node = node -> child[word[i] - 'a'];
        }
        node -> isTerminal = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(node -> child[word[i] - 'a'] == NULL)
                return false;
            node = node -> child[word[i] - 'a'];
        }
        return node -> isTerminal;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(node -> child[prefix[i] - 'a'] == NULL)
                return false;
            node = node -> child[prefix[i] - 'a'];
        }
        return true;
    }
};