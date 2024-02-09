// You are given a singly linked list that may or may not contain a cycle. You are supposed to return the node where the cycle begins, if a cycle exists, else return 'NULL'.

Node *firstNode(Node *head)
{
    //    Write your code here.
    if(head == NULL && head -> next == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;
    
    while(fast -> next && fast -> next -> next){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            slow = head;
            while(fast != slow){
                fast = fast -> next;
                slow = slow -> next;
            }
            if(slow == fast){
                return slow;
            }
        }
    }
    return NULL;
}