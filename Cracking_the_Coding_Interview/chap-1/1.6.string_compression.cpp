/*****************************************************************************
 * String compression
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example the string aabcccccaaa would become
 * a2b1c5a3. If the "compressed" string would not become smaller than the
 * roriginal string would not become smaller than the original string, your
 * method should return the original string. You can assume the string has
 * only uppercase and lowercase letters (a-z).
 * compilation steps:
 * g++ --std=c++11 1.6.string_compression.cpp -o string_compress
 * ***************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string compress(const string & ins, char *outs, int maxlen)
{
    if(outs == NULL) {
        return ins;
    }
    char sc = '\0';
    int  sc_cnt = 0;
    int  j = 0;
    for(string::size_type i=0; i< ins.length() && j < maxlen; i++) {
        if(sc != ins[i]) {
            if(sc_cnt != 0) {
                int cnt = snprintf(&outs[j], maxlen - j, "%d", sc_cnt);
                if(cnt > 0) {
                    j += cnt;
                }
            }
            sc = ins[i];
            outs[j++] = sc;
            sc_cnt = 1;
            continue;
        } else {
            sc_cnt++;
        }
    }
    outs[j] = '\0';
    string out_string = string(outs);
    printf("Instring  len:%-5ld: %s", ins.length(), ins.c_str());
    printf("outstring len:%-5ld: %s", out_string.length(), out_string.c_str());
    if(out_string.length() < ins.length()) {
        return out_string;
    } else {
        return ins;
    }
}

int main()
{
    //string ins = "hello world\n";
    string ins = "heeeeeellllllo                     wwwwwwo rrrrrlllllllllllllllllllllllllddddd\n\n\n\n\n";
    int maxlen = ins.length() * 2;
    char *p = new(nothrow) char[maxlen];
    compress(ins, p, maxlen);
    return 0;
}

