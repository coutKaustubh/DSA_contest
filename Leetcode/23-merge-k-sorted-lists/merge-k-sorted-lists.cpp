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
        int n = lists.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            ListNode* temp = lists[i];

            while(temp) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(!pq.empty()) {
            curr->next = new ListNode(pq.top());
            pq.pop();

            curr = curr->next;
        }

        return dummy->next;
    }
};