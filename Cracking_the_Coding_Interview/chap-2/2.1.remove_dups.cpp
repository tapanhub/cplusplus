/*****************************************************************************
 * Remove dups:
 * write code to remove duplicates from an unsorted linked list.
 * Follow up
 * How would ou solve this problem if a temporary buffer is not allowed ?
 * g++ --std=c++11 2.1.remove_dups.cpp -o remove_dups
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
    int data;
    node *next;
public:
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
    int freedups(void);
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

struct hashentry {
    class node *n;
    struct hashentry *next;
};

class myset {
    struct hashentry *hashtable[MYHASHSIZE]={NULL};
public:
    int addtohashtable(class node *n);
};

int node::freedups(void) {
    class myset s;
    node *element = this;
    node *prev = NULL;
    node *tmp = NULL;
    int delete_node = false;
    while(element) {
        if(s.addtohashtable(element) == 1) {
            if(prev) {
                prev->next = element->next;
                tmp = element;
                delete_node = true;
            }
        } else {
            prev = element;
        }
        element = element->next;
        if(delete_node == true && tmp) {
            delete tmp;
            tmp = NULL;
            delete_node = false;
        }
    }
    return 0;
}
int myset::addtohashtable(class node *n) {
    int key = getkey(n);
    struct hashentry *hentry = (hashtable[key]);
    struct hashentry *e = new (struct hashentry);
    if(!e) {
        cout << "Unable to allocate memory" << endl;
        return 0;
    }
    memset(e, 0, sizeof(struct hashentry));
    e->n = n;
    if(hentry) {
        hashentry  *nhead = hentry;
        struct hashentry *he = nhead;
        for(;he; he = he->next) {
            cout << __func__ << "he->n->get() = " << he->n->get() << " and n->get() = " << n->get() << endl;
            if(he->n->get() == n->get()) {
                cout << "deleting duplicate entry " << n->get() << endl;
                delete e;
                return 1;
            }
        }
        he->next = e;
    } else {
        hashtable[key] = e;
    }
    return 0;
}



node *head = NULL;
int main()
{
    head = new class node;
    if(head) {
        head->set(0);
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j < 10; j++) {
                node *n = new class node;
                if(n) {
                    n->set(j);
                    head->insert(n);
                }
            }
        }
    }
    head->show();
    head->freedups();
    head->show();
    head->freelist();
    delete head;
    head = NULL;
    return 0;
}
