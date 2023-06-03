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
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_set<int>mySet;
        
        Node*newHead=NULL;
        Node*newTail=NULL;
        
        while(head2!=NULL)
        {
            mySet.insert(head2->data);
            head2=head2->next;
        }
        
        while(head1!=NULL)
        {
            if(mySet.find(head1->data) != mySet.end())
            {
                Node*newNode=new Node(head1->data);
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