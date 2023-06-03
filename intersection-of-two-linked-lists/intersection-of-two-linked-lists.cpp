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
    WHEN TWO LINKED LIST ARE SAID TO INTERSECT EACH OTHER?
    -> When the 2 Node address of are same
     L1:     4→1
               ↓
               8→4→5→NULL
               ↑
     L2:   5→6→1   
    
    Here there are two linked list 
        L1: 4->1->8->4->5->NULL
     L2: 5->6->1->8->4->5->NULL
    
    Here the address of 8 will be same in both the linked list
    */

    /*
    APPROACH: Using HashMap

    Step 1: We will traverse the first linked list and store the address of each node
    Step 2: Then we will traverse the second linked list
            If the node address is present in the map
                then return that node thereafter of the second list
            else
                return NULL 
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>mySet;  //This map will store the address of each node

        // storing the address of each node in our map
        while(headA!=NULL)
        {
            mySet.insert(headA);
            headA=headA->next;
        }

        // now traverse the second linked list
        while(headB!=NULL)
        {
            // if the current node address is there in our map
            if(mySet.find(headB) != mySet.end())
            {
                return headB; //this means it is our intersection point
            }
            // otherwise keep moving in the second linked list
            headB=headB->next;
        }
        return NULL; //if no intersection point then retun NULL
    }

    /* BRUTE FORCE APPROACH: 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA != NULL)
        {
            ListNode*temp=headB;
            while(temp!=NULL)
            {
                if(headA == temp)
                {
                    return temp;
                }
                temp=temp->next;
            }

            headA=headA->next;
        }
        return NULL;
    }*/
};