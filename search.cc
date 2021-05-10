//
// Created by 王传德 on 2021/5/9.
//

#include <iostream>
#include <vector>
#include <cassert>

int bsearch(std::vector<int> nums, int length, int value) {
    int start = 0;
    int end = length - 1;

    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (value > nums[mid]) {
            start = mid + 1;
        } else if (value < nums[mid]) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    std::cout << "Hi, start to search" << std::endl;
    std::vector<int> numbers = {1, 3, 4, 5, 7, 9, 10, 12};
    int target = 10;
    int expect = 6;
    int rs = bsearch(numbers, numbers.size(), target);
    assert(expect == rs);
    std::cout << "find target: " << target << " result: " << rs;
    return 0;
}
