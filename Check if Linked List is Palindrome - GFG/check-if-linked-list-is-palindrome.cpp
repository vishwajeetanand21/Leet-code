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
    /*Optimized Solution
    
    1. Find the middle element of the linked list. 
    2. Reverse a linked list from the next element of the middle element.
    3. Iterate through the new list until the middle element reaches the end of the list.
    4. Use a temp node to check if the same element exists in the linked list from the middle element.
    
    DRY RUN:
    L: 1->2->3->3->2->1->NULL
       ↑
      head

    STEP 1. Find the middle element of the linked list

        1->2->3->3->2->1->NULL
        ↑     ↑
        head  mid
    
    STEP 2: Reverse a linked list from the next element of the middle element.

        1->2->3->1->2->3->NULL
        ↑     ↑
        head  mid
    
    STEP 3: Move the mid pointer to the next element

        1->2->3->1->2->1->NULL
        ↑        ↑
        head    mid
    
    STEP 4: Now keep a temp pointer at the head and traverse untill mid!=NULL

       head
        ↓
        1->2->3->1->2->1->NULL
        ↑        ↑
        temp    mid


        while(mid!=NULL)
        {
            if(temp->data != mid->data)
                return false;
            mid=mid->next;
            temp=temp->next;
        }
        return true;
    */
    Node*midElement(Node*head)
    {
        Node*slow=head;
        Node*fast=head->next;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node*reverseLL(Node*head)
    {
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
        head=prevP;
        return head;
    }    
    bool isPalindrome(Node *head)
    {
        // if the linked list is empty or only one node is present then it's already a palindrome 
        if(head==NULL || head->next==NULL)
        {
            return true;
        }

        // finding the mid element
        Node*mid=midElement(head);

        // reversing the list from the next element of mid 
        mid->next=reverseLL(mid->next);
    
        // moving mid to the next element 
        mid=mid->next;

        // temp will start from the begining
        Node*temp=head;

        while(mid!=NULL)
        {
            if(mid->data!=temp->data)
            {
                return false;
            }
            mid=mid->next;
            temp=temp->next;
        }
        return true;
    }
    
    
    
    /* BRUTE FORCE APPROACH: USING EXTRA VECTOR TO STORE THE ELEMENTS AND CHECKING IF IT IS PALINDROME OR NOT!
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
    }*/
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