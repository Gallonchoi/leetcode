// Remove all elements from a linked list of integers that have value val.
// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5
// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode T(0), *tmp;
        T.next = head;
        tmp = &T;
        while(tmp->next) {
            if(tmp->next->val == val) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }
        return T.next;
    }
};
