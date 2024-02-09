// You are given a linked list having ‘n’ nodes and an integer ‘k’.



// You have to rotate the linked list to the right by ‘k’ positions .

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(!head || !head -> next || k == 0)
          return head;

     Node *temp = head;
     int length = 1;
     while(temp -> next != NULL){
          temp = temp -> next;
          length++;
     }

     k = k % length;
     temp -> next = head;
     int end = length - k;

     while(end--){
          temp = temp -> next;
     }
     head = temp -> next;
     temp -> next = NULL;
     return head;
}