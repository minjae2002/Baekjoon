#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int N, M, cnt = 1;
int trie[MAX][27];

void add(string& text){
    int now = 0;
    for (auto ch : text){
        int idx = ch - 'a';
        if (trie[now][idx] == 0){
            trie[now][idx] = cnt++;
        }
        now = trie[now][idx];
    }
}

bool isPrefix(string& text){
    int now = 0;
    for (auto ch : text){
        int idx = ch - 'a';
        if (trie[now][idx] == 0){
            return false;
        }
        now = trie[now][idx];
    }
    return true;
}

int main(){
    int cnt = 0;
    scanf("%d %d", &N, &M);
    while (N--){
        string text;
        cin >> text;
        add(text);
    }
    while (M--){
        string pre;
        cin >> pre;
        if(isPrefix(pre)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}