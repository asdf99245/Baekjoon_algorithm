//최소 스패닝 트리
//https://www.acmicpc.net/problem/1197

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
int par[10001];
vector<pair<int, pair<int, int>>> edge;

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}
bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	else if (a > b) par[a] = b;
	else par[b] = a;

	return true;
}
int main() {
	int i;
	scanf("%d %d", &v, &e);
	for (i = 1; i <= v; i++) par[i] = i;
	for (i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a,&b,&c);
		edge.push_back({ c,{a,b} });
	}

	sort(edge.begin(), edge.end());

	long long sum = 0;
	for (i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (Union(a, b)) sum += edge[i].first;
	}

	printf("%lld", sum);
	return 0;
}