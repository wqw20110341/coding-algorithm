//
// Created by 12582 on 2024/6/16.
//
#include <algorithm>
#include <vector>
#include <iostream>

bool is_even(int num) {
    return num % 2 == 0;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 4, 3, 2, 1};
/**
 * 在C++标准库中，std::stable_partition是一个算法，它对一个范围（通常是一个容器）的元素进行重新排序，
 * 使得满足某个特定条件的元素出现在不满足条件的元素之前，
 * 同时保持相等元素的相对顺序（即稳定的分区）。
 * 在这个例子中，std::stable_partition会将nums中的偶数移动到奇数之前，同时保持相等元素的相对顺序。
 * 因此，输出结果将是所有偶数后跟所有奇数，且相等的元素（如4）的相对顺序保持不变。注意，std::stable_partition返回的迭代器指向第一个不满足条件的元素
 * （即在这个例子中是第一个奇数）。你可以使用这个迭代器来计算满足条件的元素数量，或者进行其他操作。
 */
    auto it = std::stable_partition(nums.begin(), nums.end(), is_even);

    // it现在指向第一个不满足条件的元素（即第一个奇数）

    // 打印分区结果
    for (const auto& num : nums) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    // 如果需要知道满足条件的元素有多少个，可以计算迭代器it和容器末尾之间的距离
    std::cout << "Number of even numbers: " << std::distance(nums.begin(), it) << '\n';

    return 0;
}