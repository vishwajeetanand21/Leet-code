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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL ||head->next==NULL)
    {
        return head;
    }
    
    //calling recursion
    ListNode*smallAns=reverseList(head->next);
    /*at this point of time
    head=1-address of 2
    smallAns=5--4-3-2-NULL*/
    
    
    ListNode*temp=smallAns;/*temporary variable to tarverse the linked list 
    which we got from recursion*/
    
    
    //loop to traverse the LL, which we got from recursion
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next=head;//connecting the end of the LL with our head
    head->next=NULL;//1 is connected to 2, so we need to break the link
    return smallAns;//and returninthe answer
    }
};