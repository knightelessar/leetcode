#include "ContiguousArray.hpp"
#include <vector>
#include <cassert>
using std::vector;

int Solution::findMaxLength(vector<int>& nums) {
    int maxLen {0};
    auto nNums = nums.size();
    int arr[2 * nNums + 1];
    int count {0};
    for (int i = 0; i < 2 * nNums + 1; ++i) {
        arr[i] = -2;
    }
    arr[nNums] = -1;
    
    auto it = nums.begin();
    int i {0};
    while (it != nums.end()) {
        count = count + (*it == 0 ? -1 : 1);
        if (arr[count + nNums] >= -1) {
            int newLen = i - arr[count + nNums];
            maxLen = newLen > maxLen ? newLen : maxLen;
        }
        else {
            arr[count + nNums] = i;
        }
        ++i;
        ++it;
    }

    return maxLen;
}