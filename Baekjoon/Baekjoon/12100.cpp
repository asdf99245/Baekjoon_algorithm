//2048 (Easy)
//https://www.acmicpc.net/problem/12100

#include <cstdio>
#include <algorithm>

int n;
int board[21][21];
int maxB = 0;

void playing(char dir, int (*bd)[21], int cnt){ //DFS ������� ����
	if (cnt == 5) // �ִ� 5������ ����
		return;

	int i,j;

	int cpy[21][21];

	//���� ���忡�� ������Ű�� ������ ���ο� �迭�� ���� �� ����
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cpy[i][j] = bd[i][j];
		}
	}

	//�����¿�� PUSH
	if (dir == 'U') { // ���� PUSH
		for (j = 0; j < n; j++) {
			int pb = 0, pbind = 0; //previous block , block index
			for (i = 0; i < n; i++) {
				if (cpy[i][j] != 0) { //����� ������ ��
					if (pb && cpy[i][j] == pb) { //���� ����� �ְ� ���� ��ϰ� ���� ���� ��
						//���� ��Ͽ� �����ְ� ��ģ ���� �ִ� ���� Ŭ �� ����
						cpy[pbind][j] = pb * 2;
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else { // ���� ����� ���ų� ���� ��ϰ� ���� ����� ���� ���� ���� ��
						//���� ����� ����������� ����
						pb = cpy[i][j];
						pbind = i;
					}
				}
			}
		}

		//�о�� �ϴ� ���� ������ ��� ��� �о���
		for (j = 0; j < n; j++) {
			int ind = 0; 
			for (i = 0; i < n; i++) {
				if (cpy[i][j]) {
					cpy[ind][j] = cpy[i][j];
					if (ind != i) // ���� �� ��� ����
						cpy[i][j] = 0;
					ind++;
				}
			}
		}

		playing('U', cpy, cnt + 1);
		playing('D', cpy, cnt + 1);
		playing('L', cpy, cnt + 1);
		playing('R', cpy, cnt + 1);
	}
	else if (dir == 'D') { // �Ʒ��� PUSH
		for (j = 0; j < n; j++) {
			int pb = 0, pbind = 0; //previous block , block index
			for (i = n - 1; i >= 0; i--) {
				if (cpy[i][j] != 0) { //����� ������ ��
					if (pb && cpy[i][j] == pb) { //���� ����� �ְ� ���� ��ϰ� ���� ���� ��
						//���� ��Ͽ� �����ְ� ��ģ ���� �ִ� ���� Ŭ �� ���� 
						cpy[pbind][j] = pb * 2; 
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else { // ���� ����� ���ų� ���� ��ϰ� ���� ����� ���� ���� ���� ��
						//���� ����� ����������� ����
						pb = cpy[i][j];
						pbind = i;
					}
				}
			}
		}

		//�о�� �ϴ� ���� ������ ��� ��� �о���
		for (j = 0; j < n; j++) {
			int ind = n - 1;
			for (i = n - 1; i >= 0; i--) {
				if (cpy[i][j]) {
					cpy[ind][j] = cpy[i][j];
					if (ind != i)
						cpy[i][j] = 0;
					ind--;
				}
			}
		}

		playing('U', cpy, cnt + 1);
		playing('D', cpy, cnt + 1);
		playing('L', cpy, cnt + 1);
		playing('R', cpy, cnt + 1);
	}
	else if (dir == 'L') { //�������� PUSH
		for (i = 0; i < n; i++) { //���� ����
			int pb = 0, pbind = 0;
			for (j = 0; j < n; j++) {
				if (cpy[i][j] != 0) {
					if (pb && cpy[i][j] == pb) {
						cpy[i][pbind] = pb * 2;
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else {
						pb = cpy[i][j];
						pbind = j;
					}
				}
			}
		}

		for (i = 0; i < n; i++) {
			int ind = 0;
			for (j = 0; j < n; j++) {
				if (cpy[i][j]) {
					cpy[i][ind] = cpy[i][j];
					if(ind != j)
						cpy[i][j] = 0;
					ind++;
				}
			}
		}

		playing('U', cpy, cnt + 1);
		playing('D', cpy, cnt + 1);
		playing('L', cpy, cnt + 1);
		playing('R', cpy, cnt + 1);
	}
	else { //���������� PUSH
		for (i = 0; i < n; i++) { //���� ����
			int pb = 0, pbind = 0;
			for (j = n - 1; j >= 0; j--) {
				if (cpy[i][j] != 0) {
					if (pb && cpy[i][j] == pb) {
						cpy[i][pbind] = pb * 2;
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else {
						pb = cpy[i][j];
						pbind = j;
					}
				}
			}
		}

		for (i = 0; i < n; i++) {
			int ind = n - 1;
			for (j = n - 1; j >= 0; j--) {
				if (cpy[i][j]) {
					cpy[i][ind] = cpy[i][j];
					if (ind != j)
						cpy[i][j] = 0;
					ind--;
				}
			}
		}

		playing('U', cpy, cnt + 1);
		playing('D', cpy, cnt + 1);
		playing('L', cpy, cnt + 1);
		playing('R', cpy, cnt + 1);
	}
}
int main() {
	int i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] > maxB) maxB = board[i][j]; //���忡�� ���� ū ��� ����
		}
	}

	//�����¿� 4 �������� PUSH
	playing('U', board, 0);
	playing('D', board, 0);
	playing('L', board, 0);
	playing('R', board, 0);

	printf("%d", maxB);
	return 0;
}