// Z
//https://www.acmicpc.net/problem/1074

#include <cstdio>
#include <cmath>
using namespace std;

int cnt = -1;
// Z��� ���� 
int dy[] = { 0,0,1,0 };
int dx[] = { 0,1,-1,1 };
void DFS(int y, int x, int r, int c, int n) {
	int l = pow(2, n); //�迭 ����
	if (r > y + l || c > x + l) { // ã�� �ε����� �����ȿ� ���ٸ� ���� ũ�⸸ŭ ī��Ʈ�� ������
		cnt += l * l;
		return;
	}
	if (y > r && x > c) return; // ã�� �ε����� ���� ���������� �����̸� ã�� �ʿ� ����
	if (n == 1) { // �迭 ���̰� 2 �Ͻ� Z ������� Ž���ϸ鼭 ī��Ʈ�� �÷���
		for (int i = 0; i < 4; i++) {
			++cnt;
			y += dy[i];
			x += dx[i];
			if (y == r && x == c) { // �߽߰� ���
				printf("%d", cnt);
				return;
			}
		}
		return;
	}

	// �� �������� ��������
	DFS(y, x, r, c, n - 1);  
	DFS(y, x + l / 2, r, c, n - 1);
	DFS(y + l / 2, x, r, c, n - 1);
	DFS(y + l / 2, x + l / 2, r, c, n - 1);
}
int main() {
	int n, c, r;
	scanf("%d %d %d", &n, &r, &c);
	
	DFS(0, 0, r, c, n);
	return 0;
}