#include <bits/stdc++.h>
using namespace std;

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    const char *strfind = strstr(str1.c_str(), str2.c_str());

    if (strfind != NULL) printf("1");
    else printf("0");

    return 0;
}
