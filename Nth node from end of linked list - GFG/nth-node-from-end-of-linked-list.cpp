//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    /*
    LOGIC: To find the nth node from the end of the linked list we will use a formulae
           pos=len-n+1 
           this will give us the node which we have to print by traversing from left to right
    */
    int lengthLL(Node*head)
    {
        int ans=0;
        Node*temp=head;
        while(temp!=NULL)
        {
            ans++;
            temp=temp->next;
        }
        return ans;
    }
    int helperFunction(Node*head, int pos)
    {
        int counter=1;
        Node*temp=head;
        while(counter!=pos)
        {
            temp=temp->next;
            counter++;
        }
        return temp->data;
    }
    int getNthFromLast(Node *head, int n)
    {
        // Your code here
        int len=lengthLL(head);
        
        int pos=len-n+1;
        
        if(pos<=0 || pos>len)
        {
            return -1;
        }
        
        return helperFunction(head, pos);
    }
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends