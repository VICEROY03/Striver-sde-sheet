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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        int size=0, cnt=0;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        while(head!=NULL){
            cnt++;
            if(size%2 && cnt==1+size/2){           
                head=head->next;
                continue;
            }
            else if(cnt>size/2){
                if(head->val!=st.top())                  
                    return 0;
                st.pop();
            }
            else
                st.push(head->val);
            head=head->next;
        }
        return 1;
    }
};