// Fenwick Tree

#include <bits/stdc++.h>
using namespace std;

long long getSum(vector<long long> &tree, int i){							// Fenwick Tree에서 누적합 계산 
	long long ans = 0;														// ans 0으로 초기화 
	while (i > 0){
		ans += tree[i];														// Tree의 i번째 원소를 더하고 
		i -= (i & -i);														// (2진수 기준으로) 인덱스에서 가장 오른쪽 1을 빼가면
	}																		// 처음부터 i번째 원소까지의 누적합이 계산된다 
	return ans;
}

void update(vector<long long> &tree, int i, long long diff){				// Fenwick Tree에서 원소 업데이트 
	while (i < tree.size()){
		tree[i] += diff;													// 원소를 diff만큼 변화 
		i += (i & -i);														// 바뀐 원소에 영향을 받는 Tree의 모든 항들도 diff만큼 변화 
	}
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<long long> A(n + 1);												// 실제 배열을 저장하는 벡터 A 
	vector<long long> tree(n + 1);											// Fenwick Tree를 저장하는 벡터 tree 
	for (int i = 1; i <= n; i++){
		scanf("%lld", &A[i]);												// 입력받는 값을 바로 벡터 A에 저장 
		update(tree, i, A[i]);												// Fenwick Tree의 원소를 벡터 A에 따라 업데이트 
	}
	m += k;
	while (m--){															// while문 내부 실행 후 m 1씩 감소 
		int a;
		scanf("%d", &a);
		if (a == 1){														// a가 1이라면 
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			long long diff = c - A[b];
			A[b] = c;														// b번째 수를 c로 바꾸고, 
			update(tree, b, diff);											// 그로 인해 생기는 합의 변화(diff)만큼 업데이트 
		} else{																// a가2라면 
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", getSum(tree, c) - getSum(tree, b - 1));		// b번째 수부터 c번째 수까지의 합 계산(부분합 - 부분합) 
		}
	}
	return 0;
}
