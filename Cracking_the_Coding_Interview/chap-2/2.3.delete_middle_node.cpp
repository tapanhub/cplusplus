/******************************************************************************
 * Delete middle node:
 * Implement an algorithm to delete a node in the middle.(i.e. any node but the
 * first and last node, not necessarily the exact middle) of a singly linked
 * list, given only access to that node.
 * g++ --std=c++11 2.3.delete_middle_node.cpp -o 2.3.delete_middle_node
 *****************************************************************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstring>

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
    void del_middle_node(void);
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

void node::del_middle_node(void) {
    node *step = this;
    node *prev = this;
    node *stepplusplus = this;
    while (step) {
        prev = step;
        step = step->next;
        if(stepplusplus && stepplusplus->next) {
            stepplusplus = stepplusplus->next->next;
        } else { //end of list has reached
            if(step != this && step != stepplusplus) {
                prev->next = step->next;
                cout << "deleting middle node (" << step->get() << ")" << endl;
                delete step;
                return;
            } else {
                cout << "skipping middle node" << endl;
                return;
            }
        }
    }
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
    head->del_middle_node();
    head->show();
    head->freelist();
    delete head;
    head = NULL;
    return 0;
}
