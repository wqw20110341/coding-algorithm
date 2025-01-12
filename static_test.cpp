//
// Created by 12582 on 2024/7/6.
//

#include <bits/stdc++.h>
#include "const_test.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}  // 节点的构造函数
};


ListNode *middleNode(ListNode *head) {
    if (head == nullptr || head->next == nullptr)  // 只有一个或者没有节点
        return head;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;  // slow 就是中间的节点

}

ListNode *deleteMiddle(ListNode *head) {
    if (head == nullptr) {// 只有一个或者没有节点
        return head;
    } else if (head->next == nullptr) {
        delete head;  // 只有一个节点
        return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *mid_prev = head;
    while (fast && fast->next) {
        mid_prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    mid_prev->next = slow->next;
    delete slow;  // 释放掉中间节点
    return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == nullptr)  // 只有一个或者没有节点
        return head;
    ListNode *fast = head;
    ListNode *slow = head;
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }
    if (fast == nullptr) {  // 删除头部
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;

}

class StaticClassTest;

class StaticClassTest {
public:
    static ListNode *node;

    virtual ~StaticClassTest() = default;

    static StaticClassTest &getInstance() {
        static StaticClassTest m_instance;
//        if(node == nullptr)
//            node = new ListNode(19);  // 只有在第一次使用getInstance()时才创建node
        return m_instance;
    }
};


int static_test() {
    static auto *node_x = new ListNode(10);
    return 0;
}


int pairSum(ListNode *head) {
    if (head == nullptr)
        return 0;
    int sum = 0;
    ListNode *slow = head;
    ListNode *fast = head;
    vector<int> tmp;
    while (fast && fast->next) {
        tmp.push_back(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    for (int i = (int) tmp.size() - 1; i >= 0; i--) {
        if (sum < tmp[i] + slow->val) {
            sum = tmp[i] + slow->val;
        }
        slow = slow->next;
    }
    return sum;
}

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur!= nullptr) {
        ListNode *next_node = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next_node;
    }
    return pre;
}


int main() {
//    static_test();
//    int p[] = {1, 3};
//    StaticClassTest node = StaticClassTest::getInstance();
//    node.node->val = 8;
    ListNode *list = new ListNode(0);
    list->next = new ListNode(1);
    list->next->next = new ListNode(2);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(4);
    list->next->next->next->next->next = new ListNode(5);

    int sum = pairSum(list);
    return 0;
}
