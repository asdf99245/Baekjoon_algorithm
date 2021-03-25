//��ŸƮ�� ��ũ
//https://www.acmicpc.net/problem/14889

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
int stats[20][20];
int members[20]; // 0 => ��ŸƮ�� 1 => ��ũ��
int minScore = 987654321;

int getScore(int which) {
	vector<int> v; 
	// �� ����
	for (int i = 0; i < n; i++) {
		if(members[i] == which) 
			v.push_back(i);
	}

	int score = 0;

	// ��� ���� ���ؼ� �ɷ�ġ�� �����ش�
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			score += stats[v[i]][v[j]] + stats[v[j]][v[i]];
		}
	}

	return score;
}
int getDiff() { // �ɷ�ġ ���� ���
	return abs(getScore(0) - getScore(1));
}

void DFS(int index, int cnt) {
	if (cnt == n / 2) { // �������� �����ٸ�
		minScore = min(minScore,getDiff());
		return;
	}

	// n/2���� ��ũ������ �����Ѵ�
	for (int i = index; i < n; i++) {
		members[i] = 1;
		DFS(i + 1, cnt + 1);
		members[i] = 0;
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &stats[i][j]);
		}
	}

	DFS(0, 0);
	printf("%d", minScore);
	return 0;
}