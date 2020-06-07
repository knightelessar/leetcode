#include <iostream>
#include <unordered_map>
#include <utility>

struct mySol {
    std::unordered_map<std::pair<int, int>, int> myWay;
    int run() {
        return 0;
    };
};

int main() {
    int i = mySol().run();
    return i;
}