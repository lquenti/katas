 struct ListNode {
     int val;
     struct ListNode *next;
 };

int gcd(int a, int b) {
  if (a == b) {
    return a;
  }
  return (a>b) ? gcd(a-b, b) : gcd(a, b-a);
}

#include<stdlib.h>
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
  struct ListNode *ret = head;
  while (head->next != NULL) {
    int x = gcd(head->val, head->next->val);
    struct ListNode *y = malloc(sizeof(struct ListNode));
    y->val = x;
    y->next = head->next;
    head->next = y;
    head = head->next->next;
  }
  return ret;
}
