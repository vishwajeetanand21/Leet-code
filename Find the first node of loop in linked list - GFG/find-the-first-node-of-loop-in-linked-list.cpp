//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    /*
    Approach: USING FAST AND SLOW POINTER

The following steps are required:
    -> Initially take two pointers, fast and slow. 
    -> The fast pointer takes two steps ahead while the slow pointer will take a single step.
    -> We know that if a cycle exists, fast and slow pointers will collide.
    -> If the cycle does not exist, the fast pointer will move to NULL
    -> Else, when both slow and fast pointer collides, it detects a cycle exists.
    -> Take another pointer, say entry. Point to the very first of the linked list.
    -> Move the slow and the entry pointer ahead by single steps until they collide. 
    -> Once they collide we get the starting node of the linked list.

    FOR REFERENCE: https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
*/
    int findFirstNode(Node* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head->data;
        }
        
        Node*slow=head;
        Node*fast=head;
        Node*entry=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                while(slow!=entry)
                {
                    slow=slow->next;
                    entry=entry->next;
                }
                return slow->data;
            }
        }
        return -1;
    }
    
    
    
     //Function to find first node if the linked list has a loop.
    /* BRUTE FORCE SOLUTION: USING SET TO STORE THE ADDRESS OF EACH NODE
    AND IF THE ADDRESS IS ALREADY PRESENT IN THE SET, IT MEANS THE CYCLE START FROM THAT NODE
    int findFirstNode(Node* head)
    {
        // your code here
        unordered_set<Node*>mySet;
        
        Node*temp=head;
        
        while(temp!=NULL)
        {
            if(mySet.find(temp)!=mySet.end())
            {
                return temp->data;
            }
            mySet.insert(temp);
            temp=temp->next;
        }
        return -1;
    }*/
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
	return 0;
}
// } Driver Code Ends