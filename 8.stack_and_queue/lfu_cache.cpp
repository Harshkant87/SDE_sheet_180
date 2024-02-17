struct node {
    int key, value, cnt;
    node *prev,*next; 
    node(int k, int v) {
        key = k;
        value = v; 
        cnt = 1; 
    }
}; 
struct List {
    int size; 
    node *head,*tail; 
    List() {
        head = new node(-1,-1); 
        tail = new node(-1,-1); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void addNode(node *n) {
        node *t=head->next;
        head->next=n;
        n->prev=head;
        n->next=t;
        t->prev=n;
        size++; 
    }
    
    void deleteNode(node* n) {
        node *temp=n->next;
        n->prev->next=temp;
        temp->prev=n->prev;
        size--; 
    }
    
};
class LFUCache {
    unordered_map<int, node*> keyNode; 
    unordered_map<int, List*> freqMap; 
    int maxSize;
    int minFreq; 
    int curSize; 
public:
    LFUCache(int capacity) {
        maxSize = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    void updatefreqMap(node *n) {
        keyNode.erase(n->key); 
        freqMap[n->cnt]->deleteNode(n); 
        if(n->cnt == minFreq && freqMap[n->cnt]->size == 0) {
            minFreq++; 
        }
        
        List *newlist;
        if(freqMap.find(n->cnt+1)!=freqMap.end())
            newlist=freqMap[n->cnt+1];
        else{
            newlist=new List();
        }
        n->cnt += 1; 
        newlist->addNode(n); 
        freqMap[n->cnt] = newlist; 
        keyNode[n->key] = n;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            node* n = keyNode[key]; 
            int res = n->value; 
            updatefreqMap(n); 
            return res; 
        }
        return -1; 
    }
    
    void put(int k, int v) {
        if(keyNode.find(k) != keyNode.end()) {
            node* n = keyNode[k]; 
            n->value = v; 
            updatefreqMap(n); 
        }
        else {
            if(curSize == maxSize) {
                List* list = freqMap[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                freqMap[minFreq]->deleteNode(list->tail->prev);
                curSize--; 
            }
            minFreq = 1; 
            curSize++;  

            List *newlist;
            if(freqMap.find(minFreq)!=freqMap.end())
                newlist=freqMap[minFreq];
            else{
                newlist=new List();
            } 

            node* n = new node(k, v); 
            newlist->addNode(n);
            keyNode[k] = n; 
            freqMap[minFreq] = newlist; 
        }
    }
};