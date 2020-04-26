#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#define getkey(a) ((int)a)
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
	int operator ==(const mystring & s);
};
int mystring::operator ==(const mystring &s) {
	for(int i = 0; i < HASHTABLE_SIZE; i++) {
		struct hashentry *el = hashtable[i];
		struct hashentry *er = s.hashtable[i];
		if (el == er ) {
			if(el == NULL)
				continue;
		} else if (el == NULL or er == NULL) {
			return 1;
		}
		if(el && er && (el->count != er->count)) {
			printf("char '%c' counts [%d:%d] not same\n", el->c, el->count, er->count);
			return 1;
		}
	}
	return 0;
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
	mystring s1 = mystring("hello world\n");
	mystring s2 = mystring("loelho\n wrdl");
	s1.show();
	if(!(s1 == s2)) {
		cout << "permutation" << endl;
	} else {
		cout << "not permutation" << endl;
	}
	return 0;
}

