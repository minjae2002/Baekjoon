#include <bits/stdc++.h>
using namespace std;

map<string, double> tree;


int main(){
	int count = 0;
	string treename;
	while (getline(cin, treename) && !treename.empty()){
		if(!tree[treename]) tree[treename] = 1;
		else tree[treename]++;
		count++;
	}
	
	for (auto iter : tree){
		cout.precision(4);
		cout << fixed;
		cout << iter.first << " " << (iter.second / count) * 100 << "\n";
	}
	
	return 0;
}