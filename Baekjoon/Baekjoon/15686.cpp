//ġŲ ���
//https://www.acmicpc.net/problem/15686

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int city[51][51];
int minCityDist = 999999;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> sl;
bool check[13];

int minDistance() {
	int i,j,sum = 0;

	for (i = 0; i < house.size(); i++) { //���� �����κ��� ���尡��� ġŲ�� �Ÿ� ���
		int hy = house[i].first;
		int hx = house[i].second;
		int minDist = 999999;

		for (j = 0; j < M; j++) {
			int cy = sl[j].first;
			int cx = sl[j].second;
			int dist = abs(hy - cy) + abs(hx - cx);
			minDist = min(minDist, dist);
		}
		sum += minDist; //���� ġŲ�Ÿ� ���
	}

	return sum;
}
void DFS(int cnt,int ind) {
	if (cnt == M) { //ġŲ�� M�� ������
		minCityDist = min(minCityDist, minDistance());
		return;
	}

	for (int i = ind; i < chicken.size(); i++) {
		sl.push_back(chicken[i]); //ġŲ�� �����ؼ� ���Ϳ� ����
		DFS(cnt + 1,i + 1);
		sl.pop_back();
	}
}

int main() {
	scanf("%d %d", &N, &M);
	int i, j;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &city[i][j]);
			if (city[i][j] == 1)  // �� ��ġ ���Ϳ� ����
				house.push_back({ i,j });
			else if (city[i][j] == 2) //ġŲ�� ��ġ ���Ϳ� ����
				chicken.push_back({ i,j });
		}
	}

	DFS(0,0);

	printf("%d", minCityDist);
	return 0;
}