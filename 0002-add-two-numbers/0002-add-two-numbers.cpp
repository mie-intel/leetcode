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
 #define fi first
 #define se second
class Solution {
public:
    pair <int, int> uy(int a){
        return make_pair(a % 10, bool((a - (a % 10)) > 0));
    }
    int get(ListNode* x){
        if(x) return x->val;
        return 0;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode();
        ListNode *head = res;
        int simpan = 0;
        while(l1 || l2 || simpan > 0){
            // cout << (l1 ? l1->val : -1) << " " << (l2 ? l2->val : -1) << '\n';
            pair <int, int> p = uy(get(l1) + get(l2) + simpan);
            res->val = p.fi;
            simpan = p.se;
            // cout << "P " << p.fi << " " << p.se << '\n';
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            if(l1 || l2 || simpan > 0){
                // cout << "EA A\n";
                res->next = new ListNode();
                res = res->next;
            }
        }
        return head;
    }
};