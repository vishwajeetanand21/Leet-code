//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    /*
    LOGIC: 
    L: 1 2 3 4 5 6 7 8 9 NULL       k=3     O/P: 4 5 6 7 8 9 1 2 3 NULL
    
    
    STEP 1: Reverse the entire linked list
    L: 9 8 7 6 5 4 3 2 1 NULL
    
    
    STEP 2: Divide the linked list into 2 parts 1st to (n-k)th node and rest k nodes where n=length of the linked list
    L: (9 8 7 6 5 4) (1 2 3) 
    
    
    STEP 3: Reverse both the halves
    L: (4 5 6 7 8 9) (3 2 1)
    
    
    STEP 4: Join both the halves
    L: 4 5 6 7 8 9 1 2 3 NULL
    */
    
    // Function to reverse a linked list
    Node* reverseLL(Node*head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        Node*prevP=NULL;
        Node*currP=head;
        Node*nextP;
        
        while(currP!=NULL)
        {
            nextP=currP->next;
            currP->next=prevP;
            
            prevP=currP;
            currP=nextP;
        }
        return prevP;
    }
    
    // Function to calculate the length of the linked list
    int lengthLL(Node*head)
    {
        int count=0;
        Node*temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        int n=lengthLL(head);
        
        // edge case
        if(n==k)
        {
            return head;
        }
        
        // reverse the whole linked list
        Node*revHead=reverseLL(head);
        
        // traverse from 1st node to (n-k)th node and break the linked list into 2 parts
        int a=1;
        Node*temp=revHead;
        while(a!=(n-k))
        {
            temp=temp->next;
            a++;
        }
        
        // divide the linked list into 2 parts
        Node*firstHalf=revHead;
        Node*secondHalf=temp->next;
        // break the link
        temp->next=NULL;
        
        
        // reverse both the halves
        Node*revFirstHalf=reverseLL(firstHalf);
        Node*revSecondHalf=reverseLL(secondHalf);
        
        
        // Now join both the halves
        Node*temp2=revFirstHalf;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=revSecondHalf;
        
        // finally return the answer
        return revFirstHalf;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends