/******************************************************************************
 * There are 3 types of edits that can be performed on the strings:
 * 1. insert a character
 * 2. remove a character
 * 3. replace a character
 * Given two strings, write a function to check if they are one edit
 * (or zero edits) away.
 * Example
 * pale, ple    -> true
 * pales, pale  -> true
 * pale, bale   -> true
 * pale, bake   -> false
 * steps to compile:
 *   g++ --std=c++11 1.5.one_away.cpp -o one_away
 *****************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool check_oneaway(const string & s1,const string & s2)
{
    int away_cnt = 0;
    for(string::size_type i=0,j=0; i < s2.length(); i++) {
        if(j < s1.length()) {
            //printf("s1[%ld]=%c, s2[%ld]=%c\n", j, s1[j], i, s2[i]);
            if(s2[i] == s1[j]) {
                j++;
                continue;
            } else {
                //printf("s1[%ld]=%c, s2[%ld]=%c\n", j, s1[j], i, s2[i]);
                away_cnt++;
                if(s2[i] == s1[j+1]) {
                    j+=2;
                    continue;
                }
                if (s2[i+1] == s1[j+1]) {
                    j+=1;
                    continue;
                }
                if(s2[i+1] == s1[j]) {
                    i++;
                }
            }
        } else {
            away_cnt ++;
        }
    }

    if( away_cnt >= 2) {
        cout << s1 << " vs " << s2 << ": " << "false "
            << "away cnt: " << away_cnt << endl;
        return false;
    } else {
        cout << s1 << " vs " << s2 << ": " << "true "
            << "away cnt: " << away_cnt << endl;
        return true;
    }
}
int main()
{
    string s1="pale", s2="ple";
    bool result = check_oneaway(s1, s2);
    check_oneaway("pale", "ple");
    check_oneaway("pales", "pale");
    check_oneaway("pale", "bake");
    check_oneaway("pale", "bake");
    check_oneaway("aaae", "aabe");
    check_oneaway("adae", "aade");
    return 0;
}
