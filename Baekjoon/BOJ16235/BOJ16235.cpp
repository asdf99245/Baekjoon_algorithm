// ���� ����ũ
// https://www.acmicpc.net/problem/16235

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
int fert[11][11];
int arr[11][11];
vector<int> tr[11][11];
int dy[] = { -1,1,-1,1,0,0,1,-1 };
int dx[] = { -1,1,1,-1,1,-1,0,0 };

void springSummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tr[i][j].size() == 0) continue;

			// ���� ������ �������� ����
			sort(tr[i][j].begin(), tr[i][j].end());
			vector<int> temp;
			int dead = 0;

			for (int k = 0; k < tr[i][j].size(); k++) {
				int age = tr[i][j][k];
				if (arr[i][j] < age) { // ����� ���ڶ�ٸ� �״´�
					dead += age / 2;
				}
				else { // ����� �ִٸ� ���̸�ŭ ��� �԰� ���� 1���� 
					arr[i][j] -= age;
					temp.push_back(age + 1);
				}
			}
			tr[i][j].clear(); 
			for (int k = 0; k < temp.size(); k++) tr[i][j].push_back(temp[k]); // ����� ���� ������ �ٽ� �ִ´�
			arr[i][j] += dead; // ���� �������� ����/2 ��ŭ ��� �߰�
		}
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tr[i][j].size() == 0) continue;

			for (int k = 0; k < tr[i][j].size(); k++) {
				int age = tr[i][j][k];
				if (age % 5 == 0) { // ���̰� 5�� ������ �ֺ��� ���� 1�� ���� �߰�
					for (int l = 0; l < 8; l++) {
						int ny = i + dx[l];
						int nx = j + dy[l];
						if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
							tr[ny][nx].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	// ���� ��� �߰�
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) arr[i][j] += fert[i][j];
}

void solve(int year) {
	if (year == K) return;
	springSummer();
	fall();
	winter();
	solve(year + 1);
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d",&fert[i][j]);
			arr[i][j] = 5;
		}
	}

	for (i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		tr[x][y].push_back(z); // {x,y}�� ���̰� z�� ���� �߰�
	}

	solve(0);

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt += tr[i][j].size();
		}
	}
	printf("%d", cnt);
}