//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    /*
    LOGIC: We know how to add two numbers represented by a linked list as the following
            2->4->3
            5->6->4
        Ans:7->0->8
        As in leetcode from left to right
        
        But here in gfg the pattern is reversed 
            2->4->3
            5->6->4
        Ans:8->0->7
        
        One of the approach will be: TO REVERSE BOTH THE LIST and calculate sum THEN REVERSE THE ANSWER AS WELL
        For example
            3->4->2
            4->6->7
        Ans:7->0->8
Reverse Ans:8->0->7 (REQUIRED ANSWER)

    CONCLUSION:
            STEP 1. REVERSE BOTH THE LIST
            STEP 2. CALCULATE SUM FROM LEFT TO RIGHT (Same as LeetCode)
            STEP 3. REVERSE THE FINAL ANSWER 
    */
    
    // function to reverse a linked list by iterative method
    struct Node* reverseLL(struct Node*head)
    {
        struct Node*prevP=NULL;
        struct Node*currP=head;
        struct Node*nextP;
        
        while(currP!=NULL)
        {
            nextP=currP->next;
            currP->next=prevP;
            
            prevP=currP;
            currP=nextP;
        }
        head=prevP;
        return head;
    }
    
    //function to add two numbers represented as linked list
    struct Node* addTwoListsHelper(struct Node*head1, struct Node*head2)
    {
        struct Node*newHead=NULL;
        struct Node*newTail=NULL;
        
        int carry=0;
        
        while(head1!=NULL || head2!=NULL || carry)
        {
            int sum=0;
            
            if(head1!=NULL)
            {
                sum+=head1->data;
                head1=head1->next;
            }
            if(head2!=NULL)
            {
                sum+=head2->data;
                head2=head2->next;
            }
            sum+=carry;
            
            carry=sum/10;
            
            struct Node*newNode=new Node(sum%10);
            
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
        return newHead;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        //reverse both the Linked list
        struct Node*head1=reverseLL(first);
        struct Node*head2=reverseLL(second);
        
        // we got an answer which we need to reverse
        struct Node*ans=addTwoListsHelper(head1, head2);
        
        // reverse the answer and return it
        struct Node*finalAns=reverseLL(ans);
        
        return finalAns;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends