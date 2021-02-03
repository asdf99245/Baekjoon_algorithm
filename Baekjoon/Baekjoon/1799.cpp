//ºñ¼ó
//https://www.acmicpc.net/problem/1799
/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<pair<int, int>> v;
int board[11][11];
bool bishop[11][11];
int maxNum = 0;

void DFS(int n, int cnt) {
	if (n >= v.size()) {
		if (cnt > maxNum) maxNum = cnt;
		return;
	}
	int i;

	for (i = 0; i < n; i++) {
		if (bishop[v[i].first][v[i].second] && abs(v[n].first - v[i].first) == abs(v[n].second - v[i].second)) {
			if (cnt > maxNum) maxNum = cnt;
			return;
		}
	}

	bishop[v[n].first][v[n].second] = true;
	
	for (i = n + 1; i < v.size(); i++) {
		DFS(i, cnt + 1);
		bishop[v[i].first][v[i].second] = false;
	}
}
int main() {
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j]) v.push_back({ i,j });
		}
	}

	for (i = 0; i < v.size(); i++) {
		DFS(i, 0);
		bishop[v[i].first][v[i].second] = false;
	}

	printf("%d", maxNum);
	return 0;
}*/