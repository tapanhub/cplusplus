/******************************************************************************
 * Partition:
 * Write code to partition a linked list around a value x, such that all nodes
 * less than x come before all nodes greater than or equal to x. If x is
 * contained within the list, the values of x only need to be after the
 * elements less than x.The partition element x can appear anywhere in the
 * "right partition"; it does not need to appear between the left and right
 * partitions.
 * Example:
 * Input:  3->5->8->5->10->2->1 [ partition = 5]
 * Output: 3->1->2->10->5->5->8
 * g++ --std=c++11 2.4.partition.cpp -o 2.4.partition
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
    void partition(int x);
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

void node::partition(int x) {
    node *n = this;
    node *h = this;
    node *prev = this;
    for ( ; n ; ) {
        cout << "n->data = " << n->get() << endl;
        if(n->get() < x && n != h) {
            cout << "swapping n->data = " << n->get() << endl;
            prev->next = n->next;
            node *nxt = h->next;
            h->next = n;
            n->next = nxt;
            n = prev->next;
            continue;
        }
        prev = n;
        n = n->next;
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
    int v[] = {3, 5, 8, 5, 10, 2, 1};
    for(int j = 0; j < sizeof(v)/sizeof(v[0]); j++) {
        node *n = new class node;
        if(!n) {
            cout << "node allocation failed" << endl;
            //FIXME free all previously allocated memory
            return -1;
        }
        n->set(v[j]);
        if(j==0) {
            head = n;
            continue;
        }
        head->insert(n);
    }
    head->show();
    head->partition(5);
    head->show();
    head->freelist();
    delete head;
    head = NULL;
    return 0;
}
