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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>mySet;

        if(head==NULL || head->next==NULL)
        {
            return 0;
        }


        ListNode*temp=head;
        bool ans=0;

        while(temp!=NULL)
        {
            if(mySet.find(temp)!=mySet.end())
            {
                ans=1;
                break;
            }
            mySet.insert(temp);
            temp=temp->next;
        }

        return ans;
    }
};