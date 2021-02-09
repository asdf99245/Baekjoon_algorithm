//���� ����ö 2ȣ��
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
bool circle[3001]; // ��ȯ������ üũ
int par[3001];
vector<int> v[3001];

int find(int x) { //union-find�� find�Լ�
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

bool merge(int u, int v) {//union-find�� union�Լ�
	u = find(u);
	v = find(v);
	if (u == v) return false;
	else if (u < v) par[v] = u;
	else par[u] = v;
	return true;
}

int DFS(int startNode, int cur, int len) { //��ȯ�� ���� ã�Ƽ� üũ
	if (startNode == cur && len > 2) {  //���ۿ����� ���ƿ��鼭 �ּ� ���ۿ����� 2���� ���� ������ ��쿡��
		return 1; 
		visited[cur] = true; 
	}
	else if (startNode == cur && len == 2) return 0; // ���ۿ����� ������ �������� ���ٰ� �ٷ� ���ƿ��� ���� ��ȯ���� �ƴ�
	else if(cur!= startNode) //���ۿ����� ���ƿ��� ���� ���ۿ� �����ϰ� �湮 ǥ��
		visited[cur] = true;

	for (int i = 0; i < v[cur].size(); i++) {
		int nv = v[cur][i];
		if (!visited[nv]) {
			int res = DFS(startNode, nv, len + 1);
			if (res == 1) { //���ۿ����� ���ƿ����� ������ ������ ���ư��鼭 ��ȯ�� üũ
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
	q.push({ node,0}); // second �� depth

	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop();
		if (circle[x] == true) return d; //��ȯ���� ��� �Ÿ� ��ȯ

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
		if (!merge(s1, s2)) { //����Ŭ�� �߻��Ͽ����� ��ȯ�� ����
			startNode = s1;
		}
	}

	DFS(startNode, startNode, 0);
	for (i = 1; i <= n; i++) { //�� ������ ��ȯ������ �Ÿ� ���ϱ�
		if (circle[i] == true) printf("0 ");
		else {
			memset(visited, false, sizeof(visited));
			printf("%d ", BFS(i));
		}
	}
	return 0;
}*/