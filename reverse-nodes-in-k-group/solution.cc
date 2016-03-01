#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  int getNodeLen(ListNode* node) const {
    if (node) return 1 + getNodeLen(node->next);
    return 0;
  }
  ListNode* getNextKNode(ListNode* node, int k) const {
    if (!node) return node;
    if (k > 1) return getNextKNode(node->next, k - 1);
    return node;
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k <= 1) return head;
    int len = getNodeLen(head);
    ListNode* nodes[k];
    auto pivot = head;
    auto new_head = new ListNode(0);
    auto new_pivot = new_head;
    while (len >= k) {
      for (int i = 0; i < k; ++i) {
        nodes[i] = pivot;
        pivot = pivot->next;
        --len;
      }
      for (int i = k - 1; i > 0; --i) {
        nodes[i]->next = nodes[i - 1];
      }
      nodes[0]->next = nullptr;
      new_pivot->next = nodes[k - 1];
      new_pivot = nodes[0];
    }
    new_pivot->next = pivot;
    auto result = new_head->next;
    delete new_head;
    return result;
  }
};

int main(void) {
  Solution s;
  auto x1 = new ListNode(1);
  auto x2 = new ListNode(2);
  auto x3 = new ListNode(3);
  x1->next = x2;
  // x2->next = x3;
  auto r = s.reverseKGroup(x1, 2);
  while (r) {
    std::cout << r->val << std::endl;
    r = r->next;
  }
  return 0;
}
