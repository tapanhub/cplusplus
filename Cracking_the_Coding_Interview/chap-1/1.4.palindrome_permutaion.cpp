/* Palindrome Permutaion: Given a string, write a function to check if it is
 * a permutation of a palindrome. A palindrome is a word or phrase that is
 * the same forwards and backwards. A permutation is a rearrangement of
 * letters. The palindrome does not need to be limited to just dictionary
 * words.
 * Example
 * Input: Tact Coa
 * Output: True (Permutaions: "taco cat", "atco cta", etc.)
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#define getkey(a) ((a >= 'A' && a <= 'Z')?(a + ('a' - 'A')):(int)a)
#define HASHTABLE_SIZE 256
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
    struct hashentry *hashtable[HASHTABLE_SIZE]={NULL};
    vector<char> unique;
    int ucnt = 0;
    bool palindrom = true;
    bool permutation = false;
public:
    mystring() {
        ucnt = 0;
    }
    int addtohashtable(char c);
    mystring(const string & str) {
        basestr = str;
        for (auto & c: basestr) {
            int num = addtohashtable(c);
            if(num == 1) {
                ucnt++;
            }
        }
        printf("number of unique characters = %d\n", ucnt);
    }
    void show(void);
    bool check_palindrom(void);
    int operator ==(const mystring & s);
    friend std::ostream & operator <<(std::ostream &os, mystring const &m) {
        return os << m.basestr;
    }
};

bool mystring::check_palindrom(void) {
    int oddelements = 0;
    for(int i = 0; i < HASHTABLE_SIZE; i++) {
        struct hashentry *el = hashtable[i];
        if(el == NULL) {
            continue;
        } else {
            if(el->count % 2  != 0) {
                if(el->c != ' ')
                    oddelements++;
                if(oddelements > 1) {
                    printf("false:%-10c(ascii:%d): %d\n", el->c, el->c, el->count);
                    palindrom = false;
                }
            } else if ( el->count % 2  != 0) {
                printf("false:%-10c(ascii:%d): %d\n", el->c, el->c, el->count);
                palindrom = false;
            }
            //printf("%-10c(ascii:%d): %d\n", el->c, el->c, el->count);

        }
    }
    return palindrom;
}
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
    vector <mystring> svec = {
        mystring("Tact Coa"),
        mystring("12321"),
        mystring("21231"),
        mystring("Geeksforgeeks"),
        mystring("Geeksfgeeks")
    };
    //s.show();
    for(auto s : svec) {
        if(s.check_palindrom()) {
            cout << s << " - permutation is palindrom" << endl;
        } else {
            cout << s << " - permutaion is not palindrom" << endl;
        }
    }
    return 0;
}

