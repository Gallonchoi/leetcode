
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto head = new ListNode(0);
    auto pivot = head;

    while (l1 || l2) {
      if (l1 && l2) {
        if (l1->val < l2->val) {
          pivot = pivot->next = l1;
          l1 = l1->next;
        } else {
          pivot = pivot->next = l2;
          l2 = l2->next;
        }
      } else if (l1) {
        while (l1) {
          pivot = pivot->next = l1;
          l1 = l1->next;
        }
      } else {
        while (l2) {
          pivot = pivot->next = l2;
          l2 = l2->next;
        }
      }
    }
    auto result = head->next;
    delete head;
    return result;
  }
};
