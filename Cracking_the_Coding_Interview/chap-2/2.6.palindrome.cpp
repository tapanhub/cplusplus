/******************************************************************************
 * palindrome:
 * Implement a function to check whether a linked list is palindrome
 * g++ --std=c++11 2.6.palindrome.cpp -o 2.6.palindrome
 *****************************************************************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

class node {
public:
    int data;
    node *next;
    int pflag;
    int palindrome_called;
    node(void) {
        data = 0xdeaddead;
        next = NULL;
    }
    node(int data) {
        data = data;
        next = NULL;
    }
    ~node() {
        data = 0xdeaddead;
        next = NULL;
    }
    void set(int d) {
        data = d;
    }

    node *insert(node *n);
    int show(void);
    int freelist(void);
    int get(void) {
        return data;
    }
    node * palindrome(node *);
    int check_palindrome(void);
};
node *node::insert(node *n) {
    node *element = this;
    while(element->next) {
        element = element->next;
    }
    element->next = n;
    return element;
}
int node::show(void) {
    node *element = this; //head
    int cnt = 0;
    while(element) {
        cout << setw(10) << element->data << endl;
        element = element->next;
        cnt++;
    }
    cout << setw(10) << "NULL" << endl;
    cout << "Total number of nodes = "<< cnt << endl;
    return cnt;
}

node * node::palindrome(node *n) {

    if(palindrome_called != 1) {
        palindrome_called = 1;
    }
    if(n){
        node *nr = palindrome(n->next);
        if(nr && n) {
            if(n->get() != nr->get()) {
                pflag = -1;
            }
            cout << "arg: " << n->get() << ", ret: " << nr->get() <<endl;
        }
        return nr->next;
    } else {
        return this;
    }
}

int node::check_palindrome(void) {
    switch(pflag) {
        case -1:
            cout << "not palindrome" << endl;
            break;
        case 0:
            if(palindrome_called != 1)
                cout << "please call palindrome method" << endl;
            else {
                cout << "palindrome" << endl;
            }
            break;
    }
    return pflag;
}
int node::freelist(void) {
    node *element = this; //head
    int cnt = 0;
    cout << "########################################################" << endl;
    cout << "        Deleting whole list before exit" << endl;
    cout << "########################################################" << endl;
    while(element) {
        cout << "deleting "<< setw(5) << element->data << endl;
        node *freenode = element;
        element = element->next;
        delete freenode;
        cnt++;
    }
    cout << setw(10) << "NULL" << endl;
    cout << "Total number of nodes deleted = "<< cnt << endl;
    return cnt;
}


int main()
{
    node *a = new class node;
    a->set(7);
    node *n = new class node;
    n->set(1);
    a->insert(n);
    n = new class node;
    n->set(7);
    a->insert(n);
    node *b = new class node;
    b->set(5);
    n = new class node;
    n->set(9);
    b->insert(n);
    n = new class node;
    n->set(2);
    b->insert(n);

    a->show();
    a->palindrome(a);
    a->check_palindrome();
    b->show();
    b->palindrome(b);
    b->check_palindrome();

    a->freelist();
    b->freelist();
    return 0;
}
