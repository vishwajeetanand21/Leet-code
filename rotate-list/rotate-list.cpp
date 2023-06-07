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
    ListNode*reverseLL(ListNode*head)
    {
        if(head==NULL ||  head->next==NULL)
        {
            return head;
        }

        ListNode*prevP=NULL;
        ListNode*currP=head;
        ListNode*nextP;

        while(currP!=NULL)
        {
            nextP=currP->next;
            currP->next=prevP;

            prevP=currP;
            currP=nextP;
        }
        return prevP;
    }
    int lengthLL(ListNode*head)
    {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    if(k==0)
    {
        return  head;
    }

    // if k is more than the length of the linked list
    int new_k=k % lengthLL(head);

    if(k%lengthLL(head)==0)
    {
        return head;
    }

    // STEP 1: full reverse linked list
    ListNode*fullReverse=reverseLL(head);

    // STEP 2: find the first half
    ListNode*firstHalf=fullReverse;

    ListNode*temp=firstHalf;
    for(int i=0;i<new_k-1;i++)
    {
        temp=temp->next;
    }

    // second half
    ListNode*secondHalf=temp->next;


    // break the link
    temp->next=NULL;

    // reverse the first half
    ListNode*reversedFirstHalf=reverseLL(firstHalf);

    // reverse the second half
    ListNode*reversedSecondHalf=reverseLL(secondHalf);

    // join both the halves
    ListNode*temp2=reversedFirstHalf;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=reversedSecondHalf;

    // finally return the reversedfirstHalf
    return reversedFirstHalf;
    }
};