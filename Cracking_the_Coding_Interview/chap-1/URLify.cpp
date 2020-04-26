#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class urlify {
    char *baseptr = NULL;
    int len = 0;
public:
    urlify(char *str, int size);
    void show() {
        if(baseptr)
            printf("%s\n", baseptr);
    }
};

urlify::urlify(char *str, int size) {
    baseptr = str;
    len = size;
    char *s = new char[size];
    char *cp = s;
    if(!s) {
        cout << "unable to allocate memory " << size << endl;
        return;
    }
    for(int i=0,j=0; i< size && j < size; i++, j++) {
        if(baseptr[i] == ' ') {
            *cp++ = '%';
            *cp++ = '2';
            *cp++ = '0';
            j += 2;
        } else {
            *cp++ = baseptr[i];
        }
    }
    memcpy(baseptr, s, size);
    delete [] s;
}

int main()
{
    char mystring[15] = "hello world\n";
    class urlify u = urlify(mystring, sizeof(mystring));
    u.show();
    return 0;
}
