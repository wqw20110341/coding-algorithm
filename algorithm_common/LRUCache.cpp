//
// Created by 12582 on 2025/1/7.
//

#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <array>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <random>
#include <sstream>
#include <iomanip>
#include <functional>
#include <chrono>

using namespace std;

class LRUCache {
public:
    explicit LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            cache.splice(cache.begin(), cache, it->second);
            it->second->second = value;
            return;
        }
        if (cache.size() == capacity) {
            int evictedKey = cache.back().first;
            cache.pop_back();
            map.erase(evictedKey);
        }
        cache.emplace_front(key, value);
        map[key] = cache.begin();
    }

private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};


int main() {
    int result = 0;
    LRUCache cache = LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    result = cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    result = cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    result = cache.get(1);       // 返回 -1 (未找到)
    result = cache.get(3);       // 返回  3
    result = cache.get(4);       // 返回  4
    cout << result << endl;
    return 0;
}
