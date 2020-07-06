/************************************************************
 * Three in One: Describe how you could use a single array to
 * implement three stacks.
 * g++ -std=c++14 3.1.threeinone.cpp -o threeinone
 ************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;


template <class T>

class mystack {
    private:
        T *arr;
        int top;
        int size;
    public:
        T peek(void);
        bool push(T entry);
        T pop(void);
        bool isempty(void);
        mystack(T *array, int size);

};

template <class T>
mystack<T>::mystack(T *array, int size)
{
    arr = array;
    top = -1;
    size = size;
}

template <class T>
T mystack<T>::peek(void)
{
    if(top >=0 && top < size)
        return arr[top];
}

template <class T>
T mystack<T>::pop(void)
{
    if(top >=0 && top < size)
        return arr[top--];
}
template <class T>
bool mystack<T>::isempty(void)
{
    if(top < 0)
        return true;
    else
        return false;
}
template <class T>
bool mystack<T>::push(T entry)
{
    if(top >= -1 && top < size-1) {
        arr[++top] = entry;
        return true;
    } else {
        return false;
    }
}


int main()
{
    int int_arr[9];
    string str_array[3];
    mystack<int> int_stack1(int_arr, 3);
    mystack<int> int_stack2(&int_arr[3], 3);
    mystack<int> int_stack3(&int_arr[6], 3);
    mystack<string> str_stack(str_array, 3);
    int_stack2.push(67);
    str_stack.push("Hello");
    str_stack.push("Codezclub");
    cout << int_stack2.pop() << endl;
    cout << str_stack.pop() << endl;
    cout << str_stack.pop() << endl;
    return 0;
}

