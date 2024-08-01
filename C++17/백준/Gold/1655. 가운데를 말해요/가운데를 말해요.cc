// 2 heaps Algorithm ? 

#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> maxheap;			// 입력된 숫자 중 작은 절반 저장하는 최대 힙 
	priority_queue<int> minheap;			// 입력된 숫자 중 큰 절반 저장하는 최소 힙 
	
	// priority_queue 자료형이므로 힙에 원소들이 들어오면 
	// 자동적으로 정렬되어 top 원소가 정리된다! 
	
    int N;
    scanf("%d", &N);

    for(int i = 0, num; i < N; i++){
        scanf("%d", &num);
        if(maxheap.size() > minheap.size()) minheap.push(-num);
        else maxheap.push(num);
        
        if(maxheap.size() > 0 && minheap.size() > 0){
            if(maxheap.top() > -minheap.top()){
                int maxtop = maxheap.top();
                int mintop = -minheap.top();
                maxheap.pop();
                minheap.pop();
                maxheap.push(mintop);
                minheap.push(-maxtop);
            }
        }
        printf("%d\n", maxheap.top());
    }
    return 0;
}
