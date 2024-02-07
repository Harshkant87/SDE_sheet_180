// You are given a Singly Linked List of integers. You need to reverse the Linked List by changing the links between nodes.



// Example:

// Input:
// 2 4 5 -1

// Output:
// 5 4 2 -1

Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}