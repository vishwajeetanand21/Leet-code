//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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
#include <bits/stdc++.h>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    // BRUTE FORCE APPROACH: USING EXTRA VECTOR TO STORE THE ELEMENTS AND CHECKING IF IT IS PALINDROME OR NOT!
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int>arr;

        Node*temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->data);
            temp=temp->next;
        }

        int n=arr.size();

        for(int i=0,j=n-1;i<j;i++,j--)
        {
            if(arr[i]!=arr[j])
            {
                return false;
            }
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends