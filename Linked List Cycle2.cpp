#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node*floydDetectLoop(Node* head){
    if(head== NULL)
        return head;
    Node* slow=head;
    Node* fast=head;
    while(slow != NULL && fast != NULL){
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        slow=slow->next;
        if(slow==fast)
            return slow;
    }
    return NULL;
}

Node *firstNode(Node *head)
{
	if(head== NULL)
        return head;
        Node* intersection=floydDetectLoop(head);
        if(intersection == NULL)
            return NULL;
        Node*slow=head;
        while(slow != intersection){
            slow=slow->next;
            intersection=intersection->next;
        }
        return slow;
}