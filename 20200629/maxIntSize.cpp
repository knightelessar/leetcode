#include <iostream>
#include <limits>

int main()
{
    std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "std::numeric_limits<int>::max() = " << std::numeric_limits<int>::max() << std::endl;
    size_t x{1};
    std::cout << "2^(4 * 8 - 1) - 1 = 1 << 31 - 1 = " << ((x << 31) - 1) << std::endl;
}