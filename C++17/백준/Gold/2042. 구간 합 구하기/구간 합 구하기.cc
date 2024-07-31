// Fenwick Tree

#include <bits/stdc++.h>
using namespace std;

long long getSum(vector<long long> &tree, int i){
	long long ans = 0;
	while (i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<long long> &tree, int i, long long diff){
	while (i < tree.size()){
		tree[i] += diff;
		i += (i & -i);
	}
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<long long> a(n + 1);
	vector<long long> tree(n + 1);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		update(tree, i, a[i]);
	}
	m += k;
	while (m--){
		int t1;
		scanf("%d", &t1);
		if (t1 == 1){
			int t2;
			long long t3;
			scanf("%d %lld", &t2, &t3);
			long long diff = t3 - a[t2];
			a[t2] = t3;
			update(tree, t2, diff);
		} else{
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", getSum(tree, c) - getSum(tree, b - 1));
		}
	}
	return 0;
}