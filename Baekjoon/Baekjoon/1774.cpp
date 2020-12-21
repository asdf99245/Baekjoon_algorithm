//우주신과의 교감
//https://www.acmicpc.net/problem/1774

/*#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
vector<pair<int, int>> v;
vector<pair<double, pair<int, int>>> edge;
int p[1001];

double getDist(int a, int b) {
	return sqrt(pow(v[a].first - v[b].first, 2) + pow(v[a].second - v[b].second, 2));
}
int find(int x) { //유니온 파인드 이용** 노드 x의 루트 노드 찾음
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

bool Union(int a, int b) { // 노드 a b 합침
	a = find(a);
	b = find(b);

	if (a == b) return false;
	else if (a > b) p[a] = b;
	else p[b] = a;

	return true;
}

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) p[i] = i; //  i 노드의 부모노드

	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back({ x, y }); // 우주신의 좌표
	}
	for (i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b); 
		Union(a, b); // 이미 연결된 노드
	}
	
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			edge.push_back({ getDist(i,j),{i + 1,j + 1} }); // 우주신 사이 거리 계산
		}
	}
	sort(edge.begin(), edge.end()); // 거리로 오름차순 정렬
	double result = 0;

	for (i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (Union(a, b)) result += edge[i].first; // 사이클 발생하지 않으면 엣지 추가
	}

	printf("%.2lf", result);
	return 0;
}*/