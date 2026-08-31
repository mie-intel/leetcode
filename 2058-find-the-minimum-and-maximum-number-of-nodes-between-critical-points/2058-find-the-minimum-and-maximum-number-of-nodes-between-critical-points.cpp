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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int t = 0, len = 0;
        vector <int> c;
        int prev = -1;
        while(head){
            cout << head->val << ' ';
            if(prev == -1){
                prev = head->val;
                head = head->next;
                cout << "1\n";
            }
            else if(!head->next){
                cout << "2\n";
                break;
            }
            else{
                if(head->next->val > head->val && head->val < prev){
                    c.push_back(t);
                }
                else if(head->next->val < head->val && head->val > prev){
                    c.push_back(t);
                }
                prev = head->val;
                head = head->next;
                cout << "3\n";
            }
            t++;
        }
        cout << "OUTPUT: ";
        for(auto p : c){
            cout << p << " ";
        }
        cout << '\n';
        if(c.size() < 2) return {-1, -1};
        int mx = c.back() - c[0];
        int mn = mx;
        for(int i = 1; i < c.size(); ++i){
            mn = min(mn, c[i] - c[i-1]);
        }
        return {mn, mx};
    }
};