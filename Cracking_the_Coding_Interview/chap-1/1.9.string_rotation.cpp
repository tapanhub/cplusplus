/*****************************************************************************
 * string rotation:
 * Assume you have a method isSubsring which checks if one word is a substring
 * of another. Given two strings, S1 and S2, write code to check if S2 is a
 * rotation of S1 using only one call to isSubstring(e.g. "waterbottle" is
 * a rotation of "erbottlewat").
 * steps to compile:
 * g++ --std=c++11 1.9.string_rotation.cpp -o string_rotation
 ****************************************************************************/
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool isSubstring(const string & s1, const string & s2)
{
    int s1l = s1.length();
    int s2l = s2.length();
    int i = 0, j = 0;
    for(i=0; i < s1l - s2l; i++) {
        for(j=0; j < s2l; j++) {
            if(s1[i+j] != s2[j]) {
                break;
            }
        }
        if(j == s2l) {
            return true;
        }
    }
    return false;
}

bool check_rotation(const string & s1, const string & s2)
{
    string s11 = s1 + s1;
    bool ret = isSubstring(s11, s2);
    return ret;
}

int main()
{
    string s1 = "erbottlewat";
    string s2 = "waterbottle";
    if(check_rotation(s1, s2)) {
        cout << s2 << " is a rotation of " << s1 << endl;
    } else {
        cout << s2 << " is not a rotation of " << s1 << endl;
    }
    s1 = "tapan";
    s2 = "antap";
    if(check_rotation(s1, s2)) {
        cout << s2 << " is a rotation of " << s1 << endl;
    } else {
        cout << s2 << " is not a rotation of " << s1 << endl;
    }

    s1 = "abcde";
    s2 = "deabd";
    if(check_rotation(s1, s2)) {
        cout << s2 << " is a rotation of " << s1 << endl;
    } else {
        cout << s2 << " is not a rotation of " << s1 << endl;
    }

    return 0;
}
