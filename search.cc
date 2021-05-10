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

int bsearch_first(std::vector<int> nums, int length, int value) {
    int start = 0;
    int end = length - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (value > nums[mid]) {
            start = mid + 1;
        } else if (value < nums[mid]) {
            end = mid - 1;
        } else {
            if (mid == 0 || nums[mid - 1] != value) {
                return mid;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int bsearch_first_ge(std::vector<int> nums, int length, int value) {
    int start = 0;
    int end = length - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (nums[mid] < value) {
            start = mid + 1;
        } else {
            if (mid == 0 || nums[mid - 1] < value) {
                return mid;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int bsearch_last(std::vector<int> nums, int length, int value) {
    int start = 0;
    int end = length - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (value > nums[mid]) {
            start = mid + 1;
        } else if (value < nums[mid]) {
            end = mid - 1;
        } else {
            if (mid == length - 1 || nums[mid + 1] != value) {
                return mid;
            } else {
                start = mid + 1;
            }
        }
    }

    return -1;
}

int bsearch_last_le(std::vector<int> nums, int length, int value) {
    int start = 0;
    int end = length - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (nums[mid] > value) {
            end = mid - 1;
        } else {
            if (mid == length - 1 || nums[mid + 1] > value) {
                return mid;
            } else {
                start = mid + 1;
            }
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
    std::cout << "find target: " << target << " result: " << rs << std::endl;
    std::cout << "======================================" << std::endl;

    numbers = {1, 3, 4, 5, 6, 8, 8, 8, 11, 18};
    target = 8;
    expect = 5;
    rs = bsearch_first(numbers, numbers.size(), target);
    assert(expect == rs);
    std::cout << "find target: " << target << " result: " << rs << std::endl;
    std::cout << "======================================" << std::endl;

    target = 8;
    expect = 7;
    rs = bsearch_last(numbers, numbers.size(), target);
    assert(expect == rs);
    std::cout << "find target: " << target << " result: " << rs << std::endl;
    std::cout << "======================================" << std::endl;

    numbers = {3, 4, 6, 7, 10, 11, 18};
    target = 8;
    expect = 4;
    rs = bsearch_first_ge(numbers, numbers.size(), target);
    assert(expect == rs);
    std::cout << "find target: " << target << " result: " << rs << std::endl;
    std::cout << "======================================" << std::endl;

    numbers = {3, 4, 6, 7, 10, 11, 18};
    target = 8;
    expect = 3;
    rs = bsearch_last_le(numbers, numbers.size(), target);
    assert(expect == rs);
    std::cout << "find target: " << target << " result: " << rs << std::endl;
    std::cout << "======================================" << std::endl;

    return 0;
}
