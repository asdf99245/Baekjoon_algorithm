//서울 지하철 2호선
//https://www.acmicpc.net/problem/16947

/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int n;
bool visited[3001];
bool circle[3001]; // 순환역인지 체크
int par[3001];
vector<int> v[3001];

int find(int x) { //union-find의 find함수
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

bool merge(int u, int v) {//union-find의 union함수
	u = find(u);
	v = find(v);
	if (u == v) return false;
	else if (u < v) par[v] = u;
	else par[u] = v;
	return true;
}

int DFS(int startNode, int cur, int len) { //순환역 전부 찾아서 체크
	if (startNode == cur && len > 2) {  //시작역으로 돌아오면서 최소 시작역제외 2개의 역을 지나온 경우에만
		return 1; 
		visited[cur] = true; 
	}
	else if (startNode == cur && len == 2) return 0; // 시작역으로 왔지만 다음역에 갔다가 바로 돌아오는 경우는 순환역이 아님
	else if(cur!= startNode) //시작역으로 돌아오기 위해 시작역 제외하고 방문 표시
		visited[cur] = true;

	for (int i = 0; i < v[cur].size(); i++) {
		int nv = v[cur][i];
		if (!visited[nv]) {
			int res = DFS(startNode, nv, len + 1);
			if (res == 1) { //시작역으로 돌아왔을시 지나온 역으로 돌아가면서 순환역 체크
				circle[cur] = true;
				return 1;
			}
		}
	}

	return 0;
}

int BFS(int node) {
	queue<pair<int,int>> q;
	visited[node] = true;
	q.push({ node,0}); // second 는 depth

	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop();
		if (circle[x] == true) return d; //순환역일 경우 거리 반환

		for (int i = 0; i < v[x].size(); i++) {
			if (!visited[v[x][i]]) {
				visited[v[x][i]] = true;
				q.push({ v[x][i],d + 1 });
			}
		}
	}
}
int main() {

	scanf("%d", &n);
	int i, startNode = 0;
	for (i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (i = 0; i < n; i++) {
		int s1, s2;
			scanf("%d %d", &s1, &s2);
		v[s1].push_back(s2);
		v[s2].push_back(s1);
		if (!merge(s1, s2)) { //사이클이 발생하였을때 순환역 저장
			startNode = s1;
		}
	}

	DFS(startNode, startNode, 0);
	for (i = 1; i <= n; i++) { //각 역에서 순환역까지 거리 구하기
		if (circle[i] == true) printf("0 ");
		else {
			memset(visited, false, sizeof(visited));
			printf("%d ", BFS(i));
		}
	}
	return 0;
}*/