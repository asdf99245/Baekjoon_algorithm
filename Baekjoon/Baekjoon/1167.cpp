//트리의 지름
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

	if (dist > maxL) { // 최대 길이 갱신
		maxL = dist;
		maxNode = node;
	}

	for (i = 0; i < vt[node].size(); i++) {
		int nextNode = vt[node][i].first;
		int cost = vt[node][i].second;
		if (!visited[nextNode]) { 
			DFS(nextNode, dist + cost); //다음 노드로 탐색
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
			vt[n].push_back({ v,dist }); //노드 연결
		}
	}
	
	//처음엔 진입차수가 1이 되는 루트나 리프노드를 다 찾아서 DFS탐색을 하였으나 시간초과가 남.
	//이후에 찾아보니 탐색 2번으로 해결 가능함. 루트에서 가장 먼 노드를 찾고 난 뒤, 그 노드에서 탐색하면 가능
	
	DFS(1, 0); //루트에서 가장 먼 노드를 찾음
	visited[1] = false;
	DFS(maxNode, 0); // 루트에서 가장 먼 노드부터 가장 먼 노드를 찾으면 된다

	printf("%d", maxL);
	return 0;
}
*/