//g++ --std=c++14 initializerlist.cpp -o initializerlist
#include <iostream>


//template <class T>
template <typename T>
class Fruits {
public:
    explicit Fruits(T a, T b, T c) {
        std::cout << "explicit " << __func__ << " is called \n";
        std::cout << "a=" << a << "; b=" << b << "; c=" << c << std::endl;
    }
    Fruits(T a, T b) {
        std::cout << __func__ << " is called \n";
        std::cout << "a=" << a << "; b=" << b << std::endl;
    }
    Fruits(std::initializer_list<T> l) {
        std::cout << __func__ << " initializer list is called \n";
        for (auto n : l)
            std::cout << n << ' ';
        std::cout << '\n';
    }
};

int main()
{
    Fruits<int> o1(2,3);
    Fruits<float> o2(3,5,6);
    Fruits<double> o3{7,8,9,10};
    Fruits<int>  o4 = {1,2};
    Fruits<int>  o5 = {1,2, 3};
    Fruits<int>  o6 = {1,2, 3, 5, 7, 9};
}
