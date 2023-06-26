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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // using priority queue
        int n=lists.size();

        priority_queue<int, vector<int>, greater<int>>myQueue;

        for(int i=0;i<n;i++)
        {
            ListNode*curr=lists[i];
            while(curr!=NULL)
            {
                myQueue.push(curr->val);
                curr=curr->next;
            }
        }

        // making an answer linked list
        ListNode*head=NULL;
        ListNode*tail=NULL;

        while(myQueue.size()!=0)
        {
            if(head==NULL)
            {
                ListNode*newNode= new ListNode(myQueue.top());
                head=newNode;
                tail=newNode;
                myQueue.pop();
            }
            else
            {
                ListNode*newNode=new ListNode(myQueue.top());
                tail->next=newNode;
                tail=tail->next;
                myQueue.pop();
            }
        }

        return head;
    }
};