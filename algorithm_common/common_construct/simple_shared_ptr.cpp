//
// Created by 12582 on 2025/1/10.
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

#include <iostream>
#include <atomic>

template <typename T>
class SimpleSharedPtr {
public:
    // 构造函数
    explicit SimpleSharedPtr(T* ptr = nullptr) : ptr_(ptr), refCount_(new std::atomic<int>(1)) {}

    // 复制构造函数
    SimpleSharedPtr(const SimpleSharedPtr& other) : ptr_(other.ptr_), refCount_(other.refCount_) {
        if (ptr_ != nullptr) {
            (*refCount_)++;
        }
    }

    // 移动构造函数
    SimpleSharedPtr(SimpleSharedPtr&& other) noexcept : ptr_(other.ptr_), refCount_(other.refCount_) {
        other.ptr_ = nullptr;
        other.refCount_ = nullptr;
    }

    // 复制赋值运算符
    SimpleSharedPtr& operator=(const SimpleSharedPtr& other) {
        if (this != &other) {
            reset();
            ptr_ = other.ptr_;
            refCount_ = other.refCount_;
            if (ptr_ != nullptr) {
                (*refCount_)++;
            }
        }
        return *this;
    }

    // 移动赋值运算符
    SimpleSharedPtr& operator=(SimpleSharedPtr&& other) noexcept {
        if (this != &other) {
            reset();
            ptr_ = other.ptr_;
            refCount_ = other.refCount_;
            other.ptr_ = nullptr;
            other.refCount_ = nullptr;
        }
        return *this;
    }

    // 解引用操作符
    T& operator*() const {
        return *ptr_;
    }

    // 成员访问操作符
    T* operator->() const {
        return ptr_;
    }

    // 获取引用计数
    int use_count() const {
        return refCount_ ? *refCount_ : 0;
    }

    // 重置指针
    void reset() {
        if (ptr_ && --(*refCount_) == 0) {
            delete ptr_;
            delete refCount_;
        }
        ptr_ = nullptr;
        refCount_ = nullptr;
    }

    // 析构函数
    ~SimpleSharedPtr() {
        reset();
    }

private:
    T* ptr_;
    std::atomic<int>* refCount_;
};

int main() {
    SimpleSharedPtr<int> ptr1(new int(42));
    SimpleSharedPtr<int> ptr2 = ptr1;

    std::cout << "Value: " << *ptr1 << std::endl; // 输出 42
    std::cout << "Use count: " << ptr1.use_count() << std::endl; // 输出 2

    {
        SimpleSharedPtr<int> ptr3 = ptr1;
        std::cout << "Inside block, Use count: " << ptr1.use_count() << std::endl; // 输出 3
    }

    std::cout << "Outside block, Use count: " << ptr1.use_count() << std::endl; // 输出 2

    return 0;
}
