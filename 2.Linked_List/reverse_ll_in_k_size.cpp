Node *getListAfterReverseOperationUtil(Node *head, int n, int b[],int i=0){

    if(head==nullptr){

        return head;

    }

    if(i>=n){

        return head;

    }

    if(b[i]==0){

        return getListAfterReverseOperationUtil(head,n, b,i+1);

    }

    Node* prev=nullptr;

    Node* nextNode=nullptr;

    Node* curr=head;

    int k=0;

    while(k<b[i] && curr!=nullptr){

        k++;

        Node* nextNode=curr->next;

        curr->next = prev;

        prev=curr;

        curr=nextNode;

    }

    

    if(curr!=nullptr){

        head->next = getListAfterReverseOperationUtil(curr,n,b,i+1);

    }

 

    return prev;

    

}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	return getListAfterReverseOperationUtil(head, n, b, 0);
}