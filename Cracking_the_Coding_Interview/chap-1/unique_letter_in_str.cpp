#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#define getkey(a) ((int)a)
using namespace std;

struct mylist {
    struct mylist *next;
    char c;
};

struct hashentry {
    struct mylist *node;
    int count;
    char c;
};

class mystring {
    string basestr;
    struct hashentry *hashtable[256]={NULL};
    vector<char> unique;
    int ucnt;
public:
    mystring() {
        ucnt = 0;
    }
    int addtohashtable(char c);
    mystring(const string & str) {
        basestr = str;
        printf("initializing object, unquevect size = %ld\n", unique.size());
        for (auto & c: basestr) {
            int num = addtohashtable(c);
            if(num == 1) {
                ucnt++;
            }
        }
        printf("number of unique characters = %d\n", ucnt);
    }
    void show(void);
};

int mystring::addtohashtable(char c) {
    int key = getkey(c);
    int idx = key % (sizeof(hashtable)/sizeof(hashtable[0]));
    struct hashentry *hentry = (hashtable[idx]);
    struct mylist *node = new (struct mylist);
    if(!node) {
        cout << "Unable to allocate memory" << endl;
        return 0;
    }
    memset(node, 0, sizeof(struct mylist));
    node->c = c;
    if(hentry) {
        struct mylist *nhead = (hashtable[idx]->node);
        struct mylist *n = nhead;
        for(;n->next; n = n->next);
        n->next = node;
    } else {
        hentry = new (struct hashentry);
        if(!hentry) {
            cout << "Unable to allocate memory" << endl;
            return 0;
        }

        memset(hentry, 0, sizeof(struct hashentry));
        hentry->node = node;
        hentry->c = c;
        hashtable[idx] = hentry;
    }
    hentry->count++;
    return hentry->count;
}
void mystring::show(void) {
    for(auto & he: hashtable) {
        if(he) {
            printf("%-10c(ascii:%d): %d\n", he->c, he->c, he->count);
        }
    }
}


int main()
{
    mystring s = mystring("hello world\n");
    s.show();
    return 0;
}

