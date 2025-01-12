//
// Created by 12582 on 2024/6/22.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x) : val(x), next(nullptr), prev(nullptr){}  // 节点的构造函数
};

ListNode *reverseSectionList(ListNode *pNode, ListNode *pNode1);

ListNode* reverseList(ListNode *head){
    ListNode *temp;
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while(cur){
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;

}

ListNode *reverseSectionList(ListNode *begin, ListNode *end);

ListNode* reverseKGroup(ListNode *head, int k){
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *cur = head;
    int count = 0;
    while(cur){
        count++;
        cur = cur->next;
        if(count == k){
            cur = pre->next;
            pre->next = reverseSectionList(pre->next, cur);
            count = 0;
        }
    }
    return dummy->next;
}

ListNode *reverseSectionList(ListNode *begin, ListNode *end) {
    ListNode *temp;
    ListNode *cur = begin;
    ListNode *pre = nullptr;
    while(begin != end){
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return begin;
}

int main() {
    ListNode *list = new ListNode(0);
    list->next = new ListNode(1);
    list->next->next = new ListNode(2);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(4);
    list->next->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next->next = new ListNode(6);
    ListNode *head = reverseList(list);;
    while (head){
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}
