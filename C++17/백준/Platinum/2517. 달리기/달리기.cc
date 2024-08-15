#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000

int seg[4 * MAXN];  // 세그먼트 트리
vector<pair<int, int>> players; // {실력, 인덱스}
int N;

void update(int idx, int start, int end, int pos) {
    if (start == end) {
        seg[idx]++;
        return;
    }
    int mid = (start + end) / 2;
    if (pos <= mid) {
        update(2 * idx, start, mid, pos);
    } else {
        update(2 * idx + 1, mid + 1, end, pos);
    }
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

int query(int idx, int start, int end, int left, int right) {
    if (right < start || left > end) return 0;
    if (left <= start && end <= right) return seg[idx];
    int mid = (start + end) / 2;
    return query(2 * idx, start, mid, left, right) +
           query(2 * idx + 1, mid + 1, end, left, right);
}

int main() {
    memset(seg, 0, sizeof(seg));
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int skill;
        scanf("%d", &skill);
        players.push_back({skill, i});
    }

    // 실력 기준으로 좌표 압축
    vector<int> sorted_skills;
    for (int i = 0; i < N; i++) {
        sorted_skills.push_back(players[i].first);
    }
    sort(sorted_skills.begin(), sorted_skills.end());
    sorted_skills.erase(unique(sorted_skills.begin(), sorted_skills.end()), sorted_skills.end());

    for (int i = 0; i < N; i++) {
        players[i].first = lower_bound(sorted_skills.begin(), sorted_skills.end(), players[i].first) - sorted_skills.begin() + 1;
    }

    vector<int> result(N);

    // 앞에서부터 순차적으로 현재 선수보다 앞에 있는, 자신보다 실력이 좋은 선수들의 수를 세그먼트 트리로 계산
    for (int i = 0; i < N; i++) {
        int idx = players[i].first;
        result[players[i].second] = query(1, 1, N, idx + 1, N) + 1;
        update(1, 1, N, idx);
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
