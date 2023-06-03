//{ Driver Code Starts
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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    /*LOGIC: Counting sort
            Count the number of zeros, ones and twos
            then make a new answer linked list
            
            then keep on adding first zeros to the answer list untill it reaches the total number of zeros
            similarly do it for ones
            similarly do it for twos
            
            finally return the answer linked list
    */ 
    Node* segregate(Node *head) {
        
        // variables to store the number of 0s, 1s and 2s
        int zeros=0, ones=0, twos=0;
        
        Node*temp=head; //variable to traverse the given linked list
        
        while(temp!=NULL)//traverse the linked list and store the number of 0s, 1s and 2s
        {
            if(temp->data==0)
            {
                zeros++;
            }
            else if(temp->data==1)
            {
                ones++;
            }
            else
            {
                twos++;
            }
            temp=temp->next;
        }
        
        // make an answer linked list
        Node*newHead=NULL;
        Node*newTail=NULL;
        
        // keep on adding 0 to the answer list untill the count is equal to the total number of zeros
        for(int i=0;i<zeros;i++)
        {
            Node*newNode=new Node(0); //make a node with data 0
            
            // below code is for adding the data in the answer linked list
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
        
        // similarly do it for ones
        for(int i=zeros;i<(zeros+ones);i++)
        {
            Node*newNode=new Node(1);
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
        
        // similarly do it for twos
        for(int i=(zeros+ones); i<(zeros+ones+twos);i++)
        {
            Node*newNode=new Node(2);
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
        
        // finally return the answer linked list
        return newHead;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends