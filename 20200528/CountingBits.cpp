#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num);
        bits[0] = 0;
        for (int i, j = 0; i < num; ++i) {
            if (pow(2, j) <= i < pow(2, j + 1)) {
                bits[i] = bits[i - pow(2, j)] + ((i/pow(2, ))%2 == 0) ? 
            }
            else {
                bits[i] = bits[old] + 
            }
        }
    }
};

int main() {
    auto mySol = new Solution();
    auto bits = mySol.countBits(5);
    cout << bits << endl;
    return 0;
}