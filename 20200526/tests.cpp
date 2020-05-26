#include "ContiguousArray.hpp"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    Solution mySol;
    vector<int> array{1,0,0};
    auto maxLength = mySol.findMaxLength(array);
    cout << maxLength << endl;
    return 0;
}