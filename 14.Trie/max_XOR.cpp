#include<bits/stdc++.h>

class Node{
public:
    Node *child[2];
    Node(){
        child[0] = NULL;
        child[1] = NULL;
    }
};

class Trie{

    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
    
    
        void insert(int data){
            Node *node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (data >> i) & 1; // get the ith bit
                if(node -> child[bit] == NULL){
                    node -> child[bit] = new Node();
                }
                node = node -> child[bit];
            }
        }
    
        int findMax(int num){
            Node *node = root;
            int maxi = 0;

            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(node -> child[1 - bit] != NULL){
                    maxi = maxi | (1 << i); // choosing the maximum's bit
                    node = node -> child[1 - bit];
                }else{
                    node = node -> child[bit];
                }
            }
            return maxi;
        }

};

int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie trie;
    for(int i = 0; i < A.size(); i++){
        trie.insert(A[i]);
    }
    int maxNum = 0;
    for(int i = 0; i < A.size(); i++){
        maxNum = max(maxNum, trie.findMax(A[i]));
    }
    return maxNum;
}