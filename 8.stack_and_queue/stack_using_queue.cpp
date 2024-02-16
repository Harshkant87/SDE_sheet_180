#include<queue>
class Stack {
	// Define the data members.
    queue<int> Q;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return Q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return Q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        Q.push(element);

        int s = Q.size() - 1;
        while(s){
            int elem = Q.front();
            Q.pop();
            Q.push(elem);
            s--;
        }
    }

    int pop() {
        // Implement the pop() function.
        if(Q.empty()){
            return -1;
        }else {
            int curr = Q.front();
            Q.pop();
            return curr;
        }
    }

    int top() {
        // Implement the top() function.
      if(Q.empty()) return -1;
      return Q.front();
    }
};