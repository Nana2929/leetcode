/**
2095. Delete Middle of Linked List
- Two pointer solution
- use fast and slow pointers to find the middle of the linked list
- use `prev` pointer to keep track of the previous node of the middle node
- Finally, remove the middle node by setting `prev->next = middle->next`, that's it!

 */
#include <iostream>
struct ListNode
{
   int val;
   ListNode * next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode * next) : val(x), next(next) {}
};

class Solution
{
public:

   ListNode * deleteMiddle(ListNode * head)
   {
      if (!head || !head->next) return nullptr;
      ListNode * p1 = head;
      ListNode * p2 = head;
      ListNode * prev = nullptr;
      while (p1 && p1->next)
      {
         p1 = p1->next->next;
         prev = p2;
         p2 = p2->next;
      }
      if (prev) { prev->next = p2->next; }
      return head;
   }
};

int main()
{
   Solution s;
   ListNode * head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
   ListNode * result = s.deleteMiddle(head);
   // display
    while (result)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
   return 0;
}