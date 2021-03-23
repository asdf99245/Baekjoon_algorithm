//���� ��Ÿ
//https://www.acmicpc.net/problem/3967

#include <iostream>
#include <vector>
using namespace std;

char map[5][9];
vector<pair<int, int>> v;
bool used[12];

bool check() { // 6�� ��� ���� 26�� �Ǵ��� Ȯ��
	if ((map[0][4] - 64) + (map[1][3] - 64) + (map[2][2] - 64) + (map[3][1] - 64) != 26) return false;
	if ((map[0][4] - 64) + (map[1][5] - 64) + (map[2][6] - 64) + (map[3][7] - 64) != 26) return false;
	if ((map[4][4] - 64) + (map[3][3] - 64) + (map[2][2] - 64) + (map[1][1] - 64) != 26) return false;
	if ((map[4][4] - 64) + (map[3][5] - 64) + (map[2][6] - 64) + (map[1][7] - 64) != 26) return false;
	if ((map[1][1] - 64) + (map[1][3] - 64) + (map[1][5] - 64) + (map[1][7] - 64) != 26) return false;
	if ((map[3][1] - 64) + (map[3][3] - 64) + (map[3][5] - 64) + (map[3][7] - 64) != 26) return false;

	return true;
}

void DFS(int index) {
	if (index == v.size()) { // ��ĭ�� �� ä�����ÿ�
		if (check()) { // ���� ��Ÿ�� �Ǵ��� Ȯ���Ѵ�
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					cout << map[i][j];
				}
				cout << '\n';
			}
			exit(0); // �ϳ� �߰��ϸ� �ٷ� ���� 
		}

		return;
	}
	int y = v[index].first;
	int x = v[index].second;

	for (int i = 0; i < 12; i++) { // ���� ���ĺ����� ������� �ʾҴٸ� �־��
		if (!used[i]) {
			map[y][x] = i + 'A';
			used[i] = true;
			DFS(index + 1);
			map[y][x] = 'x';
			used[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'x') // ��ĭ ��ǥ ����
				v.push_back({ i,j });
			else if (map[i][j] != '.') { 
				used[map[i][j] - 65] = true; // ���ĺ� ��뿩�� �ƽ�Ű�ڵ� �� �̿�
			}
		}
	}

	DFS(0);
	return 0;
}