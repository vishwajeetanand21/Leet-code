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


// } Driver Code Ends
/* structure of list node:

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

class Solution{
  public:
     /*
    WHEN TWO LINKED LIST ARE SAID TO INTERSECT EACH OTHER?
    -> When the 2 Node address of are same
     L1:     4→1
               ↓
               8→4→5→NULL
               ↑
     L2:   5→6→1   
    
    Here there are two linked list 
        L1: 4->1->8->4->5->NULL
     L2: 5->6->1->8->4->5->NULL
    
    Here the address of 8 will be same in both the linked list
    */

    /*
    APPROACH: Using Unordered Set

    Step 1: We will traverse the first linked list and store the data of each node in our set
    Step 2: Then we will traverse the second linked list
            If the node data is present in the set
                then we'll create a newNode and keep on adding the common element in the answer list
            else
                return NULL 
    */
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_set<int>mySet;//set to store the data of linked list
        
        Node*newHead=NULL;//answer list head
        Node*newTail=NULL;//answer list tail
        
        while(head2!=NULL)//storing the data of second linked list in our set
        {
            mySet.insert(head2->data);
            head2=head2->next;
        }
        
        while(head1!=NULL)//traversing the first linked list
        {
            if(mySet.find(head1->data) != mySet.end()) 
            // if the current data is already present in our set, then we'll add the data in the answer list
            {
                Node*newNode=new Node(head1->data);//creating the node of the common data
                
                // the below code is for adding the elements in the answer linked list
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
            }
            head1=head1->next;
        }
        // at the end return the answer linked list
        return newHead;
    }
    
    /*
    BRUTE FORCE APPROACH
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        Node*newHead=NULL;
        Node*newTail=NULL;
        
        while(head1!=NULL)
        {
            Node*temp=head2;
            while(temp!=NULL)
            {
                if(temp==head1)
                {
                    Node*newNode=new Node(temp->data);
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
                }
                temp=temp->next;
            }
            
            head1=head1->next;
        }
        // newTail->next=NULL;
        return newHead;
    }*/
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends