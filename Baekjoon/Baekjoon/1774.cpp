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
int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

bool Union(int a, int b) {
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
	for (i = 1; i <= n; i++) p[i] = i;

	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back({ x, y });
	}
	for (i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			edge.push_back({ getDist(i,j),{i + 1,j + 1} });
		}
	}
	sort(edge.begin(), edge.end());
	double result = 0;

	for (i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (Union(a, b)) result += edge[i].first;
	}

	printf("%.2lf", result);
	return 0;
}*/