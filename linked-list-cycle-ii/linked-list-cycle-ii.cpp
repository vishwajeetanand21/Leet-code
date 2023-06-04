/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>mySet;

        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(mySet.find(temp)!=mySet.end())
            {
                return temp;
            }
            mySet.insert(temp);
            temp=temp->next;
        }
        return NULL;
    }
};