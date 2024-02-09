LinkedListNode<int> *getMiddle(LinkedListNode<int> *&head){
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head -> next; //catch

    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

LinkedListNode<int> *reverseLL(LinkedListNode<int> *head){
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *next = NULL;

    while(curr){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(!head){
        return true;
    }

    LinkedListNode<int> *midNode = getMiddle(head);
    LinkedListNode<int> *temp = midNode -> next;
    midNode -> next = reverseLL(temp);

    LinkedListNode<int> *head1 = head;
    LinkedListNode<int> *reverseHead = midNode->next;

    while(reverseHead!=NULL){

        if(head1->data != reverseHead->data)
        return false;

        head1 = head1->next;
        reverseHead = reverseHead->next;

    }

    return true;

}