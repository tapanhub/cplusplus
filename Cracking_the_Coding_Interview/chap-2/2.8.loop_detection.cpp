/******************************************************************************
 * loop_detection:
 * Given a circular linked list, implement an algorithm that returns the node
 * at the beginning of the loop.
 * Example
 * Input: A -> B -> C -> D -> E ->C (the same C as earlier)
 * Output: C
 * g++ --std=c++11 2.8.loop_detection.cpp -o 2.8.loop_detection
 * Solution being tried:
 * floyed algo to detect loop, then slow start both pointers (slow & fast ) one
 * at head and other at inside loop. they will meet at intersection pt
 * proof:
 * Head ---------m--------> loop (n) (k - intersection pt)
 * n = length of cycle
 * m = distance of 1st node of cycle from head
 * k = distance of pt where slow and fast meet
 *
 * distatnce travelled by slow = 2 *(distance travelled by fast)
 * m + n*x + k  = 2(m + n *y + k)
 * x = number of  complete cycles made by fast pointer
 * y = number of complete cycles made by slow pointer
 * m + k = (x-2y)*n
 * which means m+k is a multiple of n
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
    node *detectloop(void);
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

node * node::detectloop(void) {
    node *slow = this;
    node *fast = this;
    int cnt = 0;
    while(slow && fast) {
        slow = slow->next;
        if(fast->next)
            fast = fast->next->next;
        else
            return NULL; //no loop

        cout << "1. slow: " << slow->get() << " fast: " << fast->get() << endl;
        if(slow == fast)
            break;
    }
    if(!slow || !fast) {
        return NULL; //no loop
    }
    node *slow2 = fast;
    slow = this;
    for(;;) {
        cout << "2. slow: " << slow->get() << " slow2: " << slow2->get() << endl;
        if(slow == slow2) {
            cout << "loop start node: " << slow->get() << endl;
            return slow;
        }
        slow = slow->next;
        slow2 = slow2->next;
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


int main()
{
    node *i = NULL;
    node *a = new class node;
    a->set(1);
    node *n = new class node;
    n->set(2);
    a->insert(n);
    n = new class node;
    n->set(3);
    a->insert(n);
    n = new class node;
    n->set(4);
    a->insert(n);
    n = new class node;
    n->set(5);
    a->insert(n);
    n = new class node;
    n->set(6);
    i = n;
    a->insert(n);
    n = new class node;
    n->set(7);
    a->insert(n);
    n = new class node;
    n->set(8);
    a->insert(n);
    n = new class node;
    n->set(9);
    a->insert(n);
    n = new class node;
    n->set(10);
    a->insert(n);
    n = new class node;
    n->set(11);
    a->insert(n);
    n->next = i;

    a->detectloop();

    //a->freelist();
    //b->freelist();
    return 0;
}
