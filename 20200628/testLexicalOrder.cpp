#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void myp(const T& con)
{
    for (const auto &x: con)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> city{"JFK","ATL","SFO"};
    myp(city);
    std::sort(begin(city), end(city));
    myp(city);
}