#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 10

int main(){
    char S[MAXN], t;											// t: 임시로 문자를 저장하기 위한 변수 
    int K;
    string str, ans = "0";										// str: 입력된 숫자를 문자열로 저장 
    queue<string> q;											// BFS를 위해 문자열을 저장할 큐 

    scanf(" %s %d", S, &K);
    str = S;
    
    q.push(str);												// 초기 입력된 숫자를 큐에 삽입 
    
    for(int i = 0; i < K; i++){									// 최대 K번의 교환
        set<string> s;											// 한 번 생성된 숫자를 중복해서 큐에 넣지 않기 위해 집합을 사용
        int qSize = q.size();									// 현재 큐의 크기를 저장
        
        for(int j = 0; j < qSize; j++){
            str = q.front();									// 큐의 맨 앞에 있는 숫자를 꺼냄. 
            q.pop();											// 큐의 맨 앞에 있는 숫자를 제거
            
            if(s.count(str)==1) continue;						// 이미 한 번 생성된 숫자는 건너뜀 
            s.insert(str);										// 새로 생성된 숫자를 집합에 추가
            
            for(int k = 0; k < str.size() - 1; k++){			// 각 자릿수에 대해 순차적으로 접근
                for(int l = k + 1; l < str.size(); l++){		// 현재 선택한 자릿수 이후의 자릿수와 교환을 시도
                    if(k == 0 && str[l] == '0') continue;		// 첫 번째 자리의 숫자를 '0'으로 만드는 교환은 건너뜀. 

                    t = str[k];									// 교환
                    str[k] = str[l];
                    str[l] = t;
                    
                    q.push(str);								// 교환으로 새로 만들어진 문자열을 큐에 삽입 

                    t = str[k];									// 다음 루프에서 다시 교환을 하기 위하여 원상 복구해주어야 함. 
                    str[k] = str[l];
                    str[l] = t;
                }
            }
        }
    }
    
    while(!q.empty()){											// 큐가 빌 때까지 반복
        ans = max(ans, q.front());								// 큐에 있는 모든 숫자 중에서 가장 큰 값을 ans에 저장
        q.pop();												// 큐에서 숫자를 하나씩 제거
    }
    
    if(ans[0]=='0') printf("-1");
    else printf("%s", ans.c_str());    

    return 0;
}
