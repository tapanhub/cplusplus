#include <iostream>
using namespace std;

class SmartPtr {
    int *ptr;
public:
    explicit SmartPtr(int *p = NULL) {
        cout << __func__ << " is called" << endl;
        ptr = p;
    }
    ~SmartPtr() {
        cout << __func__ << " is called" << endl;
        delete (ptr);
    }
    int& operator*() {
        cout << __func__ << " is called" << endl;
        return *ptr;
    }
};

int main(int argc, char **argv)
{
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr << endl;
    return 0;
}
