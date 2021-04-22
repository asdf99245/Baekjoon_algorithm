//나무 위의 빗물
//https://www.acmicpc.net/problem/17073

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

/*
첫번째 방법

vector<int> tree[500001];
bool visited[500001];
int cnt = 0;

void DFS(int curr) {
	visited[curr] = true;
	int i;

	bool leaf = true; // 만약 더이상 방문 할수 있는 노드가 없다면 리프노드임
	for (i = 0; i < tree[curr].size(); i++) {
		int next = tree[curr][i];
		if (!visited[next]) { 
			leaf = false;
			DFS(next);
		}
	}

	if (leaf) {
		cnt++;
	}
}

int main() {
	int n, i;
	double total;
	scanf("%d %lf", &n, &total);
	for (i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	DFS(1); // 트리의 끝 까지 탐색하면서 리프노드의 갯수를 찾는다

	printf("%lf", total/(double)cnt); // 결국 물이 리프노드에서 더이상 움직이지 않기때문에 물의양 / 총 리프노드 갯수가 답이됨
	return 0;
}

*/

//두번째 방법 

int edge[500001];
int cnt = 0;

int main() {
	double total;
	int n;
	scanf("%d %lf", &n, &total);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u] ++;
		edge[v] ++;
	}

	for (int i = 1; i <= n; i++) 
		if (edge[i] == 1) cnt++; // 엣지가 1개인 노드가 리프노드

	printf("%lf", total / cnt); // 리프노드에서 물이 멈추기때문에 물의양에 리프노드의 총갯수를 나눠준다
	return 0;
}