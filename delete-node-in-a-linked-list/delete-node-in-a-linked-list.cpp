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
    /*LOGIC: Copy 

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
    
    3. and make temp->next=NULL
    
                            delNode
                            ↓
                        1->2->4->5->NULL

                        temp->3->NULL
    
    TC: O(1)
    SC: O(1)
    */
    void deleteNode(ListNode* node) {
        ListNode*temp=node->next;

        node->val=temp->val;

        node->next=temp->next;

        temp->next=NULL;
    }
};