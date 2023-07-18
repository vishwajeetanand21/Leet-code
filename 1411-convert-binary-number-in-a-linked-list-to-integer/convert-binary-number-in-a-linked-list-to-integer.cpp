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
    /*
    APPROACH 1: Using Array to store the binary values
    TC=O(N)
    SC=O(N)

    LOGIC: First store the values of the linked list in the array
           Then traverse from right to left

           1 0 1
           =(1*2²)+(0*2¹)+(1*2⁰)
           =(4)+(0)+(1)
           =5
    */
    int getDecimalValue(ListNode* head) 
    {
        vector<int>arr;

        ListNode*temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }

        int answer=0;
        int power=0;

        for(int i=arr.size()-1;i>=0;i--)
        {
            int a=arr[i];
            int b=pow(2, power);

            answer+= a*b;

            power++;
        }
        return answer;
    }
};