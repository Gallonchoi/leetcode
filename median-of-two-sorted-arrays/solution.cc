#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    auto m = nums1.size();
    auto n = nums2.size();
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    int minidx = 0, maxidx = m, i, j, num1, mid = (m + n + 1) >> 1, num2;
    while (minidx <= maxidx) {
      i = (minidx + maxidx) >> 1;
      j = mid - i;
      if (i < m && j > 0 && nums2[j - 1] > nums1[i])
        minidx = i + 1;
      else if (i > 0 && j < n && nums2[j] < nums1[i - 1])
        maxidx = i - 1;
      else {
        if (i == 0)
          num1 = nums2[j - 1];
        else if (j == 0)
          num1 = nums1[i - 1];
        else
          num1 = max(nums1[i - 1], nums2[j - 1]);
        break;
      }
    }
    if (((m + n) & 1)) return num1;
    if (i == m)
      num2 = nums2[j];
    else if (j == n)
      num2 = nums1[i];
    else
      num2 = min(nums1[i], nums2[j]);
    return (num1 + num2) / 2.;
  }
};

int main(void) {
  auto s = new Solution;
  vector<int> nums1{};
  vector<int> nums2{2, 3};
  auto median = s->findMedianSortedArrays(nums1, nums2);
  std::cout << median << std::endl;
  return 0;
}
