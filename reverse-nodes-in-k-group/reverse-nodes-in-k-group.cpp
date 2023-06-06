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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // This below code will handle the last part of the linked list
    // if there is only 2 node at the end and k is 3-> then it will simply return the head, don't reverse anything
        ListNode*temp=head;
        for(int i=0;i<k;i++)
        {
            if(temp==NULL)
            {
                return head;
            }
            temp=temp->next;
        }

        // bass call
        if(head==NULL)
        {
            return head;
        }

        // STEP 1: Reverse k linked list
        ListNode*prevP=NULL;
        ListNode*currP=head;
        ListNode*nextP;
        int count=0;

        while(currP != NULL && count<k)
        {
            nextP=currP->next;
            currP->next=prevP;

            prevP=currP;
            currP=nextP;

            count++;
        }

        // STEP 2: Make a recursion call on the rest of the linked list 
        if(nextP!=NULL)
        {
            head->next=reverseKGroup(nextP, k);
        }

        return prevP;
    }
    /* ITERATIVE APPROACH
    int lengthOfLinkedList(ListNode* head) 
    {
        int length = 0;
        while(head != NULL) 
        {
            ++length;
            head = head->next;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == NULL||head->next == NULL) return head;
    
        int length = lengthOfLinkedList(head);
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* pre = dummyHead;
        ListNode* cur;
        ListNode* nex;
        
        while(length >= k) 
        {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++) 
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            length -= k;
        }
        return dummyHead->next;
    }*/
};