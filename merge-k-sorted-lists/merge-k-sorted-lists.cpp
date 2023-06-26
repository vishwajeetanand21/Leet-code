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
    LOGIC: STEP 1: Make a minimum priority queue
           STPE 2: Put all the elements of the vector of lists
           STPE 3: Once your minimum priority queue is ready,
                   make a linked list from that priority queue
           STEP 4: Return the linked list 
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // using priority queue
        int n=lists.size();

        priority_queue<int, vector<int>, greater<int>>myQueue;

        // pushing all the elements in the priority queue
        for(int i=0;i<n;i++)
        {
            ListNode*curr=lists[i];
            while(curr!=NULL)
            {
                myQueue.push(curr->val);
                curr=curr->next;
            }
        }

        // making an answer linked list from the priority queue
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