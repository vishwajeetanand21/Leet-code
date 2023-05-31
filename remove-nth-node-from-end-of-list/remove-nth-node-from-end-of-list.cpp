/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // BETTER APPROACH is also available


    // Method 2
    // LOGIC: The code is for normal deletion of kth node from the start
    // But we have used the formulae to delete from the end
    // pos= n-k+1 
    // where n->length of the linked list
    //       k->position given be the user to delete from the right end
    ListNode* deleteNode(ListNode*head, int pos)
    {
        if(head==NULL)
        {
            return head;
        }
        if(pos==1)
        {
            return head->next;
        }
        ListNode*smallAns=deleteNode(head->next, pos-1);
        head->next=smallAns;
        return head;
    }
    int LengthLL(ListNode*head)
    {
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=LengthLL(head);

        int pos=len-n+1; //pos=n-k+1

        ListNode*answer=deleteNode(head, pos);
        return answer;
    }
    /*
    APPROACH 1
    LOGIC: Fast and slow pointer approach
    both fast and slow pointer are pointer to the head
    first fast pointer will to move n steps ahead
    
    then fast pointer will traverse till the last element 
    meanwhile slow pointer will also move one step towards right

    now slow->next is the node which we need to delete
    perform delete operation on the slow->next node
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=new ListNode();
        temp->next=head;

        ListNode*fast=temp;
        ListNode*slow=temp;
        
        for(int i=1;i<=n;i++)
        {
            fast=fast->next;
        }

        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        ListNode*a=slow->next;
        slow->next=a->next;
        delete a;
        return temp->next;
    }*/
};