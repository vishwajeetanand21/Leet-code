//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

/*
The logic is simple
L1: 1->2->3->4->6->NULL
L2: 2->4->6->8->NULL

Both the linked list are sorted

Step 1: we will create an answer linked list to store the common elements in both the list
Step 2: We will traverse both the list
            if the head1->data == head2->data :This means it's a common element
                create a newNode and add to the answer linked list
            if the head1->data < head2->data 
                move the head1 to the next node
            if the head1->data > head2->data
                move the second linked list to the next node
Step 3: By this all the common elements will be appended to the answer linked list
*/
Node* findIntersection(Node* head1, Node* head2)
{
    // answer linked list
    Node*newHead=NULL;
    Node*newTail=NULL;
    
    while(head1!=NULL && head2!=NULL) //traverse both the linked list simultaneously
    {
        if(head1->data == head2->data)//it's a common element
        {
            Node*newNode=new Node(head1->data);//create a newNode and append it to the answer linked list
            
            // below code is for appending the newNode to the answer linked list
            if(newHead==NULL)
            {
                newHead=newNode;
                newTail=newNode;
            }
            else
            {
                newTail->next=newNode;
                newTail=newTail->next;
            }
            head1=head1->next;
            head2=head2->next;
        }
        
        // this means data of first list is less than the data of the second list
        else if(head1->data < head2->data)
        {
            head1=head1->next; //move the first list to the next node
        }
        
        //this means data of the second list is less than the data of the first list 
        else if(head1->data > head2->data)
        {
            head2=head2->next;//move the second list to the next node
        }
    }
    return newHead;//finally return the answer list
}