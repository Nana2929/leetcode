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


/*
328. Odd Even Linked List
Thanks to @_LeetCoder25_.
https://leetcode.com/problems/odd-even-linked-list/solutions/1606963/c-simplest-solution-w-explanation-one-pass
I orginally used 5 pointers, 2 for odd, even, 1 for evenHead, 2 for prev nodes of odd and even.
The below solution is to use 3 pointers in total: 2 pointers for odd and even, and 1 for evenHead.
The key is that odd and even can actually be helpful for each other in L#41 and L#42.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // set 1 ptr to string the nodes of even together
        // set another pointer to string the nodes of odd together
        // concatenate them
        if (!head || !head->next){return head;}
        ListNode* oddPtr = head;
        ListNode* evenPtr = head->next;
        ListNode* evenHead= evenPtr;
        while (oddPtr->next && evenPtr->next){
            oddPtr->next=evenPtr->next;
            evenPtr->next=oddPtr->next->next;
            // 前兩行執行完後，=兩個 ptrs 變相往前一步（其 ->next 已經被改變）
            oddPtr=oddPtr->next;
            evenPtr=evenPtr->next;
        }
        oddPtr->next=evenHead;
        return head;
    }
};