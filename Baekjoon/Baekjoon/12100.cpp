//2048 (Easy)
//https://www.acmicpc.net/problem/12100

#include <cstdio>
#include <algorithm>

int n;
int board[21][21];
int maxB = 0;

void playing(char dir, int (*bd)[21], int cnt){ //DFS 방식으로 구현
	if (cnt == 5) // 최대 5번까지 가능
		return;

	int i,j;

	int cpy[21][21];

	//현재 보드에서 변형시키기 때문에 새로운 배열에 저장 후 변형
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cpy[i][j] = bd[i][j];
		}
	}

	//상하좌우로 PUSH
	if (dir == 'U') { // 위로 PUSH
		for (j = 0; j < n; j++) {
			int pb = 0, pbind = 0; //previous block , block index
			for (i = 0; i < n; i++) {
				if (cpy[i][j] != 0) { //블록이 존재할 시
					if (pb && cpy[i][j] == pb) { //이전 블록이 있고 현재 블록과 수가 같을 시
						//이전 블록에 합쳐주고 합친 값이 최댓값 보다 클 시 갱신
						cpy[pbind][j] = pb * 2;
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else { // 이전 블록이 없거나 이전 블록과 현재 블록의 수가 같지 않을 시
						//현재 블록을 이전블록으로 저장
						pb = cpy[i][j];
						pbind = i;
					}
				}
			}
		}

		//밀어야 하는 방향 끝으로 모든 블록 밀어줌
		for (j = 0; j < n; j++) {
			int ind = 0; 
			for (i = 0; i < n; i++) {
				if (cpy[i][j]) {
					cpy[ind][j] = cpy[i][j];
					if (ind != i) // 가장 앞 블록 제외
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
	else if (dir == 'D') { // 아래로 PUSH
		for (j = 0; j < n; j++) {
			int pb = 0, pbind = 0; //previous block , block index
			for (i = n - 1; i >= 0; i--) {
				if (cpy[i][j] != 0) { //블록이 존재할 시
					if (pb && cpy[i][j] == pb) { //이전 블록이 있고 현재 블록과 수가 같을 시
						//이전 블록에 합쳐주고 합친 값이 최댓값 보다 클 시 갱신 
						cpy[pbind][j] = pb * 2; 
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else { // 이전 블록이 없거나 이전 블록과 현재 블록의 수가 같지 않을 시
						//현재 블록을 이전블록으로 저장
						pb = cpy[i][j];
						pbind = i;
					}
				}
			}
		}

		//밀어야 하는 방향 끝으로 모든 블록 밀어줌
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
	else if (dir == 'L') { //왼쪽으로 PUSH
		for (i = 0; i < n; i++) { //위와 동일
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
	else { //오른쪽으로 PUSH
		for (i = 0; i < n; i++) { //위와 동일
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
			if (board[i][j] > maxB) maxB = board[i][j]; //보드에서 가장 큰 블록 저장
		}
	}

	//상하좌우 4 방향으로 PUSH
	playing('U', board, 0);
	playing('D', board, 0);
	playing('L', board, 0);
	playing('R', board, 0);

	printf("%d", maxB);
	return 0;
}