//Mootube(Silver)
//https://www.acmicpc.net/problem/15591

/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

int N, Q;
typedef long long ll;
vector<pair<int,ll>> v[5001];
bool visited[5001];

int BFS(int start, ll k) {
	queue<pair<int,ll>> q;
	visited[start] = true;
	q.push({ start,0 });
	int cnt = 0;
	
	while (!q.empty()) {
		int cur = q.front().first;
		ll usaCur = q.front().second;
		q.pop();

		if (usaCur >= k) cnt++; //현재 동영상까지의 우사도가 k보다 크다면 추천동영상

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			ll usaToNext = v[cur][i].second;
			if (!visited[next]) {
				if (usaCur == 0) //첫 동영상과 다음 동영상 사이의 우사도는 항상 다음 동영상 까지의 우사도
					q.push({ next,usaToNext });
				else 
					q.push({ next,min(usaToNext,usaCur) }); //지금까지의 우사도보다 더 작은 우사도라면 작은 우사도로 갱신
				visited[next] = true;
			}
		}
	}

	return cnt;
}
int main() {
	int i,j;
	scanf("%d %d", &N, &Q);
	for (i = 0; i < N - 1; i++) {
		int p, q;
		ll r;
		scanf("%d %d %lld", &p, &q, &r); //두 쌍의 우사도 저장
		v[p].push_back({ q,r });
		v[q].push_back({ p,r });
	}
	for (i = 0; i < Q; i++) {
		ll k;
		int v;
		scanf("%lld %d", &k, &v);
		memset(visited, false, sizeof(visited));
		printf("%d\n", BFS(v, k));
	}
	return 0;
}*/