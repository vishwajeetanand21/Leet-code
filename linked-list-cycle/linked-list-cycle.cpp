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
    LOGIC: SET METHOD
        we will traverse the linked list
        we will maintain a set to store the address of each node
        and if the address of current node is already present in our set
        then it means that there is a cycle in the linked list
*/
    bool hasCycle(ListNode *head) {
        // set to store the address of each node
        unordered_set<ListNode*>mySet;

        // if there is 0 or 1 node there cannot be any cycle
        if(head==NULL || head->next==NULL)
        {
            return false;
        }


        ListNode*temp=head;
        bool ans=false; // answer variable

        while(temp!=NULL)// traverse the linked list
        {
            if(mySet.find(temp)!=mySet.end())// if the address of current node is already present in the set
            {
                ans=true;//this means that there is a cycle in the linked list
                break;//come out of the loop
            }
            mySet.insert(temp); //add the address of the current node in the set 
            temp=temp->next;//move the list to the next node
        }

        return ans;//finally return the answer
    }
};