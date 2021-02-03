//Ʈ���� ����
//https://www.acmicpc.net/problem/1167

/*
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int vn;
bool visited[100001];
vector<pair<int,int>> vt[100001];
int maxL = -1;
int maxNode;

void DFS(int node, int dist) {
	int i;
	visited[node] = true;

	if (dist > maxL) { // �ִ� ���� ����
		maxL = dist;
		maxNode = node;
	}

	for (i = 0; i < vt[node].size(); i++) {
		int nextNode = vt[node][i].first;
		int cost = vt[node][i].second;
		if (!visited[nextNode]) { 
			DFS(nextNode, dist + cost); //���� ���� Ž��
			visited[nextNode] = false;
		}
	}
}

int main() {
	scanf("%d", &vn);
	int i;

	for (i = 0; i < vn; i++) {
		int n,v,dist;
		scanf("%d", &n);

		while(1) {
			scanf("%d", &v);
			if (v == -1)break;
			scanf("%d", &dist);
			vt[n].push_back({ v,dist }); //��� ����
		}
	}
	
	//ó���� ���������� 1�� �Ǵ� ��Ʈ�� ������带 �� ã�Ƽ� DFSŽ���� �Ͽ����� �ð��ʰ��� ��.
	//���Ŀ� ã�ƺ��� Ž�� 2������ �ذ� ������. ��Ʈ���� ���� �� ��带 ã�� �� ��, �� ��忡�� Ž���ϸ� ����
	
	DFS(1, 0); //��Ʈ���� ���� �� ��带 ã��
	visited[1] = false;
	DFS(maxNode, 0); // ��Ʈ���� ���� �� ������ ���� �� ��带 ã���� �ȴ�

	printf("%d", maxL);
	return 0;
}
*/