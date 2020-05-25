/*****************************************************************************
 * Remove dups:
 * Implement an algorithm to find the kth to last elemtn of a singly linked
 * list.
 * g++ --std=c++11 2.2.return_kth2last.cpp -o return_kth2last
 ****************************************************************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstring>

#define MYHASHSIZE  100
#define getkey(a) (a->get() % MYHASHSIZE)

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
    int getkth2lastbyrec(node *, int k);
    node  *getkth2lastbyiter(int k);
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

int node::getkth2lastbyrec(node *n, int k) {
    int cnt = 0;
    if(n) {
        cnt = node::getkth2lastbyrec(n->next, k) + 1;
        if (cnt == k) {
            cout << k << "th last element to last = " << n->get() << endl;
        }
        return cnt;
    } else {
        return 0;
    }
}

node *node::getkth2lastbyiter(int k) {
    node *head = this; //head
    node *kthnode = head;
    node *curr = head;
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        if(kthnode->next) {
            kthnode = kthnode->next;
        } else {
            cout << k << "th last element to last could not be found" << endl;
            return NULL; //not found
        }

    }
    for( ;curr; curr = curr->next, kthnode = kthnode->next) {
        if(kthnode == NULL) {
            cout << k << "th last element to last = " << curr->get() << endl;
            return curr;
        }
    }
    cout << k << "th last element to last could not be found" << endl;
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


node *head = NULL;
int main()
{
    head = new class node;
    if(head) {
        head->set(0);
        for(int j = 1; j < 15; j++) {
            node *n = new class node;
            if(n) {
                n->set(j);
                head->insert(n);
            }
        }
    }
    head->show();
    head->getkth2lastbyrec(head, 3);
    head->getkth2lastbyrec(head, 5);
    head->getkth2lastbyrec(head, 7);
    head->getkth2lastbyrec(head, 20);
    head->getkth2lastbyiter(3);
    head->getkth2lastbyiter(5);
    head->getkth2lastbyiter(7);
    head->getkth2lastbyiter(20);
    head->freelist();
    delete head;
    head = NULL;
    return 0;
}
