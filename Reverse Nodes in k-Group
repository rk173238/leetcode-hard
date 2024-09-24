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
    //0 1 2 3 4 5 6
    pair<ListNode*, ListNode*> reverseNode(ListNode* aa,ListNode* bb){
        ListNode* a = aa;
        ListNode* b = bb;
        ListNode* prev = new ListNode(0);
        ListNode* cur = a;
        ListNode* next = a->next;
        // cout<<aa->val<<" "<<bb->val<<endl;
        while(next != bb){
            // cout<<cur->val<<" ";
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        a->next = NULL;
        return {cur,a};  // return head and tail after reversing
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* cur = head;
        ListNode* next = head->next;
        ListNode* prev = new ListNode(0);
        ListNode* ans = prev;
        
        while(next != NULL){
            int i = 0;
            bool check = false;
            ListNode* temp = cur;
            while(i<k){
                if(cur == NULL){
                    check = true;
                    break;
                }
                cur = cur->next;
                i++;
            }
            if(check){
                prev->next = temp;
                break;
            }
            auto result = reverseNode(temp,cur);
            prev->next = result.first;
            prev = result.second;
        }
        return ans->next;
    }
};

// 1 2 3 4 5 6
// 5 4 3 2 1 6
