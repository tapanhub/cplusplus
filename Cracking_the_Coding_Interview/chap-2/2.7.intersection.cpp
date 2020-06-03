/******************************************************************************
 * intersection:
 * Given two (singly) linked lists, determine if the two lists intersect.
 * Retuurn the intersectiing node. Note that the intersection is defined based
 * on reference, not value. That is if the kth node of the first linked list is
 * the exact same node (by reference) as the jth node of the second linked list
 * then they are intersecting.
 * g++ --std=c++11 2.7.intersection.cpp -o 2.7.intersection
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
    int seen;
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
    node *get_intersection(node *);
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

node * node::get_intersection(node *n) {
    node *element = this; //head
    int cnt = 0;
    while(element) {
        element->seen = 1;
        element = element->next;
    }
    while(n) {
        if(n->seen == 1 ) {
            cout << "intersection node = "<< n->get() << endl;
            return n;
        }
        n = n->next;
    }
    cout << "intersection node not found"<< endl;
    return NULL;
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
    a->insert(n);
    n = new class node;
    n->set(2);
    b->insert(n);

    a->show();
    b->show();
    a->get_intersection(b);

    //a->freelist();
    //b->freelist();
    return 0;
}
