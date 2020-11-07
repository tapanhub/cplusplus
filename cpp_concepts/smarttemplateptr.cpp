//g++ --std=c++14 smarttemplateptr.cpp -o smarttemplateptr
#include <iostream>
using namespace std;

template <class T>
class SmartPtr {
    T *ptr;
public:
    explicit SmartPtr(T *p = NULL) {
        cout << __func__ << " is called" << endl;
        ptr = p;
    }
    ~SmartPtr() {
        cout << __func__ << " is called" << endl;
        delete (ptr);
    }
    T& operator*() {
        cout << __func__ << " is called" << endl;
        return *ptr;
    }
    T* operator->() {
        cout << __func__ << " is called" << endl;
        return ptr;
    }

};

int main(int argc, char **argv)
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr << endl;
    return 0;
}
