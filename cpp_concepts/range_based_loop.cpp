//g++ --std=c++14 range_based_loop.cpp -o range_based_loop

#include <iostream>
#include <vector>

template <typename T>
void printEle(T& v)
{
    std::cout << "-------begin------\n";
    for(auto& t: v) {
        std::cout << t << std::endl;
    }
    for(auto _pos=v.begin(); _pos != v.end(); _pos++) {
        std::cout <<  *_pos << std::endl;
    }

    std::cout << "-------end------\n";
}

int main()
{
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto& a: v) {
        a *=2;
    }
    for (auto a: v) {
        std::cout << a << std::endl;
        a += 2; // private copy , no change in actual vector
    }
    std::cout << "-------\n";
    for (auto a: v) {
        std::cout << a << std::endl;
    }
    printEle(v);
}
