//
// Created by 12582 on 2024/6/16.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

// 定义一个判断函数，用于 remove_if
bool is_even(int num) {
    return num % 2 == 0;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 使用 remove_if 移除偶数元素
    auto new_end = std::remove_if(nums.begin(), nums.end(), is_even);

    // 真正地从 vector 中删除元素
    nums.erase(new_end, nums.end());

    // 打印结果
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto pointers = new std::vector<std::unique_ptr<int>>();
    pointers->push_back(std::make_unique<int>(1));

    for (auto &pointer:*pointers) {
        if( *pointer % 2 == 0){
            pointer = nullptr;
        }
    }
   pointers->erase(std::remove(pointers->begin(),pointers->end(), nullptr),pointers->end());
    // 打印结果
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;
}