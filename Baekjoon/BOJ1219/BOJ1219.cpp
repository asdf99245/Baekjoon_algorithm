//¿À¹Î½ÄÀÇ °í¹Î
//https://www.acmicpc.net/problem/1219

#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

vector<pair<int, int>> v[100];
int profit[100];
long long dist[100];

int main() {
	int N, start, to, M;
	scanf("%d %d %d %d", &N, &start, &to, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &profit[i]);
	}

	for (int i = 0; i < N; i++) dist[i] = 

	return 0;
}