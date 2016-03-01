#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    int len = lists.size();
    while (len > 1) {
      for (int i = 0; i < len / 2; ++i) {
        lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
      }
      len = (len + 1) / 2;
    }
    return lists.front();
  }
};

int main(void) {
  Solution s;
  vector<ListNode*> lists{new ListNode(0), new ListNode(1)};
  s.mergeKLists(lists);
  return 0;
}
