//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
// Function to merge 2 sorted linked list
Node* mergeTwoLL(Node*head1, Node*head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    Node*newHead=NULL;
    Node*newTail=NULL;
    if(head1->data<head2->data)
    {
        newHead=head1;
        newTail=head1;
        head1=head1->bottom;
    }
    else
    {
        newHead=head2;
        newTail=head2;
        head2=head2->bottom;
    }
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            newTail->bottom=head1;
            head1=head1->bottom;
            newTail=newTail->bottom;
        }
        else
        {
            newTail->bottom=head2;
            newTail=newTail->bottom;
            head2=head2->bottom;
        }
    }
    if(head1!=NULL)
    {
        newTail->bottom=head1;
    }
    if(head2!=NULL)
    {
        newTail->bottom=head2;
    }
    return newHead;
}
// Function to flatten the linked list
Node *flatten(Node *root)
{
   // Base call for recursion
   if(root==NULL || root->next==NULL)
   {
       return root;
   }
   
   // Calling the recursion on the second vertical linked list   
   root->next=flatten(root->next);
   
   // merging the first vertical LL with second LL
   root=mergeTwoLL(root, root->next);
   
   // returning the answer
   return root;
}

