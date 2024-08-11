#include<bits/stdc++.h>
using namespace std;

int prime_num;
long long primes[100];
int order;
priority_queue<int, vector<int>, greater<int>> min_pq;

int main(){
    scanf("%d %d", &prime_num, &order);

    for(int i = 0; i < prime_num; ++i){
        scanf("%d", &primes[i]);
        min_pq.push(primes[i]);
    }

    int count =0 ;
    int head=0;
    long long result;

    while(count != order){
        for(int i = 0; i < prime_num; ++i){
            head = min_pq.top();
            result = primes[i] * min_pq.top();
      
            if(result >= INT32_MAX)
                break;

            min_pq.push(result);

            if(head % primes[i] ==0)
                break;
        }
        min_pq.pop();
        ++count;
    }
    printf("%d\n", head);

    return 0;
}