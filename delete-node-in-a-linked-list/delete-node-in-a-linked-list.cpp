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
    /*LOGIC: The approach is to copy the next node’s value in the deleted node. Then, link node to next of next node. This does not delete that node but indirectly it removes that node from the linked list.
    

                            delNode
                              ↓
                        1->2->3->4->5->NULL 
                                ↑
                                temp
          
    1. we will copy the data of temp to delNode, like this
    
                            delNode
                              ↓
                        1->2->4->4->5->NULL
                                ↑
                                temp
    
    2. now update delNode->next=temp->next;
    
                            delNode
                              ↓
                        1->2->4->5->NULL
                                 ↑
                           temp->4  
    
    3. and delete temp
    
                            delNode
                              ↓
                        1->2->4->5->NULL
    
    TC: O(1)
    SC: O(1)
    */
    void deleteNode(ListNode* node) {
        ListNode*temp=node->next;

        node->val=temp->val;

        node->next=temp->next;

        // delete temp
        delete temp;
    }
};