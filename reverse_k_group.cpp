//
// Created by 12582 on 2024/6/23.
//

#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x) : val(x), next(nullptr), prev(nullptr){}  // 节点的构造函数
};


pair<ListNode *, ListNode *> reverse_list(ListNode *head, ListNode *tail) {
    ListNode *prev = tail->next;
    ListNode *p = head;
    while (prev != tail) {
        ListNode *nex = p->next;
        p->next = prev;
        prev = p;
        p = nex;
    }
    return {tail, head};
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = dummy;
    while (head) {
        ListNode *tail = prev;
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
            if (!tail) {
                return dummy->next;
            }
        }
        ListNode *nex = tail->next;
        pair<ListNode *, ListNode *> p = reverse_list(head, tail);
        prev->next = p.first;
        p.second->next = nex;
        prev = p.second;
        head = p.second->next;
    }
    return dummy->next;
}

int main() {
    ListNode *list = new ListNode(0);
    list->next = new ListNode(1);
    list->next->next = new ListNode(2);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(4);
    list->next->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next->next = new ListNode(6);

    ListNode *result = reverseKGroup(list, 3);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
