/******************************************************************************
 * Sum list:
 * You have two numbers represented by a linked list, where each node contains
 * a single digit. The digits are stored in reverse order, such that the 1's
 * digit is at the head of the list. Write a function that adds the two numbers
 * and returns the sum as a linked list.
 * Example:
 * Input: (7->1->6) + (5->9->2) that is 617 + 295
 * Output: 2->1->9. that is , 912
 * Follow up:
 * Suppose the digits are stored in forward order. Repeat the above problem
 * Example:
 * Input:(6->1->7) + (2->9->5), i.e. 617 + 295
 * Output: 9->1->2. That is 912
 * g++ --std=c++11 2.5.sum_list.cpp -o 2.5.sum_list
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
    node &operator +(node &obj);
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

node &node::operator +(node  &obj) {
    int a = 0, b = 0, c = 0;
    node *n = this;
    node *res = NULL;
    cout << __func__ << " is called" << endl;
    for(int i = 0;n;n = n->next, i++) {
        a += n->get() * pow(10,i);
    }
    n = &obj;
    for(int i = 0;n;n = n->next, i++) {
        b += n->get() * pow(10,i);
    }
    c = a + b;
    for(int i = 0;c; c /= 10, i++) {
        node *n = new class node;
        n->set(c%10);
        if(i == 0) {
            res = n;
        } else {
            res->insert(n);
            res->show();
        }
    }
    if(res)
        return *res;
    else
        return obj;
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
    n->set(6);
    a->insert(n);
    node *b = new class node;
    b->set(5);
    n = new class node;
    n->set(9);
    b->insert(n);
    n = new class node;
    n->set(2);
    b->insert(n);
    node c = *a + *b;

    a->show();
    b->show();
    c.show();

    a->freelist();
    b->freelist();
    return 0;
}
