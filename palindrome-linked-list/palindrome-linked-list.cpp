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
    ListNode*midElement(ListNode*head)
    {
        ListNode*slow=head;
        ListNode*fast=head->next;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode*reverseLL(ListNode*head)
    {
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
        head=prevP;
        return head;
    }
    bool isPalindrome(ListNode* head) 
    {
        ListNode*mid=midElement(head);

        mid->next=reverseLL(mid->next);
        mid=mid->next;

        ListNode*temp=head;

        while(mid!=NULL)
        {
            if(mid->val!=temp->val)
            {
                return false;
            }
            mid=mid->next;
            temp=temp->next;
        }
        return true;
    }

    /* BRUTE FORCE APPROACH
    bool isPalindrome(ListNode* head) {
        vector<int>arr;

        ListNode*temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
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