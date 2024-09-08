#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

vector <int> prime;
bool visited[40000];
map<int, int> a, b;

void make(int num, char ch) {
    if (ch == 'a') {
        for (auto o : prime) {
            if (num % o == 0) {
                a[o]++;
                make(num / o, 'a');
                return;
            }
        }
        if (num != 1)                                   //num이 약수가 없으면
            a[num]++;
    }
    else {
        for (auto o : prime) {
            if (num % o == 0) {
                b[o]++;
                make(num / o, 'b');
                return;
            }
        }
        if (num != 1)                                   //num이 약수가 없으면
            b[num]++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    long long answer = 1;
    bool isBigger=false;
    for (int i = 2; i < 40000; i++) {                   //2부터 40000까지 소수 저장
        if (visited[i])
            continue;
        prime.push_back(i);
        for (int j = 2 * i; j < 40000; j += i) {
            visited[j] = true;
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) {                       //주어진 a배열의 수들을 소인수분해하여 map a에 저장
        int num;
        cin >> num;
        make(num, 'a');
    }
    cin >> m;
    for (int i = 0; i < m; i++) {                       //주어진 b배열의 수들을 소인수분해하여 map b에 저장
        int num;
        cin >> num;
        make(num, 'b');
    }

    for (auto o : a) {
        if (!b[o.first])                                //map a엔 있지만, map b에 없으면 pass
            continue;
        int cnt = min(o.second, b[o.first]);            //map a와 map b 의 소인수가 같을 때, 해당 소인수의 count가 적은 것을 가져온다.
        while (cnt--) {                                 //pow(o.first,cnt)하면 값이 다르게 나와서 cnt수만큼 곱해주기
            answer *= o.first; 
            if (answer >= INF) {                        //INF보다 크거나 같으면 INF로 나누어주기
                answer = answer % INF;
                isBigger = true;
            }
        }
    }
    if (isBigger)                                       //INF보다 크지만 나머지 값이 앞부분이 0이 나올 수 있으니 9자리수를 맞춰줘야함
        printf("%09lld", answer);
    else
        cout << answer;

    return 0;
}