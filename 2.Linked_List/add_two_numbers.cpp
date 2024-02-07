// Input:
// 'num1' : 1 -> 2 -> 3 -> NULL
// 'num2' : 4 -> 5 -> 6 -> NULL

// Output: 5 -> 7 -> 9 -> NULL

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *dummyHead = new Node();
    Node *temp = dummyHead;
    int carry = 0;
    

    while(num1 || num2 || carry){
        int sum = 0;
        if(num1){
            sum += num1 -> data;
            num1 = num1 -> next;
        }

        if(num2){
            sum += num2 -> data;
            num2 = num2 -> next;
        }

        sum += carry;
        Node *node = new Node(sum % 10);
        carry = sum/10;
        temp -> next = node;
        temp = temp -> next; 
    }
    return dummyHead -> next;
}