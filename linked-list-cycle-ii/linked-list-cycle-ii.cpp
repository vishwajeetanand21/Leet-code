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
    /*
    Approach: USING FAST AND SLOW POINTER

The following steps are required:

    -> Initially take two pointers, fast and slow. 
    -> The fast pointer takes two steps ahead while the slow pointer will take a single step.
    -> We know that if a cycle exists, fast and slow pointers will collide.
    -> If the cycle does not exist, the fast pointer will move to NULL
    -> Else, when both slow and fast pointer collides, it detects a cycle exists.
    -> Take another pointer, say entry. Point to the very first of the linked list.
    -> Move the slow and the entry pointer ahead by single steps until they collide. 
    -> Once they collide we get the starting node of the linked list.

    FOR REFERENCE: https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
    */
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }

        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*entry=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                while(slow!=entry)
                {
                    entry=entry->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }

    /* BRUTE FORCE SOLUTION: USING SET TO STORE THE ADDRESS OF EACH NODE
     AND IF THE ADDRESS IS ALREADY PRESENT IN THE SET, IT MEANS THE CYCLE START FROM THAT NODE
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
    }*/
};