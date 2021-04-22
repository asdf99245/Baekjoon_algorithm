//Strongly Connected Component
//https://www.acmicpc.net/problem/2150

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> graph[10001];
vector<int> rGraph[10001];
stack<int> st;
int visited[10001];
vector<int> scc[10001];

void DFS(int curr) { 
	visited[curr] = true;
	int i;

	for (i = 0; i < graph[curr].size(); i++) {
		int next = graph[curr][i];
		if (!visited[next]) {
			DFS(next);
		}
	}

	st.push(curr); // ��带 ������� �����ϱ� ����
}

void reverse_DFS(int curr,int cnt) {
	visited[curr] = true;
	int i;
	scc[cnt].push_back(curr);

	for (i = 0; i < rGraph[curr].size(); i++) {
		int next = rGraph[curr][i];
		if (!visited[next]) {
			reverse_DFS(next,cnt);
		}
	}
}

int main() {
	int V, E, i;
	scanf("%d %d", &V, &E);
	for (i = 0; i < E; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		graph[A].push_back(B);
		rGraph[B].push_back(A); //�ڻ���� �˰����� ���� ������ �׷����� ����
	}

	for (i = 1; i <= V; i++) {
		if(!visited[i])
			DFS(i);
	}
	memset(visited, false, sizeof(visited));

	int cnt = 0;
	vector<pair<int, int>> v; //scc�� ù��°���ҿ� ���� �����ϱ� ���� ���
	while (!st.empty()) { // ó�� DFS���� �湮�ߴ� ���ҵ��� ������ �������� DFS
		int ver = st.top();
		st.pop();
		if (!visited[ver]) { 
			reverse_DFS(ver,cnt);
			sort(scc[cnt].begin(), scc[cnt].end()); // scc �������� ����
			v.push_back({ scc[cnt][0],cnt });
			cnt++; // �ѹ��� DFS�� scc�Ѱ�
		}
	}

	sort(v.begin(), v.end()); // ù��° ������ ũ��� ����
	printf("%d\n", cnt);
	for (i = 0; i < v.size(); i++) {
		int index = v[i].second;
		for (int j = 0; j < scc[index].size(); j++) {
			printf("%d ", scc[index][j]);
		}
		printf("-1\n");
	}
	return 0;
}