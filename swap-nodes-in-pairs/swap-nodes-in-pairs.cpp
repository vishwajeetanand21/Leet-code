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
    int lengthLL(ListNode*head)
    {
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* dummy = new ListNode(0);  // Dummy node to handle the head swapping
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* first = head;
    ListNode* second = head->next;

    while (first != NULL && second != NULL) {
        // Swapping the adjacent nodes
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // Updating pointers for the next iteration
        prev = first;
        first = first->next;
        if (first != NULL) {
            second = first->next;
        }
    }

    ListNode* newHead = dummy->next;
    delete dummy;

    return newHead;
    }
};