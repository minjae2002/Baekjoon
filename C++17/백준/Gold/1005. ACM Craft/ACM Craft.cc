#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001
typedef pair<int, int> edge;

int T, N, K, w;
int btime[MAXN] = {0,};  // 각 건물의 건설 시간
int indegree[MAXN] = {0,};  // 각 건물의 진입 차수
vector<edge> V[MAXN];  // 간선의 가중치(이전 건물 건설 시간), 다음 건물
int reachtime[MAXN] = {0,};  // 각 건물까지 도달하는 데 걸리는 시간

int topology(int w) {
    queue<int> q;

    // 초기 설정: 진입 차수가 0인 건물(노드)을 큐에 추가
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            reachtime[i] = 0;  // 진입 차수가 0인 건물은 바로 지어질 수 있으므로 0으로 초기화
        }
    }

    // 위상 정렬 시작
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto& p : V[cur]) {
            int next = p.second;
            int ntime = reachtime[cur] + btime[cur];  // 현재 건물의 완성 시간을 다음 건물의 도달 시간에 반영
            indegree[next]--;
            reachtime[next] = max(reachtime[next], ntime);  // 다음 건물의 도달 시간을 업데이트

            if (indegree[next] == 0) q.push(next);
        }
    }

    // 최종적으로 목표 건물이 지어지는 데 걸리는 총 시간은 reachtime[w] + btime[w]
    return reachtime[w] + btime[w];
}

void Solve() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &N, &K);

        // 각 테스트 케이스 초기화
        for (int j = 1; j <= N; j++) {
            scanf("%d", &btime[j]);
            V[j].clear();
            indegree[j] = 0;
            reachtime[j] = 0;
        }

        // 규칙 입력 및 그래프 구성
        for (int j = 0; j < K; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            V[x].push_back(make_pair(btime[x], y));
            indegree[y]++;
        }

        scanf("%d", &w);
        int ans = topology(w);
        printf("%d\n", ans);
    }
}

int main() {
    Solve();
    return 0;
}
